
#pragma once

#include <string>
#include <iostream>

namespace utils {

    namespace {
        struct control_block
        {
            int _reference_count;

            auto operator ++()
                -> control_block &
            {
                this->_reference_count += 1;
                return *this;
            }

            auto operator --()
                -> control_block &
            {
                this->_reference_count -= 1;
                return *this;
            }
        };
    }

template <typename T>
struct shared_pointer
{
    public:
        explicit shared_pointer(T * raw_pointer)
        {
            _obj_ptr = raw_pointer;
            _block   = new control_block{1};
        }

        shared_pointer(shared_pointer<T> const & other)
        {
            _obj_ptr = other._obj_ptr;
            _block   = other._block;
            ++(*_block);
        }

        ~shared_pointer()
        {
            --(*_block);
            if( _block->_reference_count == 0 )
            {
                std::cout << "Deleting obj memory\n";
                delete _obj_ptr;
            }
        }

        template <typename U>
        friend auto to_string(shared_pointer<U> const & item)
            -> std::string
        {
            return std::string{"reference count => " + std::to_string(item._block->_reference_count)};
        }

        auto ref_count() const
            -> int
        {
            return _block->_reference_count;
        }

    private:
        T             * _obj_ptr{nullptr};
        control_block * _block{nullptr};
};

}
