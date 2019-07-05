/**
 * TI AM65x R5F MCU Phase-Locked Loop Controller.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_PLL_HPP_
#define CPU_PLL_HPP_

#include "cpu.Object.hpp"
#include "api.CpuPll.hpp"
#include "Configuration.hpp"

namespace local
{
    namespace cpu
    {
        class Pll : public cpu::Object
        {
            typedef cpu::Pll    Self;
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
            Pll(const Configuration& config);

            /**
             * Destructor.
             */
            virtual ~Pll();

            /**
             * Tests if this object has been constructed.
             *
             * @return true if object has been constructed successfully.
             */
            virtual bool isConstructed() const;

            /**
             * Creates a new HW PLL resource.
             *
             * @return a new PLL resource, or NULL if an error has been occurred.
             */
            api::CpuPll* create();

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
            Pll(const Pll& obj);

            /**
             * Assignment operator.
             *
             * @param obj reference to source object.
             * @return reference to this object.
             */
            Pll& operator =(const Pll& obj);

            /**
             * Configuration of the operating system.
             */
            const Configuration& config_;

        };
    }
}
#endif // CPU_PLL_HPP_
