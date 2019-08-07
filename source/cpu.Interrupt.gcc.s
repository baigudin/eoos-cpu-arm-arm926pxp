/**
 * Interrupt low level module.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
        .arm
        .extern  _c_int00

/****************************************************************************/

/**
 * Hardware interrupt exception vectors.
 */
        .section    .text.hwi, "ax"
m_reset:                                               /* Priorities */
        ldr     pc, a_m_interrupt_handle_rst           /* 0 */
        ldr     pc, a_m_interrupt_handle_und           /* 5 */
        ldr     pc, a_m_interrupt_handle_swi           /* 5 */
        ldr     pc, a_m_interrupt_handle_abt_prefetch  /* 4 */
        ldr     pc, a_m_interrupt_handle_abt_data      /* 1 */
        .word   0xDEADDEAD                             /* N */
        ldr     pc, a_m_interrupt_handle_irq           /* 3 */
        ldr     pc, a_m_interrupt_handle_fiq           /* 2 */

    /* TODO: This has to be moved in memory to somewhere, as it shouldn't be located after the
             the HWI table probably. But also the labels must be accessible for LDR instructions. */
a_m_interrupt_handle_rst:          .word m_interrupt_handle_rst
a_m_interrupt_handle_und:          .word m_interrupt_handle_und
a_m_interrupt_handle_swi:          .word m_interrupt_handle_swi
a_m_interrupt_handle_abt_prefetch: .word m_interrupt_handle_abt_prefetch
a_m_interrupt_handle_abt_data:     .word m_interrupt_handle_abt_data
a_m_interrupt_handle_res:          .word 0xDEADDEAD
a_m_interrupt_handle_irq:          .word m_interrupt_handle_irq
a_m_interrupt_handle_fiq:          .word m_interrupt_handle_fiq

/****************************************************************************/

        .text
/**
 * Reset exception handler.
 */
m_interrupt_handle_rst:
        ldr     pc, a_m__c_int00

a_m__c_int00: .word _c_int00

/**
 * Undefined Instruction exception handler.
 */
m_interrupt_handle_und:
        b       m_interrupt_handle_und

/**
 * Undefined Instruction exception handler.
 */
m_interrupt_handle_swi:
        b       m_interrupt_handle_swi
/**
 * Prefetch Abort exception handler.
 */
m_interrupt_handle_abt_prefetch:
        b       m_interrupt_handle_abt_prefetch

/**
 * Data Abort exception handler.
 */
m_interrupt_handle_abt_data:
        b       m_interrupt_handle_abt_data

/**
 * IRQ exception handler.
 */
m_interrupt_handle_irq:
        b       m_interrupt_handle_irq

/**
 * FIQ exception handler.
 */
m_interrupt_handle_fiq:
        b       m_interrupt_handle_fiq
