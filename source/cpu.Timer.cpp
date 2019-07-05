/**
 * TI AM65x R5F MCU Timer Controller.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "cpu.Timer.hpp"

namespace local
{
    namespace cpu
    {
        /**
         * Constructor.
         *
         * @param config a operating system configuration.
         */
        Timer::Timer(const Configuration& config) : Parent(),
            config_ (config){
            bool const isConstructed = construct();
            setConstructed( isConstructed );
        }

        /**
         * Destructor.
         */
        Timer::~Timer()
        {
        }

        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */
        bool Timer::isConstructed() const
        {
            return Parent::isConstructed();
        }

        /**
         * Creates a new HW timer resource.
         *
         * @param index - an available timer index.
         * @return a new timer resource, or NULL if an error has been occurred.
         */
        api::CpuTimer* Timer::create(int32 const index)
        {
            return NULL;
        }

        /**
         * Constructs this object.
         *
         * @return true if object has been constructed successfully.
         */
        bool Timer::construct()
        {
            bool res = Self::isConstructed();
            while(res == true)
            {
                if( config_.cpuClock == 0 || config_.sourceClock == 0 )
                {
                    res = false;
                    continue;
                }
                // The construction completed successfully
                break;
            }
            return res;
        }
    }
}
