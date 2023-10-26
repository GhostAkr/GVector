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
