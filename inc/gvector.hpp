#ifndef GVECTOR_HPP
#define GVECTOR_HPP

#include <cstddef>

namespace GAlg
{
    class GVector
    {
    public:
        GVector();
        GVector(std::size_t size);
        GVector(const GVector& other);
        GVector(GVector&& other);
        ~GVector();

        GVector& operator=(GVector other);
        int& operator[](size_t ix);

        friend void swap(GVector& firstm, GVector& second);

        void print();

    private:
        int* _val;
        std::size_t _size;

        void swap(GVector& other);

    };

    void swap(GVector& first, GVector& second);
}

#endif  // GVECTOR_HPP
