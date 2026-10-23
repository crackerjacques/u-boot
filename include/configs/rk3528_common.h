/* SPDX-License-Identifier: GPL-2.0-or-later */
/* Copyright Contributors to the U-Boot project. */

#ifndef __CONFIG_RK3528_COMMON_H
#define __CONFIG_RK3528_COMMON_H

#define CFG_CPUID_OFFSET		0xa

#include "rockchip-common.h"

#define CFG_IRAM_BASE			0xfe480000

#define CFG_SYS_SDRAM_BASE		0
#define SDRAM_MAX_SIZE			0xfc000000

#ifndef ROCKCHIP_DEVICE_SETTINGS
#define ROCKCHIP_DEVICE_SETTINGS
#endif

#define CFG_EXTRA_ENV_SETTINGS			\
	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0"	\
	ENV_MEM_LAYOUT_SETTINGS			\
	ROCKCHIP_DEVICE_SETTINGS		\
	"boot_targets=" BOOT_TARGETS "\0"

#endif /* __CONFIG_RK3528_COMMON_H */
