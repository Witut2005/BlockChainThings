
#include "./block.h"

auto Block::data_get(void) -> decltype(this->data)
{
    return this->data; 
}

auto Block::previous_block_hash_get(void) -> decltype(this->PreviousBlockHash)
{
    return this->PreviousBlockHash;
}

auto Block::block_hash_get(void) -> decltype(this->BlockHash)
{
    return this->BlockHash;
}
