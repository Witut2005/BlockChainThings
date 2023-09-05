
#include "./blockchain.h"
#include "../block/block.h"

void BlockChain_t::print_blocks(void) 
{
    auto CurrentBlock = this->rbegin();

    while(CurrentBlock->block_hash_get())
    {
        fmt::print("Block: {} {} {} {} {}\n", CurrentBlock->block_hash_get(), CurrentBlock->previous_block_hash_get(), CurrentBlock->nonce_get(), CurrentBlock->logic_puzzle_level_get(), CurrentBlock->data_get());
        CurrentBlock++;
    }
    
    fmt::print("Block: {} {} {} {} {}\n", CurrentBlock->block_hash_get(), CurrentBlock->previous_block_hash_get(), CurrentBlock->nonce_get(), CurrentBlock->logic_puzzle_level_get(), CurrentBlock->data_get());

}

int BlockChain_t::first_invalid_block_id_get(void) const
{
    int id = -1;

    auto CurrentBlock = this->rbegin();

    while(1)
    {
        id++;
        if(!CurrentBlock->is_valid())
            return id;

        if(!CurrentBlock->previous_block_hash_get())
            break;

        CurrentBlock++;
    }
    return BlockChain_t::NO_INVALID_BLOCKS;
}