/**
 * TI AM65x R5F MCU Interrupt Controller.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_INTERRUPT_HPP_
#define CPU_INTERRUPT_HPP_

#include "cpu.Object.hpp"
#include "api.Task.hpp"
#include "api.CpuInterrupt.hpp"
#include "Configuration.hpp"

namespace local
{
    namespace cpu
    {
        class Interrupt : public cpu::Object
        {
            typedef cpu::Interrupt Self;
            typedef cpu::Object    Parent;

        public:

            /**
             * Constructor.
             *
             * NOTE: A passed configuration will NOT be copied to the class internal data, but used by the class.
             *       Do not invalidate the passed configuration object while an object of the class is alive.
             *
             * @param config a operating system configuration.
             */
            Interrupt(const Configuration& config);

            /**
             * Destructor.
             */
            virtual ~Interrupt();

            /**
             * Tests if this object has been constructed.
             *
             * @return true if object has been constructed successfully.
             */
            virtual bool isConstructed() const;

            /**
             * Creates a new HW interrupt resource.
             *
             * @param handler - user class which implements an interrupt handler interface.
             * @param source  - available interrupt source number.
             * @return a new interrupt resource, or NULL if an error has been occurred.
             */
            api::CpuInterrupt* create(api::Task& handler, int32 source);

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
            Interrupt(const Interrupt& obj);

            /**
             * Assignment operator.
             *
             * @param obj reference to source object.
             * @return reference to this object.
             */
            Interrupt& operator =(const Interrupt& obj);

            /**
             * Configuration of the operating system.
             */
            const Configuration& config_;

        };
    }
}
#endif // CPU_INTERRUPT_HPP_
