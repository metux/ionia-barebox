/*
 * am3517_evm.h - Default configuration for AM3517 EVM board.
 *
 * Author: Vaibhav Hiremath <hvaibhav@ti.com>
 *
 * Based on omap3_evm_config.h
 *
 * Copyright (C) 2010 Texas Instruments Incorporated
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* High Level Configuration Options */

#define CONFIG_OMAP

#define CONFIG_NR_DRAM_BANKS	2	/* CS1 may or may not be populated */

#define CONFIG_EMIF4	/* The chip has EMIF4 controller */

/*
 * 1MB into the SDRAM to allow for SPL's bss at the beginning of SDRAM
 * 64 bytes before this address should be set aside for u-boot.img's
 * header. That is 0x800FFFC0--0x80100000 should not be used for any
 * other needs.
 */
#define CONFIG_SYS_TEXT_BASE		0x80100000
#define CONFIG_SYS_SPL_MALLOC_START	0x80208000
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x100000

#include <asm/arch/cpu.h>		/* get chip and board defs */
#include <asm/arch/omap.h>

#define CONFIG_MISC_INIT_R
#define CONFIG_CMDLINE_TAG		/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Clock Defines */
#define V_OSCK			26000000	/* Clock output from T2 */
#define V_SCLK			(V_OSCK >> 1)

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(16 << 20)

/* Hardware drivers */

/* OMAP GPIO configuration */
#define CONFIG_OMAP_GPIO

/* NS16550 Configuration */
#define V_NS16550_CLK			48000000	/* 48MHz (APLL96/2) */
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		V_NS16550_CLK

/* select serial console configuration */
#define CONFIG_CONS_INDEX		3
#define CONFIG_SYS_NS16550_COM3		OMAP34XX_UART3
#define CONFIG_SERIAL3			3	/* UART3 on AM3517 EVM */

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{4800, 9600, 19200, 38400, 57600,\
					115200}

/*
 * USB configuration
 * Enable CONFIG_USB_MUSB_HOST for Host functionalities MSC, keyboard
 * Enable CONFIG_USB_MUSB_GADGET for Device functionalities.
 */
#define CONFIG_USB_MUSB_AM35X
#define CONFIG_USB_MUSB_PIO_ONLY

#ifdef CONFIG_USB_MUSB_AM35X

#ifdef CONFIG_USB_MUSB_HOST

#ifdef CONFIG_USB_KEYBOARD
#define CONFIG_SYS_USB_EVENT_POLL
#define CONFIG_PREBOOT "usb start"
#endif /* CONFIG_USB_KEYBOARD */

#endif /* CONFIG_USB_MUSB_HOST */

#ifdef CONFIG_USB_MUSB_GADGET
#define CONFIG_USB_ETHER
#define CONFIG_USB_ETH_RNDIS
#endif /* CONFIG_USB_MUSB_GADGET */

#endif /* CONFIG_USB_MUSB_AM35X */

/* commands to include */
#define CONFIG_CMD_NAND
#define CONFIG_CMD_MTDPARTS

/* I2C */
#define CONFIG_SYS_I2C
#define CONFIG_SYS_OMAP24_I2C_SPEED	100000
#define CONFIG_SYS_OMAP24_I2C_SLAVE	1
#define CONFIG_SYS_I2C_OMAP34XX

/* Ethernet */
#define CONFIG_DRIVER_TI_EMAC
#define CONFIG_DRIVER_TI_EMAC_USE_RMII
#define CONFIG_MII
#define CONFIG_BOOTP_DEFAULT
#define CONFIG_BOOTP_DNS
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_NET_RETRY_COUNT		10

/* Board NAND Info. */
#ifdef CONFIG_NAND
#define CONFIG_NAND_OMAP_GPMC
#define CONFIG_NAND_OMAP_GPMC_PREFETCH
#define CONFIG_BCH
#define CONFIG_CMD_UBIFS		/* Read-only UBI volume operations */
#define CONFIG_RBTREE			/* required by CONFIG_CMD_UBI */
#define CONFIG_LZO			/* required by CONFIG_CMD_UBIFS */

