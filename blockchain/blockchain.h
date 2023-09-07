
#pragma once

#include <bits/stdc++.h>
#include "../block/block.h"

// template<typename T>
class BlockChain_t : public std::unordered_map<std::size_t, Block>
{
    using iterator =  typename std::unordered_map<std::size_t, Block>::iterator; 
    using citerator =  typename std::unordered_map<std::size_t, Block>::const_iterator; 

    private:
        iterator begin();
        Block LatestBlock;

    public:
    Block latest_block_get(void) const; 
    Block nth_block_get(uint32_t index) const; // 0 means latest block
    Block previous_block_get(Block CurrentBlock) const;
    void print_blocks(void);
    int first_invalid_block_id_get(void) const;
    void block_add(Block BlockToAdd);
    BlockChain_t(Block FirstBlock);
    
    static constexpr int FIRST_BLOCK_PREVIOUS_HASH = -1;
    static constexpr int NO_INVALID_BLOCKS = -1;

    friend void blockchain_block_modify(BlockChain_t& BlockChain);
};