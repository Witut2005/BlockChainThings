
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

void new_block_add(std::vector<Block>& BlockChain)
{

    std::string data;
    uint32_t logic_puzzle_level = 0;

    fmt::print("Block data: ");
    std::getline(std::cin, data);
    
    fmt::print("Logic puzzle level: ");
        
    while(!(std::cin >> logic_puzzle_level))
    {
        fmt::print(fg(fmt::color::red), "invalid input\n");
        fmt::print("Logic puzzle level: ");

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::random_device RandomDevice;
    std::mt19937 Twister(RandomDevice());

    std::uniform_int_distribution<uint32_t> Distribution(0, UINT32_MAX);

    uint32_t nonce = Distribution(Twister);

    
    while(1)
    {
        Block BlockToAdd(BlockChain.rbegin()->block_hash_get(), data, logic_puzzle_level, nonce);
        
        if(Block::check_logic_puzzle_level_correctness(BlockToAdd.block_hash_get(), logic_puzzle_level))
        {
            std::cout << "Block hash: " << std::bitset<sizeof(std::size_t) * 8>(BlockToAdd.block_hash_get()) << std::endl;
            break;
        }
        nonce = Distribution(Twister);
    }

    BlockChain.push_back(Block(BlockChain.rbegin()->block_hash_get(), data, logic_puzzle_level, nonce));
    fmt::print(fg(fmt::color::green), "Block added\n");
    
}


void blockchain_blocks_print(BlockChain_t& BlockChain)
{
    auto CurrentBlock = BlockChain.rbegin();

    fmt::print("\n");
    int data_length = 0;

    while(1)
    {
        // data_length = CurrentBlock->data_get().length() > 40 ? CurrentBlock->data_get().length() : 40;
        data_length = data_length > (std::string("data: ") + CurrentBlock->data_get()).length() ? 
            data_length : ((std::string("data: ") + CurrentBlock->data_get()).length() > 40) ? (std::string("data: ") + CurrentBlock->data_get()).length()  : 40;

        bool is_valid = CurrentBlock->is_valid();

        for(int i = 0; i < data_length + 2; i++)
            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red), "-");
        fmt::print("\n");

        /////////////////////////BLOCK HASH///////////////////////////////

        {
            std::stringstream ss;
            ss << std::string("block hash: ") << "0x" << std::hex << CurrentBlock->block_hash_get();
            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red),"|");
            fmt::print("{}", ss.str());

            for(int i = 0; i < int(data_length - ss.str().length()); i++) // UNOPTIMIZED
                fmt::print(" ");

            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red), "|\n");
        }

        /////////////////////PREVIOUS BLOCK HASH//////////////////////////
        {
            std::stringstream ss;
            ss << std::string("previous block hash: ") << "0x" << std::hex << CurrentBlock->previous_block_hash_get();
            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red),"|");
            fmt::print("{}", ss.str()); 

            for(int i = 0; i < int(data_length - ss.str().length()); i++) // UNOPTIMIZED
                fmt::print(" ");

            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red), "|\n");
        }

        /////////////////////////////NONCE///////////////////////////////
        {
            std::stringstream ss;
            ss << std::string("nonce: ") << "0x" <<  std::hex << CurrentBlock->nonce_get();
            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red),"|");
            fmt::print("{}", ss.str()); 

            for(int i = 0; i < int(data_length - ss.str().length()); i++) // UNOPTIMIZED
                fmt::print(" ");

            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red), "|\n");
        }

        ///////////////////////LOGIC PUZZLE LEVEL////////////////////////
        {
            std::stringstream ss;
            ss << std::string("logic puzzle level: ") << std::dec << CurrentBlock->logic_puzzle_level_get();
            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red),"|");
            fmt::print("{}", ss.str()); 

            for(int i = 0; i < int(data_length - ss.str().length()); i++) // UNOPTIMIZED
                fmt::print(" ");

            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red), "|\n");
        }

        //////////////////////////////DATA///////////////////////////////

        {
            std::stringstream ss;
            ss << std::string("data: ") << CurrentBlock->data_get();
            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red),"|");
            fmt::print("{}", ss.str()); 

            for(int i = 0; i < int(data_length - ss.str().length()); i++) // UNOPTIMIZED
                fmt::print(" ");

            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red), "|\n");
        }

        ////////////////////////////////////////////////////////////////

        for(int i = 0; i < data_length + 2; i++)
            fmt::print(is_valid ? fg(fmt::color::green) : fg(fmt::color::red),"-");
        fmt::print("\n");


        // fmt::print("Block: {:X} {:X} {:X} {:X} {}\n----------------------------\n", CurrentBlock->block_hash_get(), CurrentBlock->previous_block_hash_get(), CurrentBlock->nonce_get(), CurrentBlock->logic_puzzle_level_get(), CurrentBlock->data_get());

        if(!CurrentBlock->previous_block_hash_get())
            break;

        const char* arrow = "^|||||";

        for(int i = 0; i < sizeof(arrow) - 2; i++)
        {
            for(int i = 0; i < data_length / 2; i++)
                fmt::print(" ");

            fmt::print("{}", arrow[i]);

            for(int i = 0; i < data_length / 2; i++)
                fmt::print(" ");

            fmt::print("\n");
        }

        CurrentBlock++;
    }
}