#define CONFIG_HARD_I2C			1
#define CONFIG_SYS_I2C_SPEED		100000
#define CONFIG_SYS_I2C_SLAVE		1

#define CONFIG_CMD_NET

/*
 * Board NAND Info.
 */
#define CONFIG_SYS_NAND_ADDR		NAND_BASE	/* physical address */
							/* to access nand */
#define CONFIG_SYS_NAND_BASE		NAND_BASE	/* physical address */
							/* to access */
							/* nand at CS0 */
#define CONFIG_SYS_MAX_NAND_DEVICE	1		/* Max number of */
							/* NAND devices */
#define CONFIG_SYS_NAND_BUSWIDTH_16BIT
#define CONFIG_SYS_NAND_5_ADDR_CYCLE
#define CONFIG_SYS_NAND_PAGE_COUNT	64
#define CONFIG_SYS_NAND_PAGE_SIZE	2048
#define CONFIG_SYS_NAND_OOBSIZE		64
#define CONFIG_SYS_NAND_BLOCK_SIZE	(128 * 1024)
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	NAND_LARGE_BADBLOCK_POS
#define CONFIG_SYS_NAND_ECCPOS		{ 2,  3,  4,  5,  6,  7,  8,  9, 10, \
					 11, 12, 13, 14, 16, 17, 18, 19, 20, \
					 21, 22, 23, 24, 25, 26, 27, 28, 30, \
					 31, 32, 33, 34, 35, 36, 37, 38, 39, \
					 40, 41, 42, 44, 45, 46, 47, 48, 49, \
					 50, 51, 52, 53, 54, 55, 56 }

#define CONFIG_SYS_NAND_ECCSIZE		512
#define CONFIG_SYS_NAND_ECCBYTES	13
#define CONFIG_NAND_OMAP_ECCSCHEME	OMAP_ECC_BCH8_CODE_HW_DETECTION_SW
#define CONFIG_SYS_NAND_MAX_OOBFREE	2
#define CONFIG_SYS_NAND_MAX_ECCPOS	56
#define CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x80000
#define CONFIG_MTD_PARTITIONS		/* required for UBI partition support */
#define CONFIG_MTD_DEVICE		/* needed for mtdparts commands */
/* NAND block size is 128 KiB.  Synchronize these values with
 * corresponding Device Tree entries in Linux:
 *  MLO(SPL)             4 * NAND_BLOCK_SIZE = 512 KiB  @ 0x000000
 *  U-Boot              15 * NAND_BLOCK_SIZE = 1920 KiB @ 0x080000
 *  U-Boot environment   2 * NAND_BLOCK_SIZE = 256 KiB  @ 0x260000
 *  Kernel              64 * NAND_BLOCK_SIZE = 8 MiB    @ 0x2A0000
 *  DTB                  4 * NAND_BLOCK_SIZE = 512 KiB  @ 0xAA0000
 *  RootFS              Remaining Flash Space           @ 0xB20000
 */
#define MTDIDS_DEFAULT "nand0=omap2-nand.0"
#define MTDPARTS_DEFAULT "mtdparts=omap2-nand.0:"	\
	"512k(MLO),"					\
	"1920k(u-boot),"				\
	"256k(u-boot-env),"				\
	"8m(kernel),"					\
	"512k(dtb),"					\
	"-(rootfs)"
#else
#define MTDIDS_DEFAULT
#define MTDPARTS_DEFAULT
#endif /* CONFIG_NAND */

#define CONFIG_SYS_64BIT_VSPRINTF		/* needed for nand_util.c */

/* Environment information */

#define CONFIG_BOOTFILE		"uImage"

