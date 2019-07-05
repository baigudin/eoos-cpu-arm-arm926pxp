/**
 * Boot routine.
 *
 * The module initializes AM65x R5F MCU and C/C++ run-time environment.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
        .thumb

        .global    _c_int00

        .extern    __bss_start__
        .extern    __bss_end__
        .extern    main
        .extern    CpuBoot_initialize

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
_c_int00:
        /* Synchronize data and instructions */
        dsb
        isb
        /* Disable IRQ and FIQ interrupts */
        cpsid   if
        /* Reset registers */
        mov     r0,  #0
        mov     r1,  r0
        mov     r2,  r0
        mov     r3,  r0
        mov     r4,  r0
        mov     r5,  r0
        mov     r6,  r0
        mov     r7,  r0
        mov     r8,  r0
        mov     r9,  r0
        mov     r10, r0
        mov     r11, r0
        mov     r12, r0
        ldr     r0, =__usr_stack_top__
        mov     sp,  r0
        mov     r0,  #0
        mov     lr,  r0
        /* Call C/C++ environment initialization */
        bl      CpuBoot_initialize
        cmp     R0, #0
mc_no_boot:
        beq     mc_no_boot
        /* Call the system main method */
        bl      main
        /* The execution of the system is terminated */
        cpsid   if
mc_terminate:
        wfi
        b       mc_terminate
