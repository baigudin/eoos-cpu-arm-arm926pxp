/**
 * Boot routine.
 *
 * The module initializes AM65x R5F MCU and C/C++ run-time environment.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
        .arm

        .global    _start

        .extern    __bss_start__
        .extern    __bss_end__
        .extern    main
        .extern    CpuBoot_initialize
        .extern    CpuUart_putString

/* Mode bits of program status registers */
#define PSR_USR 0x00000010
#define PSR_FIQ 0x00000011
#define PSR_IRQ 0x00000012
#define PSR_SVC 0x00000013
#define PSR_ABT 0x00000017
#define PSR_UND 0x0000001b
#define PSR_SYS 0x0000001F

/* Bit masks of program status registers */
#define PSR_M  0x0000001F
#define PSR_T  0x00000020
#define PSR_F  0x00000040
#define PSR_I  0x00000080
#define PSR_A  0x00000100
#define PSR_E  0x00000200
#define PSR_GE 0x000f0000
#define PSR_J  0x01000000
#define PSR_Q  0x08000000
#define PSR_V  0x10000000
#define PSR_C  0x20000000
#define PSR_Z  0x40000000
#define PSR_N  0x80000000

        .text
/**
 * The bootstrap routine.
 */
_start:
        /* Disable IRQ and FIQ interrupts */
        cpsid   if
        /* Output the Hello message */
        ldr     r0,  =s_hello
        bl      CpuUart_putString
        /* Set FIQ mode */
        mov     r0,  #PSR_I|PSR_F|PSR_FIQ
        msr     cpsr_fsxc, r0
        mov     r8,  #0
        mov     r9,  #0
        mov     r10, #0
        mov     r11, #0
        mov     r12, #0
        ldr     sp,  =__fiq_stack_top__
        mov     lr,  #0
        /* Set IRQ mode */
        mov     r0,  #PSR_I|PSR_F|PSR_IRQ
        msr     cpsr_fsxc, r0
        ldr     sp,  =__irq_stack_top__
        mov     lr,  #0
        /* Set abort mode */
        mov     r0,  #PSR_I|PSR_F|PSR_ABT
        msr     cpsr_fsxc, r0
        ldr     sp,  =__abt_stack_top__
        mov     lr,  #0
        /* Set undefined mode */
        mov     r0,  #PSR_I|PSR_F|PSR_UND
        msr     cpsr_fsxc, r0
        ldr     sp,  =__und_stack_top__
        mov     lr,  #0
        /* Set supervisor mode */
        mov     r0,  #PSR_I|PSR_F|PSR_SVC
        msr     cpsr_fsxc, r0
        ldr     sp,  =__svc_stack_top__
        mov     lr,  #0
        /* Set system mode */
        mov     r0,  #PSR_I|PSR_F|PSR_SYS
        msr     cpsr_fsxc, r0
        mov     r0,  #0
        mov     r1,  #0
        mov     r2,  #0
        mov     r3,  #0
        mov     r4,  #0
        mov     r5,  #0
        mov     r6,  #0
        mov     r7,  #0
        mov     r8,  #0
        mov     r9,  #0
        mov     r10, #0
        mov     r11, #0
        mov     r12, #0
        ldr     sp, =__usr_stack_top__
        mov     lr,  #0
        /* Clean bss section */
        mov     r0, #0             /* Fill value */
        ldr     r1, =__bss_start__ /* Start of memory block */
        ldr     r3, =__bss_end__   /* End of memory block */
        subs    r4, r3, r1         /* Length of block */
        beq     m_clear_end
mc_clear:
        strb    r0, [r1], #1
        subs    r4, r4, #1
        bgt     mc_clear
m_clear_end:
        /* Call C/C++ environment initialization */
        bl      CpuBoot_initialize
        cmp     R0, #0
mc_no_boot:
        beq     mc_no_boot
        /* Call the system main method */
        bl      main
        /* The execution of the system is terminated */
        cpsid   if
        /* Output the completion message */
        cmp     r0, #0
        beq     m_goodbye
m_error:
        ldr     r0,  =s_error
        bl      CpuUart_putString
        b       mc_terminate
m_goodbye:
        ldr     r0,  =s_goodbye
        bl      CpuUart_putString
        /* Get idle */
mc_terminate:
        b       mc_terminate

s_hello:    .asciz "[0.000000000] EOOS RT execution started\n"
s_goodbye:  .asciz "[X.CCCCCCCCC] EOOS RT execution completed successfully\n"
s_error:    .asciz "[X.EEEEEEEEE] EOOS RT execution terminated with an error\n"
