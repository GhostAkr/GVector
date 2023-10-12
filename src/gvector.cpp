#include "../inc/gvector.hpp"

GVector::GVector()
    : _val(nullptr)
{}

GVector::GVector(std::size_t size)
    : _val(new int[size])
{}

GVector::~GVector()
{
    delete[] _val;
}
