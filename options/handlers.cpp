
#include "./handlers.h"

void new_data_add_handler(std::vector<std::string>& Vec)
{
    fmt::print("words (type quit to exit): ");
    std::string input;

    uint32_t count = 1;

    fmt::print("\n{}. ", count++);
    while((std::cin >> input) && (input != "quit"))
    {
        fmt::print("\n{}. ", count++);
        Vec.push_back(input);
    }
}

void print_data_handler(const std::vector<std::string>& Vec)
{
    fmt::print("\ndata: {}\n", Vec);
}