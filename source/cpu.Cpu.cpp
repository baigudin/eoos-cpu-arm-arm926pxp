/**
 * The operating system target CPU class.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "cpu.Cpu.hpp"

namespace local
{
    namespace cpu
    {
        /**
         * Constructor.
         *
         * @param config a operating system configuration.
         */
        Cpu::Cpu(const Configuration& config) : Parent(),
            config_ (config),
            pll_    (config_),
            int_    (config_),
            tim_    (config_){
            bool const isConstructed = construct();
            setConstructed( isConstructed );
        }

        /**
         * Destructor.
         */
        Cpu::~Cpu()
        {
        }

        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */
        bool Cpu::isConstructed() const
        {
            return Parent::isConstructed();
        }

        /**
         * Returns a name of a target Central Processing Unit.
         *
         * @return a CPU name, or NULL if an error has been occurred.
         */
        const char* Cpu::getName() const
        {
            return "TI AM65x R5F MCU";
        }

        /**
         * Returns an ID of CPU core executing this program code.
         *
         * @return a CPU ID, or -1 if an error has been occurred.
         */
        int32 Cpu::getCoreId() const
        {
            // TODO: Currently, the R5F MCU executes applications in Split Mode on the core 0
            return 0;
        }

        /**
         * Creates a new HW PLL resource.
         *
         * @return a new PLL resource, or NULL if an error has been occurred.
         */
        api::CpuPll* Cpu::createPll()
        {
            api::CpuPll* const res = pll_.create();
            return proveResource(res);
        }

        /**
         * Creates a new HW interrupt resource.
         *
         * @param handler - user class which implements an interrupt handler interface.
         * @param source  - available interrupt source number.
         * @return a new interrupt resource, or NULL if an error has been occurred.
         */
        api::CpuInterrupt* Cpu::createInterrupt(api::Task& handler, int32 const source)
        {
            api::CpuInterrupt* const res = int_.create(handler, source);
            return proveResource(res);
        }

        /**
         * Creates a new HW timer resource.
         *
         * @param index - an available timer index.
         * @return a new timer resource, or NULL if an error has been occurred.
         */
        api::CpuTimer* Cpu::createTimer(int32 const index)
        {
            api::CpuTimer* const res = tim_.create(index);
            return proveResource(res);
        }

        /**
         * Returns the processor stack operation type.
         *
         * @return the stack operation.
         */
        api::Stack<int64>::Operation Cpu::getStackType()
        {
            // The ARM EABI:
            // Full stacks have stack pointers that point to the last used location.
            // Descending stacks grow towards decreasing memory addresses.
            return api::Stack<int64>::FD;
        }

        /**
         * Constructs this object.
         *
         * @return true if object has been constructed successfully.
         */
        bool Cpu::construct()
        {
            bool res = Self::isConstructed();
            while(res == true)
            {
                if( not pll_.isConstructed() )
                {
                    res = false;
                    continue;
                }
                if( not int_.isConstructed() )
                {
                    res = false;
                    continue;
                }
                if( not tim_.isConstructed() )
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
