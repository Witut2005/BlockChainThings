

#pragma once

template <typename R, typename A>
class BaseOptionHandler_t 
{
    
    private:
    R(*function)(A);

    public:
    BaseOptionHandler_t(R(*function)(A));
    void operator ()(A arg);
};

template <typename R, typename A>
BaseOptionHandler_t<R, A>::BaseOptionHandler_t(R(*function)(A))
{
    this->function = function;
}

template <typename R, typename A>
void BaseOptionHandler_t<R, A>::operator()(A arg)
{
    this->function(arg);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
