/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2016 Rockchip Electronics Co., Ltd
 */

#ifndef _ROCKCHIP_COMMON_H_
#define _ROCKCHIP_COMMON_H_
#include <linux/sizes.h>

#ifndef CFG_CPUID_OFFSET
#define CFG_CPUID_OFFSET	0x7
#endif

#ifndef CONFIG_XPL_BUILD

#ifndef BOOT_TARGETS
#define BOOT_TARGETS	"mmc1 mmc0 nvme scsi usb pxe dhcp spi"
#endif

#ifdef CONFIG_ARM64
#define ROOT_UUID "B921B045-1DF0-41C3-AF44-4C6F280D3FAE;\0"
#else
#define ROOT_UUID "69DAD710-2CE4-4E3C-B16C-21A1D49ABED3;\0"
#endif
#define PARTS_DEFAULT \
	"uuid_disk=${uuid_gpt_disk};" \
	"name=loader1,start=32K,size=4000K,uuid=${uuid_gpt_loader1};" \
	"name=loader2,start=8MB,size=4MB,uuid=${uuid_gpt_loader2};" \
	"name=trust,size=4M,uuid=${uuid_gpt_atf};" \
	"name=boot,size=112M,bootable,uuid=${uuid_gpt_boot};" \
	"name=rootfs,size=-,uuid="ROOT_UUID

#ifdef CONFIG_ROCKCHIP_COMMON_STACK_ADDR
/*
 * Default load addresses as offsets from the start of DRAM, the same on
 * every SoC with the common memory layout. Everything up to the ramdisk
 * fits below U-Boot proper relocated to the top of 128 MiB of DRAM, and
 * loadaddr (SYS_LOAD_ADDR) sits just above SPL's own stack, heap and BSS.
 * Offsets are pasted after the DRAM base nibble, so they must stay below
 * 0x10000000.
 */
#if CONFIG_SPL_TEXT_BASE == 0x60000000
#define ROCKCHIP_DRAM_HI	"0x6"
#elif CONFIG_SPL_TEXT_BASE == 0x40000000
#define ROCKCHIP_DRAM_HI	"0x4"
#else
#define ROCKCHIP_DRAM_HI	"0x0"
#endif

#define ENV_MEM_LAYOUT_SETTINGS \
	"scriptaddr="		ROCKCHIP_DRAM_HI "0200000\0" \
	"script_offset_f=0xffe000\0" \
	"script_size_f=0x2000\0" \
	"pxefile_addr_r="	ROCKCHIP_DRAM_HI "0300000\0" \
	"fdt_addr_r="		ROCKCHIP_DRAM_HI "0400000\0" \
	"fdtoverlay_addr_r="	ROCKCHIP_DRAM_HI "0500000\0" \
	"kernel_addr_r="	ROCKCHIP_DRAM_HI "0600000\0" \
	"ramdisk_addr_r="	ROCKCHIP_DRAM_HI "5000000\0" \
	"kernel_comp_addr_r="	ROCKCHIP_DRAM_HI "b000000\0" \
	"kernel_comp_size=0x2000000\0"
#endif

#ifndef ENV_MEM_LAYOUT_SETTINGS
#error "Define ENV_MEM_LAYOUT_SETTINGS for boards without ROCKCHIP_COMMON_STACK_ADDR"
#endif

#endif

#endif /* _ROCKCHIP_COMMON_H_ */
