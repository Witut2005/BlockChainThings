
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

    std::random_device RandomDevice;
    std::mt19937 Twister(RandomDevice());

    std::uniform_int_distribution<uint32_t> Distribution(0, UINT32_MAX);

    uint32_t nonce = Distribution(Twister);

    
    while(1)
    {
        Block BlockToAdd((BlockChain.end() - 1)->block_hash_get(), data, logic_puzzle_level, nonce);
        
        if(Block::check_logic_puzzle_level_correctness(BlockToAdd.block_hash_get(), logic_puzzle_level))
        {
            std::cout << "Block hash: " << std::bitset<sizeof(std::size_t) * 8>(BlockToAdd.block_hash_get()) << std::endl;
            break;
        }
        
        
        nonce = Distribution(Twister);
    }


    BlockChain.push_back(Block(BlockChain.rend()->block_hash_get(), data, logic_puzzle_level, nonce));
    fmt::print(fg(fmt::color::green), "Block added\n");
}


