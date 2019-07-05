/**
 * Root class of the operating system target CPU class hierarchy.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_OBJECT_HPP_
#define CPU_OBJECT_HPP_

#include "Object.hpp"
#include "cpu.Allocator.hpp"

namespace local
{
    namespace cpu
    {
        class Object : public ::local::Object<Allocator>
        {
            typedef ::local::Object<Allocator> Parent;

        public:

            /**
             * Constructor.
             */
            Object();

            /**
             * Destructor.
             */
            virtual ~Object();

        };
    }
}
#endif // CPU_OBJECT_HPP_
