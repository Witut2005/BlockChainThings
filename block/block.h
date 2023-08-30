#include <iostream>

class Block{
    private:
        std::string data; 
        std::size_t PreviousBlockHash;
        std::size_t BlockHash;
        uint32_t logic_puzzle_level;
        uint32_t nonce;
    
    public:

    auto data_get(void) -> decltype(this->data);
    auto previous_block_hash_get(void) -> decltype(this->PreviousBlockHash);
    auto block_hash_get(void) -> decltype(this->BlockHash);

};