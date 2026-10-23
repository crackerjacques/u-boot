/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 */

#ifndef __CONFIG_PX30_COMMON_H
#define __CONFIG_PX30_COMMON_H

#include "rockchip-common.h"

#define CFG_IRAM_BASE		0xff0e0000

#define GICD_BASE			0xff131000
#define GICC_BASE			0xff132000

#define CFG_SYS_SDRAM_BASE		0
#define SDRAM_MAX_SIZE			0xff000000

#define CFG_EXTRA_ENV_SETTINGS \
	ENV_MEM_LAYOUT_SETTINGS \
	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
	"partitions=" PARTS_DEFAULT \
	ROCKCHIP_DEVICE_SETTINGS \
	"boot_targets=" BOOT_TARGETS "\0"

#endif
