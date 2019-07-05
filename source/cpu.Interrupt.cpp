/**
 * TI AM65x R5F MCU Interrupt Controller.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "cpu.Interrupt.hpp"

namespace local
{
    namespace cpu
    {
        /**
         * Constructor.
         *
         * @param config a operating system configuration.
         */
        Interrupt::Interrupt(const Configuration& config) : Parent(),
            config_ (config){
            bool const isConstructed = construct();
            setConstructed( isConstructed );
        }

        /**
         * Destructor.
         */
        Interrupt::~Interrupt()
        {
        }

        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */
        bool Interrupt::isConstructed() const
        {
            return Parent::isConstructed();
        }

        /**
         * Creates a new HW interrupt resource.
         *
         * @param handler - user class which implements an interrupt handler interface.
         * @param source  - available interrupt source number.
         * @return a new interrupt resource, or NULL if an error has been occurred.
         */
        api::CpuInterrupt* Interrupt::create(api::Task& handler, int32 const source)
        {
            return NULL;
        }

        /**
         * Constructs this object.
         *
         * @return true if object has been constructed successfully.
         */
        bool Interrupt::construct()
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
