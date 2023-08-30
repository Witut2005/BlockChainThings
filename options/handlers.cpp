
#include "./handlers.h"

void new_data_add_handler(std::vector<std::string>& Data)
{
    fmt::print("words (type quit to exit): ");
    std::string input;

    uint32_t count = 1;

    fmt::print("\n{}. ", count++);
    while((std::cin >> input) && (input != "quit"))
    {
        fmt::print("\n{}. ", count++);
        Data.push_back(input);
    }
}

void print_data_handler(const std::vector<std::string>& Data)
{
    fmt::print("\ndata: {}\n", Data);
}

void new_block_add(std::vector<Block> BlockChain)
{

    std::string data;
    uint32_t logic_puzzle_level;

    fmt::print("Block data: ");
    std::cin >> data;
    
    fmt::print("Logic puzzle level: ");
    std::cin >> logic_puzzle_level;

    uint32_t nonce;

    BlockChain.push_back(Block(BlockChain.rend()->block_hash_get(), data, logic_puzzle_level, nonce));
}


