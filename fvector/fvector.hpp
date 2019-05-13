
#pragma once

#include <cassert>
#include <cstddef>
#include <utility>
#include <iostream>

struct fvector_int
{
    public:
        explicit fvector_int()
            :_size(0)
            ,_v   (nullptr)
        {}

        explicit fvector_int(std::size_t size)
            :_size{std::move(size)}
            ,_v   {new int[_size]}
        {}

        fvector_int(fvector_int const & v)
            :fvector_int{size(v)}
        {
            for(std::size_t i = 0; i < _size; ++i)
                _v[i] = v[i];
        }

        auto operator = (fvector_int const & v)
            -> fvector_int &;

        ~fvector_int()
        {
            delete [] _v;
        }

        auto operator [] (std::size_t const index)
            -> int &
        {
            assert(index < _size);
            return _v[index];
        }

        auto operator [] (std::size_t const index) const
            -> const int &
        {
            assert(index < _size);
            return _v[index];
        }

        friend auto operator == (fvector_int const & lt
                                ,fvector_int const & rt)
            -> bool;

        friend auto operator < (fvector_int const & lt
                               ,fvector_int const & rt)
            -> bool;

        friend auto size(fvector_int const & v)
            -> std::size_t;

    private:
        std::size_t   _size;
        int         * _v;

};

auto fvector_int::operator=(fvector_int const & v)
    -> fvector_int &
{
    if( this != &v )
    {
        if( size(*this) == size(v) )
        {
            for(std::size_t i = 0; i < size(*this); ++i)
                this->_v[i] = v[i];
        }
        else
        {
            this -> ~fvector_int();
            new (this) fvector_int{v};
        }
    }
    return *this;
}

auto size(fvector_int const & v)
    -> std::size_t
{
    return v._size;
}

auto operator << (std::ostream & out, fvector_int const & v)
    -> std::ostream &
{
    auto const length = size(v);
    std::cout << "{";
    for(std::size_t i = 0; i < length; ++i)
        std::cout << v[i] << ", ";
    std::cout << "}";
    return out;
}

auto operator == (fvector_int const & lt
                 ,fvector_int const & rt)
    -> bool
{
    if( size(lt) != size(rt) )
        return false;

    for(std::size_t i = 0; i < size(lt); ++i)
        if( lt[i] != rt[i] )
            return false;

    return true;
}

auto operator != (fvector_int const & lt
                 ,fvector_int const & rt)
    -> bool
{
    return !(lt == rt);
}

auto operator < (fvector_int const & lt
                ,fvector_int const & rt)
    -> bool
{
    auto const minimum_size = std::min(size(lt), size(rt));
    auto       i            = std::size_t{0};
    while( (i < minimum_size) and (lt[i] == rt[i]) )
    {
        ++i;
    }
    if( i < minimum_size )
        return lt[i] < rt[i];
    return size(lt) < size(rt);
}

auto operator > (fvector_int const & lt
                ,fvector_int const & rt)
    -> bool
{
    return rt < lt;
}

auto operator >= (fvector_int const & lt
                 ,fvector_int const & rt)
    -> bool
{
    return !(lt < rt);
}

auto operator <= (fvector_int const & lt
                 ,fvector_int const & rt)
    -> bool
{
    return !(lt > rt);
}
