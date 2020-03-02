/*
 * Copyright (C) 2017 Andes Technology Corporation
 * Rick Chen, Andes Technology Corporation <rick@andestech.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

/* Brett: Copied from cp ~/u-boot/u-boot-riscv/include/configs/lowrisc-ariane.h include/configs/ariane-generic.h */
#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * CPU and Board Configuration Options
 */
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_BOOTP_SERVERIP

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_CBSIZE	1024	/* Console I/O Buffer Size */

/*
 * Print Buffer Size
 */
#define CONFIG_SYS_PBSIZE	\
	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)

/*
 * max number of command args
 */
#define CONFIG_SYS_MAXARGS	16

/*
 * Boot Argument Buffer Size
 */
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE

/*
 * Size of malloc() pool
 * 512kB is suggested, (CONFIG_ENV_SIZE + 128 * 1024) was not enough
 */
#define CONFIG_SYS_MALLOC_LEN   (512 << 10)  /* 512KB */

/* DT blob (fdt) address */
#define CONFIG_SYS_FDT_BASE		0x000f0000

/*
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_SDRAM_0	0x84000000		/* SDRAM Bank #1 */
#define PHYS_SDRAM_0_SIZE	0x4000000	/* 64 MB */
#define CONFIG_SYS_SDRAM_BASE	PHYS_SDRAM_0

/*
 * Serial console configuration
 */
//#define CONFIG_UART_SBI
#define CONFIG_SYS_NS16550_SERIAL
#ifndef CONFIG_DM_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	-4
#endif
#define CONFIG_SYS_NS16550_CLK		50000000 //19660800

/* Init Stack Pointer */

// #define CONFIG_SYS_INIT_SP_ADDR		0x90004000 - GENERATED_GBL_DATA_SIZE
#define CONFIG_SYS_INIT_SP_ADDR                0x84000000 - GENERATED_GBL_DATA_SIZE

/*
 * Load address and memory test area should agree with
 * arch/riscv/config.mk. Be careful not to overwrite U-Boot itself.
 */
#define CONFIG_SYS_LOAD_ADDR		0x80200000	/* SDRAM */

#ifdef FOOBAR
/* Copied from ax25-ae350.h */
/* max number of memory banks */
/*
 * There are 4 banks supported for this Controller,
 * but we have only 1 bank connected to flash on board
*/
#ifndef CONFIG_SYS_MAX_FLASH_BANKS_DETECT
#define CONFIG_SYS_MAX_FLASH_BANKS  1
#endif
#define CONFIG_SYS_FLASH_BANKS_SIZES {0x4000000}
#endif

/*
 * memtest works on 1 MB in DRAM
 */

#define CONFIG_SYS_ALT_MEMTEST 1
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_LOAD_ADDR
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_LOAD_ADDR + 0x100000)


/* environments */
//#define CONFIG_ENV_SPI_BUS		0
//#define CONFIG_ENV_SPI_CS		0
//#define CONFIG_ENV_SPI_MAX_HZ		50000000
//#define CONFIG_ENV_SPI_MODE		0
//#define CONFIG_ENV_SECT_SIZE		0x1000
//#define CONFIG_ENV_OVERWRITE
//#define CONFIG_ENV_SIZE		        0x1000

//#define CONFIG_SF_DEFAULT_BUS		0
//#define CONFIG_SF_DEFAULT_CS		0
//#define CONFIG_SF_DEFAULT_SPEED		1000000
//#define CONFIG_SF_DEFAULT_MODE		0

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 16 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */

/* Initial Memory map for Linux*/
#define CONFIG_SYS_BOOTMAPSZ	(64 << 20)
/* Increase max gunzip size */
#define CONFIG_SYS_BOOTM_LEN	(64 << 20)

//#define CONFIG_SYS_LDSCRIPT	"arch/riscv/cpu/ariane/u-boot.lds"


//#define CONFIG_XILINX_AXIEMAC
//#define CONFIG_PHY_REALTEK
//#define CONFIG_RGMII
//#define CONFIG_DM_MDIO

#ifdef FOOBAR
#define read_csr(reg) ({ uint64_t __tmp;         \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  asm volatile ("csrw " #reg ", %0" :: "rK"(val)); })

#define swap_csr(reg, val) ({ uint64_t __tmp; \
  asm volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "rK"(val)); \
  __tmp; })

#define set_csr(reg, bit) ({ uint64_t __tmp; \
  asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
  __tmp; })

#define clear_csr(reg, bit) ({ uint64_t __tmp; \
  asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
  __tmp; })
#endif //FOOBAR
#endif /* __CONFIG_H */
