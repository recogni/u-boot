// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2018, Bin Meng <bmeng.cn@gmail.com>
 */

#include <common.h>
#include <fdtdec.h>
#include <init.h>
#include <asm/global_data.h>
#include <linux/sizes.h>

DECLARE_GLOBAL_DATA_PTR;

int dram_init(void)
{

// #ifdef CONFIG_TARGET_ARIANE_GENERIC
// //Total hackware copied from ~/u-boot/u-boot-riscv.
// //I think the realfix is to call board_init_f(ulong boot_flags)
// //with GD_FLG_SKIP_RELOC.

//     int ret;
//     gd->flags |= GD_FLG_SKIP_RELOC;
// 	ret = fdtdec_setup_mem_size_base();

//     return ret;
// #else
	int ret = fdtdec_setup_mem_size_base();
    gd->ram_size = PHYS_SDRAM_0_SIZE;
	return ret;
    // #endif
}

int dram_init_banksize(void)
{
	return fdtdec_setup_memory_banksize();
}

ulong board_get_usable_ram_top(ulong total_size)
{
	/*
	 * Ensure that we run from first 4GB so that all
	 * addresses used by U-Boot are 32bit addresses.
	 *
	 * This in-turn ensures that 32bit DMA capable
	 * devices work fine because DMA mapping APIs will
	 * provide 32bit DMA addresses only.
	 */
	if (gd->ram_top >= SZ_4G)
		return SZ_4G - 1;

	return gd->ram_top;
}
