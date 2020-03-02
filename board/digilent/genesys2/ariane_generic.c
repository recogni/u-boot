// SPDX-License-Identifier: GPL-2.0+
// //Brett Copied from board/sifive/fu540/fu540.c
/*
 * Copyright (c) 2019 Western Digital Corporation or its affiliates.
 *
 * Authors:
 *   Anup Patel <anup.patel@wdc.com>
 */

#include <common.h>
#include <dm.h>
#include <linux/delay.h>
#include <linux/io.h>

#ifdef CONFIG_MISC_INIT_R

#endif

int board_init(void)
{
	/* For now nothing to do here. */
    puts("ariane_generic board_init()\n");
	return 0;
}


