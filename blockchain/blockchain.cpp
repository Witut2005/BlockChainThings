
#include "./blockchain.h"
#include "../block/block.h"

Block BlockChain_t::latest_block_get(void) const
{
    // BlockChain_t::citerator ret;
    // for(auto it = this->cbegin(); it != this->cend(); it++) { ret = it; }
    // return ret->second;
    return this->LatestBlock;
}

Block BlockChain_t::nth_block_get(uint32_t index) const
{
    if(index >= this->size())
        throw std::invalid_argument("ERROR: block index out of range");

    auto Block = this->latest_block_get();

    for(int i = 0; i < index; i++)
        Block = this->find(Block.previous_block_hash_get())->second;

    return Block;
}

Block BlockChain_t::previous_block_get(Block CurrentBlock) const
{
    return this->find(CurrentBlock.previous_block_hash_get())->second;
}

void BlockChain_t::print_blocks(void) 
{
    auto CurrentBlock = this->latest_block_get();

    while(1)
    {
        fmt::print("Block: {} {} {} {} {}\n", CurrentBlock.block_hash_get(), CurrentBlock.previous_block_hash_get(), CurrentBlock.nonce_get(), CurrentBlock.logic_puzzle_level_get(), CurrentBlock.data_get());

        if(auto PreviousBlock = this->find(CurrentBlock.previous_block_hash_get()); PreviousBlock != this->end())
            CurrentBlock = PreviousBlock->second;
        else
            break;
    }
}

int BlockChain_t::first_invalid_block_id_get(void) const
{
    int id = -1;

    auto CurrentBlock = this->latest_block_get();

    while(1)
    {
        id++;
        if(!CurrentBlock.is_valid())
            return id;

        if(!CurrentBlock.previous_block_hash_get())
            break;

        CurrentBlock = this->find(CurrentBlock.previous_block_hash_get())->second;
    }
    return BlockChain_t::NO_INVALID_BLOCKS;
}

BlockChain_t::BlockChain_t(Block FirstBlock) : LatestBlock(FirstBlock)
{
    this->insert(std::make_pair(FirstBlock.block_hash_get(), FirstBlock));
}

void BlockChain_t::block_add(Block BlockToAdd)
{
    this->LatestBlock = BlockToAdd;
    this->insert(std::make_pair(BlockToAdd.block_hash_get(), BlockToAdd));
}