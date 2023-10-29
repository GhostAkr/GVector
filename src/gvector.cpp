#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include "../inc/gvector.hpp"

GVector::GVector()
    : _val(nullptr)
    , _size(0)
{}

GVector::GVector(std::size_t size)
    : _val(new int[size])
    , _size(size)
{}

GVector::~GVector()
{
    delete[] _val;
}

int& GVector::operator[](size_t ix)
{
    if (ix + 1 > this->_size)
    {
        std::string errorMsg = std::string("Trying to get element with index ") + 
            std::to_string(ix) + std::string(" from array with size ") + 
            std::to_string(this->_size);

        throw std::out_of_range(errorMsg);
    }

    return this->_val[ix];
}

void GVector::print()
{
    if (this->_val == nullptr || this->_size <= 0)
    {
        std::string errorMsg = std::string("Trying to print uninitialized GVector");
        
        throw std::runtime_error(errorMsg);
    }

    int maxNumsInRow = 10;
    int numsInRow = 0;
    for (size_t ix = 0; ix < this->_size; ++ix)
    {
        std::cout << this->_val[ix];
        numsInRow++;

        if (ix != this->_size - 1)
            std::cout << " ";

        if (numsInRow == maxNumsInRow || ix == this->_size - 1)
        {
            std::cout << std::endl;
            numsInRow = 0;
        }
    }
}
