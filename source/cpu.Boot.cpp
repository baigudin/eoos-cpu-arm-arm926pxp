/**
 * Boot routine.
 *
 * The module performs the tasks to initialize C/C++ run-time environment.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "cpu.Boot.hpp"

extern "C"
{
    extern void (* const __init_array_start[])(void);
    extern void (* const __init_array_end[])(void);

    /**
     * Initialization.
     *
     * @return true if no errors have been occurred.
     */
    int CpuBoot_initialize()
    {
        int i;
        int const count = __init_array_end - __init_array_start;
        for(i=0; i<count; i++)
        {
            __init_array_start[i]();
        }
        return 1;
    }
}

namespace local
{
    namespace cpu
    {
        /**
         * Initialization.
         *
         * @return true if no errors have been occurred.
         */
        bool Boot::initialize()
        {
            return ( CpuBoot_initialize() == 1) ? true : false;
        }
    }
}
