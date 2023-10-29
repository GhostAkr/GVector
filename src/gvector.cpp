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
