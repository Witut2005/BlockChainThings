

#include "./handler.h"

namespace handlers 
{

    void new_data_add(std::vector<std::string>& Data)
    {
        fmt::print("words (type quit to exit): ");
        std::string input;

        uint32_t count = 1;

        fmt::print("\n{}. ", count++);
        while(std::getline(std::cin, input) && (input != "quit"))
        {
            fmt::print("\n{}. ", count++);
            Data.push_back(input);
        }
    }

    void print_data(std::vector<std::string>& Data)
    {
        fmt::print("\ndata: {}\n", Data);
    }

}