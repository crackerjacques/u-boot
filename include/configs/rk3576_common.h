/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2024 Rockchip Electronics Co., Ltd
 */

#ifndef __CONFIG_RK3576_COMMON_H
#define __CONFIG_RK3576_COMMON_H

#define CFG_CPUID_OFFSET	0xa

#include "rockchip-common.h"

#define CFG_IRAM_BASE			0x3ff80000

#define CFG_SYS_SDRAM_BASE		0x40000000
/* Used by board_get_usable_ram_top(), space below the 4G address boundary */
#define SDRAM_MAX_SIZE			(SZ_4G - CFG_SYS_SDRAM_BASE)

#ifndef ROCKCHIP_DEVICE_SETTINGS
#define ROCKCHIP_DEVICE_SETTINGS
#endif

#define CFG_EXTRA_ENV_SETTINGS		\
	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0"	\
	ENV_MEM_LAYOUT_SETTINGS		\
	ROCKCHIP_DEVICE_SETTINGS	\
	"boot_targets=" BOOT_TARGETS "\0"

#endif /* __CONFIG_RK3576_COMMON_H */
