
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

#include <bits/stdc++.h>

#include "./block/block.h"
#include "./options/handlers.h"

int main(void)
{

    std::vector<std::string> Words;

    std::vector<std::pair<std::string, std::function<void(std::vector<std::string>&)>>> Options = {
        { "data", print_data_handler },
        { "word", new_data_add_handler }
    };

    while(1)
    {
        fmt::print("\nYour option: ");

        std::string option_selected;
        std::cin >> option_selected;

        
        for(auto option : Options)
        {
            if(option_selected == option.first)
            {
                option.second(Words);
                goto end; 
            }
        }

        fmt::print(fg(fmt::color::red), "no such option\n");

        end:
        continue;
    }

}