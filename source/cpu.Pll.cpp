/**
 * TI AM65x R5F MCU Phase-Locked Loop Controller.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "cpu.Pll.hpp"

namespace local
{
    namespace cpu
    {
        /**
         * Constructor.
         *
         * @param config a operating system configuration.
         */
        Pll::Pll(const Configuration& config) : Parent(),
            config_ (config){
            bool const isConstructed = construct();
            setConstructed( isConstructed );
        }

        /**
         * Destructor.
         */
        Pll::~Pll()
        {
        }

        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */
        bool Pll::isConstructed() const
        {
            return Parent::isConstructed();
        }

        /**
         * Creates a new HW PLL resource.
         *
         * @return a new PLL resource, or NULL if an error has been occurred.
         */
        api::CpuPll* Pll::create()
        {
            return NULL;
        }

        /**
         * Constructs this object.
         *
         * @return true if object has been constructed successfully.
         */
        bool Pll::construct()
        {
            bool res = Self::isConstructed();
            while(res == true)
            {
                // Check configuration
                if( config_.cpuClock == 0 || config_.sourceClock == 0 )
                {
                    res = false;
                    continue;
                }

                // TODO
                // Base initialization of ARM Core is probably made by the MCU ROM Code.
                // So, the checking that the PLL initialization is correctly has to be done here,
                // and also peripherals like Eth and etc. have to be written.

                // The construction completed successfully
                break;
            }
            return res;
        }
    }
}
