
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