/* Basic 'extra' env variables */
#define EXTRA_ENV_SETTINGS \
	"loadaddr=0x82000000\0" \
	"kloadaddr=0x80007fc0\0" \
	"console=ttyO2,115200n8\0" \
	"fdtfile=am3517-evm.dtb\0" \
	"fdtaddr=0x82C00000\0" \
	"vram=16M\0" \
	"bootenv=uEnv.txt\0" \
	"cmdline=\0" \
	"optargs=\0" \
	"mtdids=" MTDIDS_DEFAULT "\0" \
	"mtdparts=" MTDPARTS_DEFAULT "\0" \
	"mmcdev=0\0" \
	"mmcpart=1\0" \
	"mmcroot=/dev/mmcblk0p2 rw\0" \
	"mmcrootfstype=ext4 rootwait fixrtc\0" \
	"mmcargs=setenv bootargs console=${console} " \
		"${mtdparts} " \
		"${optargs} " \
		"root=${mmcroot} " \
		"rootfstype=${mmcrootfstype} " \
		"${cmdline}\0" \
	"nandargs=setenv bootargs console=${console} " \
		"${mtdparts} " \
		"${optargs} " \
		"root=ubi0:rootfs rw ubi.mtd=rootfs " \
		"rootfstype=ubifs rootwait " \
		"${cmdline}\0" \
	"loadbootenv=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${bootenv}\0"\
	"importbootenv=echo Importing environment from mmc ...; " \
		"env import -t ${loadaddr} ${filesize}\0" \
	"bootscript=echo Running bootscript from mmc ...; " \
		"source ${loadaddr}\0" \
	"loaduimage=fatload mmc ${mmcdev} ${kloadaddr} uImage\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"bootm ${kloadaddr}; \0" \

#define CONFIG_BOOTCOMMAND \
	"mmc dev ${mmcdev}; if mmc rescan; then " \
		"if run loadbootscript; then " \
			"run bootscript; " \
		"else " \
			"if run loadbootenv; then " \
				"echo Loaded environment from ${bootenv};" \
				"run importbootenv;" \
			"fi;" \
			"if test -n $uenvcmd; then " \
				"echo Running uenvcmd ...;" \
				"run uenvcmd;" \
			"fi;" \
			"if run loaduimage; then " \
				"run mmcboot; " \
			"else run " FLASHBOOT "; " \
			"fi; " \
		"fi; " \
	"else run " FLASHBOOT "; fi"

/* Miscellaneous configurable options */
#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING
#define CONFIG_SYS_LONGHELP

/* We set the max number of command args high to avoid HUSH bugs. */
#define CONFIG_SYS_MAXARGS		64

/* Console I/O Buffer Size */
#define CONFIG_SYS_CBSIZE		512
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE \
					+ sizeof(CONFIG_SYS_PROMPT) + 16)
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE

/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	(OMAP34XX_SDRC_CS0)
#define CONFIG_SYS_MEMTEST_END		(OMAP34XX_SDRC_CS0 + \
					0x01F00000) /* 31MB */

#define CONFIG_SYS_LOAD_ADDR		(OMAP34XX_SDRC_CS0) /* default load */
								/* address */

/*
 * AM3517 has 12 GP timers, they can be driven by the system clock
 * (12/13/16.8/19.2/38.4MHz) or by 32KHz clock. We use 13MHz (V_SCLK).
 * This rate is divided by a local divisor.
 */
#define CONFIG_SYS_TIMERBASE		OMAP34XX_GPT2
#define CONFIG_SYS_PTV			2	/* Divisor: 2^(PTV+1) => 8 */

/* Physical Memory Map */
#define PHYS_SDRAM_1			OMAP34XX_SDRC_CS0
#define PHYS_SDRAM_2			OMAP34XX_SDRC_CS1
#define CONFIG_SYS_CS0_SIZE		(256 * 1024 * 1024)
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_INIT_RAM_ADDR	0x4020f800
#define CONFIG_SYS_INIT_RAM_SIZE	0x800
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
					 CONFIG_SYS_INIT_RAM_SIZE - \
					 GENERATED_GBL_DATA_SIZE)

