/**
 * UART module.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
        .arm
        .global    CpuUart_putChar
        .global    CpuUart_putString

/* UART registers */
#define REG_UART0_DR 0x101F1000

        .text
/**
 * Puts a char to UART port.
 */
CpuUart_putChar:
        ldr     r2, a_reg_uart0_dr
        str     r0, [r2]
        bx      lr

/**
 * Puts a string to UART port.
 */
CpuUart_putString:
        ldr     r2, a_reg_uart0_dr
        mov     r1, r0
mc_next_char:
        ldrbt   r0, [r1]        @ Load a char
        cmp     r0, #0
        bxeq    lr
        str     r0, [r2]        @ Output to port
        add     r1, r1, #1
        b       mc_next_char

a_reg_uart0_dr: .word REG_UART0_DR
