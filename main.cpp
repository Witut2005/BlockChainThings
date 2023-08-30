
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

#include <bits/stdc++.h>

#include "./block/block.h"
#include "./options/handlers.h"

int main(void)
{

    std::vector<std::string> Data;

    std::vector<std::pair<std::string, std::function<void(std::vector<std::string>&)>>> DataOptions = {
        { "data", print_data_handler },
        { "word", new_data_add_handler }
    }; 

    std::vector<std::pair<std::string, std::function<void(std::vector<Block>&)>>> BlockChainOptions = {
        { "add", new_block_add},
    }; 

    std::vector<Block> BlockChain = {
        {0, "fromini", 0, 0}
    };


    print_all_available_options(DataOptions, BlockChainOptions);


    while(1)
    {
        fmt::print("\nYour option: ");

        std::string option_selected;
        std::cin >> option_selected;

        
        for(auto option : DataOptions)
        {
            if(option_selected == option.first)
            {
                option.second(Data);
                goto end; 
            }
        }

        for(auto option : BlockChainOptions)
        {
            if(option_selected == option.first)
            {
                option.second(BlockChain);
                goto end; 
            }
        }

        fmt::print(fg(fmt::color::red), "no such option\n");

        end:
        continue;
    }

}