#ifndef GVECTOR_HPP
#define GVECTOR_HPP

#include <cstddef>

class GVector
{
public:
    GVector();
    GVector(std::size_t size);
    ~GVector();

private:
    int* _val;
    std::size_t _size;

};

#endif  // GVECTOR_HPP
