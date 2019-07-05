/**
 * The operating system target CPU class.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_CPU_HPP_
#define CPU_CPU_HPP_

#include "cpu.Object.hpp"
#include "api.Cpu.hpp"
#include "api.Stack.hpp"
#include "cpu.Pll.hpp"
#include "cpu.Interrupt.hpp"
#include "cpu.Timer.hpp"
#include "Configuration.hpp"


namespace local
{
    namespace cpu
    {
        class Cpu : public cpu::Object, public api::Cpu
        {
            typedef cpu::Cpu    Self;
            typedef cpu::Object Parent;

        public:

            /**
             * Constructor.
             *
             * NOTE: A passed configuration will be copied to an internal data of the class.
             *
             * @param config a operating system configuration.
             */
            Cpu(const Configuration& config);

            /**
             * Destructor.
             */
            virtual ~Cpu();

            /**
             * Tests if this object has been constructed.
             *
             * @return true if object has been constructed successfully.
             */
            virtual bool isConstructed() const;

            /**
             * Returns a name of a target Central Processing Unit.
             *
             * @return a CPU name, or NULL if an error has been occurred.
             */
            virtual const char* getName() const;

            /**
             * Returns an ID of CPU core executing this program code.
             *
             * @return a CPU ID, or -1 if an error has been occurred.
             */
            virtual int32 getCoreId() const;

            /**
             * Creates a new HW PLL resource.
             *
             * @return a new PLL resource, or NULL if an error has been occurred.
             */
            virtual api::CpuPll* createPll();

            /**
             * Creates a new HW interrupt resource.
             *
             * @param handler - user class which implements an interrupt handler interface.
             * @param source  - available interrupt source number.
             * @return a new interrupt resource, or NULL if an error has been occurred.
             */
            virtual api::CpuInterrupt* createInterrupt(api::Task& handler, int32 source);

            /**
             * Creates a new HW timer resource.
             *
             * @param index - an available timer index.
             * @return a new timer resource, or NULL if an error has been occurred.
             */
            virtual api::CpuTimer* createTimer(int32 index);

            /**
             * Returns the processor stack operation type.
             *
             * @return the stack operation.
             */
    		static api::Stack<int64>::Operation getStackType();

        private:

            /**
             * Constructs this object.
             *
             * @return true if object has been constructed successfully.
             */
            bool construct();

            /**
             * Proves a resource.
             *
             * @param a resource.
             * @return a passed resource, or NULL if the resource has not been approved.
             */
            template <class T>
            static T* proveResource(T* res)
            {
                if(res != NULL)
                {
                    if( not res->isConstructed() )
                    {
                        delete res;
                        res = NULL;
                    }
                }
                return res;
            }

            /**
             * Copy constructor.
             *
             * @param obj a reference to source object.
             */
            Cpu(const Cpu& obj);

            /**
             * Assignment operator.
             *
             * @param obj a reference to source object.
             * @return reference to this object.
             */
            Cpu& operator =(const Cpu& obj);

            /**
             * Configuration of the operating system.
             */
            Configuration config_;

            /**
             * Target CPU PLL controller.
             */
            Pll pll_;

            /**
             * Target CPU Interrupt controller.
             */
            Interrupt int_;

            /**
             * Target CPU Timer controller.
             */
            Timer tim_;

        };
    }
}
#endif // CPU_CPU_HPP_