/* FLASH and environment organization */

/* **** PISMO SUPPORT *** */
#define CONFIG_SYS_MAX_FLASH_SECT	520	/* max number of sectors */
						/* on one chip */
#define CONFIG_SYS_MAX_FLASH_BANKS	2	/* max number of flash banks */
#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* Reserve 2 sectors */

#if defined(CONFIG_NAND)
#define CONFIG_SYS_FLASH_BASE		NAND_BASE
#endif

/* Configure the PISMO */
#define PISMO1_NAND_SIZE		GPMC_SIZE_128M
#define PISMO1_ONEN_SIZE		GPMC_SIZE_128M

/* General */
#define CONFIG_SYS_MAX_FLASH_SECT	512	/* max sectors on one chip */

/*
 * CFI FLASH driver setup.  Please note that, first 4 blocks are of 32K and
 * rest all blocks are 128K.
 */
#if defined (CONFIG_SYS_HAS_NORFLASH)
#define CONFIG_CMD_FLASH			/* flinfo, erase, protect */
#define CONFIG_SYS_FLASH_BASE		DEBUG_BASE
#define CONFIG_SYS_FLASH_CFI			/* use CFI geometry data */
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE 	/* ~10x faster writes */
#define CONFIG_SYS_FLASH_PROTECTION		/* hardware sector protection */
#define CONFIG_SYS_FLASH_EMPTY_INFO		/* flinfo 'E' for empty */
#define CONFIG_SYS_FLASH_BANKS_LIST	{CONFIG_SYS_FLASH_BASE}
#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of flash banks */
#define CONFIG_SYS_FLASH_CFI_WIDTH	2
#define PHYS_FLASH_SIZE			(8 << 20)
/* Monitor at start of flash */
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_FLASH_BASE
#else
/* No support for CFI flash. */
#undef CONFIG_CMD_FLASH
#define CONFIG_SYS_NO_FLASH
#define CONFIG_SYS_MAX_FLASH_BANKS	0
#endif

#define CONFIG_SYS_ENV_SECT_SIZE	(128 << 10)	/* 128 KiB */
#define CONFIG_ENV_SIZE			CONFIG_SYS_ENV_SECT_SIZE
#define SMNAND_ENV_OFFSET		0x260000 /* environment starts here */
#define CONFIG_ENV_OFFSET		SMNAND_ENV_OFFSET
#define CONFIG_ENV_ADDR			SMNAND_ENV_OFFSET
#define CONFIG_ENV_IS_IN_NAND

#define CONFIG_NAND_OMAP_GPMC
#define CONFIG_ENV_IS_IN_NAND		1
#define GPMC_NAND_ECC_LP_x16_LAYOUT	1

/* timeout values are in ticks */
#define CONFIG_SYS_FLASH_ERASE_TOUT	(100 * CONFIG_SYS_HZ)
#define CONFIG_SYS_FLASH_WRITE_TOUT	(100 * CONFIG_SYS_HZ)

/* Flash banks JFFS2 should use */
#define CONFIG_SYS_MAX_MTD_BANKS	(CONFIG_SYS_MAX_FLASH_BANKS + \
					CONFIG_SYS_MAX_NAND_DEVICE)
#define CONFIG_SYS_JFFS2_MEM_NAND
/* use flash_info[2] */
#define CONFIG_SYS_JFFS2_FIRST_BANK	CONFIG_SYS_MAX_FLASH_BANKS
#define CONFIG_SYS_JFFS2_NUM_BANKS	1

