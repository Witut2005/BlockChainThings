
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

#include <bits/stdc++.h>

#include "./block/block.h"
#include "./blockchain/blockchain.h"

#include "./options/data/handler.h"
#include "./options/blockchain/handler.h"
#include "./options/base_handler/base_option_handler.h"

int main(void)
{

    std::vector<std::string> Data;

    std::vector<std::pair<std::string, BaseOptionHandler_t<void, std::vector<std::string>&>>> DataOptions = {
        { "data", BaseOptionHandler_t(handlers::print_data) },
        { "word", BaseOptionHandler_t(handlers::new_data_add) }
    };

    std::vector<std::pair<std::string, BaseOptionHandler_t<void, BlockChain_t&>>> BlockChainOptions = {
        { "add", BaseOptionHandler_t(handlers::new_block_add) },
        {"modify", BaseOptionHandler_t(handlers::blockchain_block_modify) },
        {"print_blocks", BaseOptionHandler_t(handlers::blockchain_blocks_print) }
    }; 

    BlockChain_t BlockChain = {
        {0, "fromini", 0, 0}
    };

    // fmt::print("fro: {}", BlockChain.begin()->block_hash_get());

    handlers::print_all_available_options(DataOptions, BlockChainOptions);

    while(1)
    {
        fmt::print("\nYour option: ");
        std::string option_selected;

        std::getline(std::cin, option_selected);

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

        fmt::print(fg(fmt::color::red), "no such option: {}\n", option_selected);

        end:
        continue;
    }

}