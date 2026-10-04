#ifndef XPARAMETERS_H   /* prevent circular inclusions */
#define XPARAMETERS_H   /* by using protection macros */

#define XPAR_XGPIO_NUM_INSTANCES 1

/* Definitions for peripheral AXI_GPIO_0 */
#define XPAR_AXI_GPIO_0_COMPATIBLE "xlnx,axi-gpio-2.0"
#define XPAR_AXI_GPIO_0_BASEADDR 0x40000000
#define XPAR_AXI_GPIO_0_HIGHADDR 0x4000ffff
#define XPAR_AXI_GPIO_0_INTERRUPT_PRESENT 0x0
#define XPAR_AXI_GPIO_0_IS_DUAL 0x1
#define XPAR_AXI_GPIO_0_GPIO_WIDTH 0x4

/* Canonical definitions for peripheral AXI_GPIO_0 */
#define XPAR_XGPIO_0_BASEADDR 0x40000000
#define XPAR_XGPIO_0_HIGHADDR 0x4000ffff
#define XPAR_XGPIO_0_COMPATIBLE "xlnx,axi-gpio-2.0"
#define XPAR_XGPIO_0_GPIO_WIDTH 0x4
#define XPAR_XGPIO_0_INTERRUPT_PRESENT 0x0
#define XPAR_XGPIO_0_IS_DUAL 0x1

#define XPAR_XTMRCTR_NUM_INSTANCES 1

/* Definitions for peripheral AXI_TIMER_0 */
#define XPAR_AXI_TIMER_0_COMPATIBLE "xlnx,axi-timer-2.0"
#define XPAR_AXI_TIMER_0_BASEADDR 0x41c00000
#define XPAR_AXI_TIMER_0_HIGHADDR 0x41c0ffff
#define XPAR_AXI_TIMER_0_CLOCK_FREQUENCY 0x5f5e100

/* Canonical definitions for peripheral AXI_TIMER_0 */
#define XPAR_XTMRCTR_0_BASEADDR 0x41c00000
#define XPAR_XTMRCTR_0_HIGHADDR 0x41c0ffff
#define XPAR_XTMRCTR_0_COMPATIBLE "xlnx,axi-timer-2.0"
#define XPAR_XTMRCTR_0_CLOCK_FREQUENCY 0x5f5e100

#define XPAR_LMB_BRAM_0_BASEADDRESS 0x0
#define XPAR_LMB_BRAM_0_HIGHADDRESS 0x3fff
#define XPAR_CPU_CORE_CLOCK_FREQ_HZ 100000000

#define XPAR_MICROBLAZE_ADDR_SIZE 32

#define XPAR_MICROBLAZE_USE_STACK_PROTECTION 0

/* Number of SLRs */
#define NUMBER_OF_SLRS 0x1

/* Device ID */
#define XPAR_DEVICE_ID "7z010"

#endif  /* end of protection macro */