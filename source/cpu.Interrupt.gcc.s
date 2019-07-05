/**
 * Interrupt low level module.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
        .thumb
        .extern  _c_int00

/****************************************************************************/

/**
 * Hardware interrupt exception vectors.
 */
        .section    .hwi
        .word       __usr_stack_top__
        .word       m_interrupt_handle_reset
        .word       m_interrupt_handle_nmi
        .word       m_interrupt_handle_hard_fault
        .word       m_interrupt_handle_memory_management
        .word       m_interrupt_handle_bus_fault
        .word       m_interrupt_handle_usage_fault
        .word       0xDEADDEAD
        .word       0xDEADDEAD
        .word       0xDEADDEAD
        .word       0xDEADDEAD
        .word       m_interrupt_handle_sv_call
        .word       m_interrupt_handle_debug_monitor
        .word       0xDEADDEAD
        .word       m_interrupt_handle_pend_sv
        .word       m_interrupt_handle_sys_tick

/****************************************************************************/

        .text
/**
 * Reset exception handler.
 */
m_interrupt_handle_reset:
        b       _c_int00

/**
 * Non-maskable Interrupt exception handler.
 */
m_interrupt_handle_nmi:
        b       m_interrupt_handle_nmi

/**
 * Hard Fault exception handler.
 */
m_interrupt_handle_hard_fault:
        b       m_interrupt_handle_hard_fault

/**
 * Memory Management exception handler.
 */
m_interrupt_handle_memory_management:
        b       m_interrupt_handle_memory_management

/**
 * Bus Fault exception handler.
 */
m_interrupt_handle_bus_fault:
        b       m_interrupt_handle_bus_fault

/**
 * Usage Fault exception handler.
 */
m_interrupt_handle_usage_fault:
        b       m_interrupt_handle_usage_fault

/**
 * SVCall exception handler.
 */
m_interrupt_handle_sv_call:
        b       m_interrupt_handle_sv_call

/**
 * Debug Monitor exception handler.
 */
m_interrupt_handle_debug_monitor:
        b       m_interrupt_handle_debug_monitor

/**
 * PendSV exception handler.
 */
m_interrupt_handle_pend_sv:
        b       m_interrupt_handle_pend_sv

/**
 * SysTick exception handler.
 */
m_interrupt_handle_sys_tick:
        b       m_interrupt_handle_sys_tick
