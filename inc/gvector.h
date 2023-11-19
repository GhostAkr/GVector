#ifndef GVECTOR_HPP
#define GVECTOR_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>

namespace GAlg
{
    // Forward declarations

    template<typename T>
    class GVector;

    template<typename T>
    void swap(GVector<T>& first, GVector<T>& second);

    // Classes

    template<typename T>
    class GVector
    {
    public:

        // Structors

        GVector() noexcept
            : _val(nullptr)
            , _size(0)
        {}

        GVector(std::size_t size)
            : _val(new T[size])
            , _size(size)
        {}

        GVector(const GVector& other)
            : GVector(other._size)
        {
            std::memcpy(this->_val, other._val, other._size * sizeof(int));
        }   


        GVector(GVector&& other) noexcept
            : _val(other._val)
            , _size(other._size)
        {
            other._val = nullptr;
            other._size = 0;
        }

        ~GVector()
        {
            delete[] _val;
        }

        // Operators

        GVector& operator=(GVector other)
        {
            GAlg::swap<T>(*this, other);
            return *this;
        }

        T& operator[](size_t ix)
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

        // Friends

        template<typename A>
        friend void GAlg::swap(GVector<A>& firstm, GVector<A>& second);

        // Methods

        void print()
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

    private:

        // Fields

        T* _val;
        std::size_t _size;

        // Methods

        void swap(GVector& other)
        {
            using std::swap;

            swap(this->_val, other._val);
            swap(this->_size, other._size);
        }

    };

    // GAlg's functions

    template<typename T>
    void swap(GVector<T>& first, GVector<T>& second)
    {
        first.swap(second);
    }

    // Extern instantiations

    extern template class GVector<int>;
    extern template class GVector<float>;
    extern template class GVector<double>;

    // Aliases

    using GVectorI = GVector<int>;
    using GVectorF = GVector<float>;
    using GVectorD = GVector<double>;
}

#endif  // GVECTOR_HPP