/* Environment location */
#ifdef CONFIG_SYS_BOOT_NORFLASH
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OFFSET		0x80000	/* environment starts here */
/* NOR related env and boot */
#define FLASHBOOT			"norboot"
#define CONFIG_EXTRA_ENV_SETTINGS	EXTRA_ENV_SETTINGS \
	"norargs=run bootargs_defaults; " \
		"setenv bootargs ${bootargs} " \
		"root=/dev/mtdblock3 rw " \
		"rootfstype=jffs2\0" \
	"norboot=echo Booting from nor ...; " \
		"run norargs; " \
		"bootm 0x080A0000; \0"
/* JFFS2 */
#define CONFIG_JFFS2_DEV		"nor0"
/* start of jffs2 partition */
#define CONFIG_JFFS2_PART_OFFSET	(CONFIG_SYS_FLASH_BASE + 0x3A0000)
#define CONFIG_JFFS2_PART_SIZE		0x460000	/* sz of jffs2 part */
#else
/* ENV resides in NAND */
#define CONFIG_ENV_IS_IN_NAND
#define SMNAND_ENV_OFFSET		0x260000 /* environment starts here */
#define CONFIG_ENV_OFFSET		SMNAND_ENV_OFFSET
/* NAND related env and boot */
#define FLASHBOOT			"nandboot"
#define CONFIG_EXTRA_ENV_SETTINGS	EXTRA_ENV_SETTINGS \
	"nandargs=run bootargs_defaults; " \
		"setenv bootargs ${bootargs} " \
		"root=/dev/mtdblock4 rw " \
		"rootfstype=jffs2\0" \
	"nandboot=echo Booting from nand ...; " \
		"run nandargs; " \
		"nand read ${kloadaddr} 280000 400000; " \
		"bootm ${kloadaddr}; \0"
/* JFFS2 */
#define CONFIG_JFFS2_NAND
/* nand device jffs2 lives on */
#define CONFIG_JFFS2_DEV		"nand0"
/* start of jffs2 partition */
#define CONFIG_JFFS2_PART_OFFSET	0x680000
#define CONFIG_JFFS2_PART_SIZE		0xf980000	/* sz of jffs2 part */
#endif

/*-----------------------------------------------------
 * ethernet support for AM3517 EVM
 *------------------------------------------------
 */
#if defined(CONFIG_CMD_NET)
#define CONFIG_SYS_DCACHE_OFF		/* Driver not D-CACHE safe */
#define CONFIG_DRIVER_TI_EMAC
#define CONFIG_DRIVER_TI_EMAC_USE_RMII
#define CONFIG_MII
#define CONFIG_EMAC_MDIO_PHY_NUM	0
#define CONFIG_BOOTP_DEFAULT
#define CONFIG_BOOTP_DNS
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_NET_RETRY_COUNT		10
#define CONFIG_NET_MULTI
#endif

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_INIT_RAM_ADDR	0x4020f800
#define CONFIG_SYS_INIT_RAM_SIZE	0x800
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
					 CONFIG_SYS_INIT_RAM_SIZE - \
					 GENERATED_GBL_DATA_SIZE)

/* Defines for SPL */
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_BOARD_INIT
#define CONFIG_SPL_NAND_SIMPLE
#define CONFIG_SPL_TEXT_BASE		0x40200000
#define CONFIG_SPL_MAX_SIZE		(SRAM_SCRATCH_SPACE_ADDR - \
					 CONFIG_SPL_TEXT_BASE)

#define CONFIG_SPL_BSS_START_ADDR	0x80000000
#define CONFIG_SPL_BSS_MAX_SIZE		0x80000		/* 512 KB */

#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION	1
#define CONFIG_SPL_FS_LOAD_PAYLOAD_NAME		"u-boot.img"

#define CONFIG_SPL_NAND_BASE
#define CONFIG_SPL_NAND_DRIVERS
#define CONFIG_SPL_NAND_ECC
#define CONFIG_SPL_LDSCRIPT		"arch/arm/mach-omap2/u-boot-spl.lds"

#endif /* __CONFIG_H */
