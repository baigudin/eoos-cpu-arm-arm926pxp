/**
 * The operating system target CPU memory allocator.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "cpu.Allocator.hpp"

namespace local
{
    namespace cpu
    {
        /**
         * Allocates memory.
         *
         * @param size number of bytes to allocate.
         * @return allocated memory address or a null pointer.
         */
        void* Allocator::allocate(const size_t)
        {
            return NULL;
        }

        /**
         * Frees an allocated memory.
         *
         * @param ptr address of allocated memory block or a null pointer.
         */
        void Allocator::free(void* const)
        {
        }
    }
}
