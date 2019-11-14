
#pragma once

#include <string>
#include <iostream>

namespace utils {


template <typename T>
class shared_pointer
{
    private:

        struct control_block_impl
        {
            int _reference_count;

            control_block_impl() : _reference_count{1} {}

            virtual void destroy() = 0;
            virtual ~control_block_impl() {};
        };

        template <typename Object, typename Deleter>
        struct control_block : control_block_impl
        {
            Object  * obj;
            Deleter   deleter;

            control_block(Object * o, Deleter d) : obj(o), deleter(d) {}

            virtual void destroy()
            {
                deleter(obj);
            }
        };

        template <typename U>
        struct default_deleter
        {
            void operator() (U * obj) const { delete obj;}
        };

        void increment_count() 
        {
            if( _block != nullptr )
                _block->_reference_count += 1;
        }

        void decrement_count() 
        {
            if( _block != nullptr )
            {
                if( !--(_block->_reference_count) )
                {
                    _block->destroy();
                    delete _block;
                }
            }
        }

        control_block_impl * _block;
        T                  * _obj_ptr;

    public:

        shared_pointer() : _block(), _obj_ptr() {}

        template <typename U>
        shared_pointer(U * raw_pointer)
            : _block(new control_block<U, default_deleter<U>>{raw_pointer, default_deleter<U>{}})
             ,_obj_ptr(raw_pointer)
        {}

        template <typename U, typename Deleter>
        shared_pointer(U * raw_pointer, Deleter d)
            : _block(new control_block<U, Deleter>{raw_pointer, d})
             ,_obj_ptr(raw_pointer)
        {}

        shared_pointer(shared_pointer<T> const & other)
            : _block(other._block)
             ,_obj_ptr(other._obj_ptr)
        {
            increment_count();
        }

        shared_pointer & operator = (shared_pointer<T> const & other)
        {
            if( &other != this )
            {
                decrement_count();
                _block = other._block;
                _obj_ptr = other._obj_ptr;
                increment_count();
            }
            return *this;
        }

        ~shared_pointer()
        {
            decrement_count();
        }

        template <typename U>
        friend auto to_string(shared_pointer<U> const & item)
            -> std::string
        {
            return std::string{"reference count => " + std::to_string(item.use_count())};
        }

        auto use_count() const
            -> int
        {
            return _block->_reference_count;
        }

        T* operator->() const { return  _obj_ptr;}
        T& operator*() const  { return *_obj_ptr;}
};

}
