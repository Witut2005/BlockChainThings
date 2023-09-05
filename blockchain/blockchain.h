
#pragma once

#include <bits/stdc++.h>
#include "../block/block.h"

// template<typename T>
class BlockChain_t : public std::vector<Block>
{
    using riterator =  typename std::vector<Block>::reverse_iterator; 
    using iterator =  typename std::vector<Block>::iterator; 

    iterator begin() = delete;
    riterator rend() = delete;

    public:
    void print_blocks(void);
    int first_invalid_block_id_get(void) const;
    BlockChain_t(std::initializer_list<Block> args) : std::vector<Block>(args){};
    
    static constexpr int NO_INVALID_BLOCKS = -1;
    friend void blockchain_block_modify(BlockChain_t& BlockChain);

};