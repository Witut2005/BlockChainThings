
#include <bits/stdc++.h>
#include "../block/block.h"

// template<typename T>
class BlockChain : public std::vector<Block>
{
    using riterator =  typename std::vector<Block>::reverse_iterator; 
    using iterator =  typename std::vector<Block>::iterator; 

    iterator begin() = delete;
    riterator rend() = delete;

    public:
    void print_blocks(void);
    BlockChain(std::initializer_list<Block> args) : std::vector<Block>(args){};

};