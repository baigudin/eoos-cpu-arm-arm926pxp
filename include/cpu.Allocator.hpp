/**
 * The operating system target CPU memory allocator.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_ALLOCATOR_HPP_
#define CPU_ALLOCATOR_HPP_

#include "Types.hpp"

namespace local
{
    namespace cpu
    {
        class Allocator
        {

        public:

            /**
             * Allocates memory.
             *
             * @param size number of bytes to allocate.
             * @return allocated memory address or a null pointer.
             */
            static void* allocate(size_t size);

            /**
             * Frees an allocated memory.
             *
             * @param ptr address of allocated memory block or a null pointer.
             */
             static void free(void* ptr);

        };
    }
}
#endif // CPU_ALLOCATOR_HPP_
