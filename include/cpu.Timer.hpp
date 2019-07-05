/**
 * TI AM65x R5F MCU Timer Controller.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_TIMER_HPP_
#define CPU_TIMER_HPP_

#include "cpu.Object.hpp"
#include "api.CpuTimer.hpp"
#include "Configuration.hpp"

namespace local
{
    namespace cpu
    {
        class Timer : public cpu::Object
        {
            typedef cpu::Timer  Self;
            typedef cpu::Object Parent;

        public:

            /**
             * Constructor.
             *
             * NOTE: A passed configuration will NOT be copied to the class internal data, but used by the class.
             *       Do not invalidate the passed configuration object while an object of the class is alive.
             *
             * @param config a operating system configuration.
             */
            Timer(const Configuration& config);

            /**
             * Destructor.
             */
            virtual ~Timer();

            /**
             * Tests if this object has been constructed.
             *
             * @return true if object has been constructed successfully.
             */
            virtual bool isConstructed() const;

            /**
             * Creates a new HW timer resource.
             *
             * @param index - an available timer index.
             * @return a new timer resource, or NULL if an error has been occurred.
             */
            api::CpuTimer* create(int32 index);

        private:

            /**
             * Constructs this object.
             *
             * @return true if object has been constructed successfully.
             */
            bool construct();

            /**
             * Copy constructor.
             *
             * @param obj reference to source object.
             */
            Timer(const Timer& obj);

            /**
             * Assignment operator.
             *
             * @param obj reference to source object.
             * @return reference to this object.
             */
            Timer& operator =(const Timer& obj);

            /**
             * Configuration of the operating system.
             */
            const Configuration& config_;

        };
    }
}
#endif // CPU_TIMER_HPP_
