
#include <bits/stdc++.h>

template<typename T>
class BlockChain : public std::vector<T>
{
    using riterator =  typename std::vector<T>::reverse_iterator; 
    using iterator =  typename std::vector<T>::iterator; 

    // iterator begin() = delete;
    // riterator rend() = delete;

    public:
    BlockChain(std::initializer_list<T> args) : std::vector<T>(args){};

};