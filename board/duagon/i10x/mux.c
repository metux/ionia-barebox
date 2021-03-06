/*
 * mux.c
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <common.h>
#include <config.h>
#include <asm/io.h>
#include "common_def.h"
#include <asm/arch/hardware.h>

#define MUX_CFG(value, offset)  \
    writel(value, (CTRL_BASE + offset));

/* PAD Control Fields */
/* Settings with (0<<shiftval) are for readability */
#define SLEW_FAST   (0x0 << 6) /* Slew rate: fast */
#define SLEW_SLOW   (0x1 << 6) /* Slew rate: slow */

#define RX_ENABLE   (0x1 << 5) /* Rx enabled */
#define RX_DISABLE  (0x0 << 5) /* Rx disabled */

#define PULLUP_SEL  (0x1 << 4) /* Pull up Selection */
#define PULLDN_SEL  (0x0 << 4) /* Pull dn Selection */

#define PULLUD_EN   (0x0 << 3) /* Pull up/dn enabled */
#define PULLUD_DIS  (0x1 << 3) /* Pull up/dn disabled */

#define MODE(val)   val

/*
 * PAD CONTROL OFFSETS
 * Field names corresponds to the pad signal name
 */
struct pad_signals {
    int gpmc_ad0;
    int gpmc_ad1;
    int gpmc_ad2;
    int gpmc_ad3;
    int gpmc_ad4;
    int gpmc_ad5;
    int gpmc_ad6;
    int gpmc_ad7;
    int gpmc_ad8;
    int gpmc_ad9;
    int gpmc_ad10;
    int gpmc_ad11;
    int gpmc_ad12;
    int gpmc_ad13;
    int gpmc_ad14;
    int gpmc_ad15;
    int gpmc_a0;
    int gpmc_a1;
    int gpmc_a2;
    int gpmc_a3;
    int gpmc_a4;
    int gpmc_a5;
    int gpmc_a6;
    int gpmc_a7;
    int gpmc_a8;
    int gpmc_a9;
    int gpmc_a10;
    int gpmc_a11;
    int gpmc_wait0;
    int gpmc_wpn;
    int gpmc_be1n;
    int gpmc_csn0;
    int gpmc_csn1;
    int gpmc_csn2;
    int gpmc_csn3;
    int gpmc_clk;
    int gpmc_advn_ale;
    int gpmc_oen_ren;
    int gpmc_wen;
    int gpmc_be0n_cle;
    int lcd_data0;
    int lcd_data1;
    int lcd_data2;
    int lcd_data3;
    int lcd_data4;
    int lcd_data5;
    int lcd_data6;
    int lcd_data7;
    int lcd_data8;
    int lcd_data9;
    int lcd_data10;
    int lcd_data11;
    int lcd_data12;
    int lcd_data13;
    int lcd_data14;
    int lcd_data15;
    int lcd_vsync;
    int lcd_hsync;
    int lcd_pclk;
    int lcd_ac_bias_en;
    int mmc0_dat3;
    int mmc0_dat2;
    int mmc0_dat1;
    int mmc0_dat0;
    int mmc0_clk;
    int mmc0_cmd;
    int mii1_col;
    int mii1_crs;
    int mii1_rxerr;
    int mii1_txen;
    int mii1_rxdv;
    int mii1_txd3;
    int mii1_txd2;
    int mii1_txd1;
    int mii1_txd0;
    int mii1_txclk;
    int mii1_rxclk;
    int mii1_rxd3;
    int mii1_rxd2;
    int mii1_rxd1;
    int mii1_rxd0;
    int rmii1_refclk;
    int mdio_data;
    int mdio_clk;
    int spi0_sclk;
    int spi0_d0;
    int spi0_d1;
    int spi0_cs0;
    int spi0_cs1;
    int ecap0_in_pwm0_out;
    int uart0_ctsn;
    int uart0_rtsn;
    int uart0_rxd;
    int uart0_txd;
    int uart1_ctsn;
    int uart1_rtsn;
    int uart1_rxd;
    int uart1_txd;
    int i2c0_sda;
    int i2c0_scl;
    int mcasp0_aclkx;
    int mcasp0_fsx;
    int mcasp0_axr0;
    int mcasp0_ahclkr;
    int mcasp0_aclkr;
    int mcasp0_fsr;
    int mcasp0_axr1;
    int mcasp0_ahclkx;
    int xdma_event_intr0;
    int xdma_event_intr1;
    int nresetin_out;
    int porz;
    int nnmi;
    int osc0_in;
    int osc0_out;
    int rsvd1;
    int tms;
    int tdi;
    int tdo;
    int tck;
    int ntrst;
    int emu0;
    int emu1;
    int osc1_in;
    int osc1_out;
    int pmic_power_en;
    int rtc_porz;
    int rsvd2;
    int ext_wakeup;
    int enz_kaldo_1p8v;
    int usb0_dm;
    int usb0_dp;
    int usb0_ce;
    int usb0_id;
    int usb0_vbus;
    int usb0_drvvbus;
    int usb1_dm;
    int usb1_dp;
    int usb1_ce;
    int usb1_id;
    int usb1_vbus;
    int usb1_drvvbus;
    int ddr_resetn;
    int ddr_csn0;
    int ddr_cke;
    int ddr_ck;
    int ddr_nck;
    int ddr_casn;
    int ddr_rasn;
    int ddr_wen;
    int ddr_ba0;
    int ddr_ba1;
    int ddr_ba2;
    int ddr_a0;
    int ddr_a1;
    int ddr_a2;
    int ddr_a3;
    int ddr_a4;
    int ddr_a5;
    int ddr_a6;
    int ddr_a7;
    int ddr_a8;
    int ddr_a9;
    int ddr_a10;
    int ddr_a11;
    int ddr_a12;
    int ddr_a13;
    int ddr_a14;
    int ddr_a15;
    int ddr_odt;
    int ddr_d0;
    int ddr_d1;
    int ddr_d2;
    int ddr_d3;
    int ddr_d4;
    int ddr_d5;
    int ddr_d6;
    int ddr_d7;
    int ddr_d8;
    int ddr_d9;
    int ddr_d10;
    int ddr_d11;
    int ddr_d12;
    int ddr_d13;
    int ddr_d14;
    int ddr_d15;
    int ddr_dqm0;
    int ddr_dqm1;
    int ddr_dqs0;
    int ddr_dqsn0;
    int ddr_dqs1;
    int ddr_dqsn1;
    int ddr_vref;
    int ddr_vtp;
    int ddr_strben0;
    int ddr_strben1;
    int ain7;
    int ain6;
    int ain5;
    int ain4;
    int ain3;
    int ain2;
    int ain1;
    int ain0;
    int vrefp;
    int vrefn;
};

struct module_pin_mux {
    short reg_offset;
    unsigned char val;
};

struct evm_pin_mux {
    struct module_pin_mux *mod_pin_mux;
    unsigned short profile;

/*
* If the device is required on both baseboard & daughter board (ex i2c),
* specify DEV_ON_BASEBOARD
*/
#define DEV_ON_BASEBOARD       0
#define DEV_ON_DGHTR_BRD       1
    unsigned short device_on;
};

#define PAD_CTRL_BASE   0x800
#define OFFSET(x)   (unsigned int) (&((struct pad_signals *) \
                (PAD_CTRL_BASE))->x)

/* UART0 Pinmux settings */
static struct module_pin_mux uart0_pin_mux[] = {
    {OFFSET(uart0_rxd),  (MODE(0) | SLEW_SLOW | RX_ENABLE | PULLDN_SEL | PULLUD_EN)},  /* UART0_RXD */
    {OFFSET(uart0_txd),  (MODE(0) | SLEW_SLOW | RX_DISABLE| PULLDN_SEL | PULLUD_EN)},  /* UART0_TXD */
    {OFFSET(uart0_ctsn), (MODE(0) | SLEW_SLOW | RX_ENABLE | PULLDN_SEL | PULLUD_EN)},  /* UART0_CTSN */
    {OFFSET(uart0_rtsn), (MODE(0) | SLEW_SLOW | RX_DISABLE| PULLDN_SEL | PULLUD_EN)},  /* UART0_RTSN */
    {-1},
};

static struct module_pin_mux gpmc_pin_mux[] = {
  {OFFSET(gpmc_ad0), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD0  */
  {OFFSET(gpmc_ad1), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD1  */
  {OFFSET(gpmc_ad2), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD2  */
  {OFFSET(gpmc_ad3), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD3  */
  {OFFSET(gpmc_ad4), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD4  */
  {OFFSET(gpmc_ad5), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD5  */
  {OFFSET(gpmc_ad6), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD6  */
  {OFFSET(gpmc_ad7), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD7  */
  {OFFSET(gpmc_ad8), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD8  */
  {OFFSET(gpmc_ad9), (MODE(0)  | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD9  */
  {OFFSET(gpmc_ad10), (MODE(0) | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD10 */
  {OFFSET(gpmc_ad11), (MODE(0) | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD11 */
  {OFFSET(gpmc_ad12), (MODE(0) | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD12 */
  {OFFSET(gpmc_ad13), (MODE(0) | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD13 */
  {OFFSET(gpmc_ad14), (MODE(0) | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD14 */
  {OFFSET(gpmc_ad15), (MODE(0) | SLEW_FAST |  RX_ENABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC AD15 */
  {OFFSET(gpmc_a0), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A0  */
  {OFFSET(gpmc_a1), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A1  */
  {OFFSET(gpmc_a2), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A2  */
  {OFFSET(gpmc_a3), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A3  */
  {OFFSET(gpmc_a4), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A4  */
  {OFFSET(gpmc_a5), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A5  */
  {OFFSET(gpmc_a6), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A6  */
  {OFFSET(gpmc_a7), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A7  */
  {OFFSET(gpmc_a8), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A8  */
  {OFFSET(gpmc_a9), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},  /* GPMC A9  */
  {OFFSET(gpmc_a10), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)}, /* GPMC A10 */
  {OFFSET(gpmc_a11),   (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLDN_SEL | PULLUD_EN)},   /* GPMC A11 */
  {OFFSET(gpmc_wait0), (MODE(0) | SLEW_FAST |  RX_ENABLE  | PULLUP_SEL | PULLUD_EN)},   /* GPMC WAIT0 */
  {OFFSET(gpmc_wpn),   (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},   /* GPMC_WPN */
  {OFFSET(gpmc_be1n),  (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},   /* GPMC_BE1n */
  {OFFSET(gpmc_csn0),  (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},   /* GPMC_CS0 */
  {OFFSET(gpmc_csn1),  (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},   /* GPMC_CS1 */
  {OFFSET(gpmc_csn2),  (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},   /* GPMC_CS2 */
  {OFFSET(gpmc_csn3),  (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},   /* GPMC_CS3 */
  {OFFSET(gpmc_clk),   (MODE(0) | SLEW_FAST |  RX_ENABLE | PULLUP_SEL | PULLUD_EN)},    /* GPMC_CLK */
  {OFFSET(gpmc_advn_ale), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)}, /* GPMC_ADV_ALE */
  {OFFSET(gpmc_oen_ren),  (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},    /* GPMC_OEn_REn */
  {OFFSET(gpmc_wen),      (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},    /* GPMC_WEn */
  {OFFSET(gpmc_be0n_cle), (MODE(0) | SLEW_FAST |  RX_DISABLE | PULLUP_SEL | PULLUD_EN)},    /* GPMC_BE0n_CLE */
  {-1},
};

static struct module_pin_mux DBG_LED_CPU_pin_mux[] = {
  {OFFSET(lcd_pclk), (MODE(7) | SLEW_FAST | RX_DISABLE | PULLDN_SEL | PULLUD_DIS )},    /* DBG_LED_CPU  */
  {-1},
};

static struct module_pin_mux SYSBOOT_pin_mux[] = {
  {OFFSET(lcd_data6), (MODE(7) | RX_ENABLE | PULLUD_DIS )}, /* MII/RMII config pins  */
  {OFFSET(lcd_data7), (MODE(7) | RX_ENABLE | PULLUD_DIS )}, /* MII/RMII config pins  */
  {-1},
};

static struct module_pin_mux __attribute__((section (".data"))) i2c0_pin_mux[] = {
    {OFFSET(i2c0_sda), (MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN )},    /* I2C_DATA */
    {OFFSET(i2c0_scl), (MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN )},    /* I2C_SCLK */
    {-1},
};


#ifndef CONFIG_NO_ETH
static struct module_pin_mux mii1_pin_mux[] = {
  {OFFSET(mii1_col),   MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_COL */
  {OFFSET(mii1_crs),   MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_COL */
  {OFFSET(mii1_rxerr), MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_RXERR */
  {OFFSET(mii1_txen),  MODE(0) | SLEW_FAST | RX_DISABLE| PULLDN_SEL | PULLUD_EN },  /* MII1_TXEN */
  {OFFSET(mii1_rxdv),  MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_RXDV */
  {OFFSET(mii1_txd3),  MODE(0) | SLEW_FAST | RX_DISABLE| PULLDN_SEL | PULLUD_EN },  /* MII1_TXD3 */
  {OFFSET(mii1_txd2),  MODE(0) | SLEW_FAST | RX_DISABLE| PULLDN_SEL | PULLUD_EN },  /* MII1_TXD2 */
  {OFFSET(mii1_txd1),  MODE(0) | SLEW_FAST | RX_DISABLE| PULLDN_SEL | PULLUD_EN },  /* MII1_TXD1 */
  {OFFSET(mii1_txd0),  MODE(0) | SLEW_FAST | RX_DISABLE| PULLDN_SEL | PULLUD_EN },  /* MII1_TXD0 */
  {OFFSET(mii1_txclk), MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_TXCLK */
  {OFFSET(mii1_rxclk), MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_RXCLK */
  {OFFSET(mii1_rxd3),  MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_RXD3 */
  {OFFSET(mii1_rxd2),  MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_RXD2 */
  {OFFSET(mii1_rxd1),  MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_RXD1 */
  {OFFSET(mii1_rxd0),  MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_EN },  /* MII1_RXD0 */
  {OFFSET(mdio_data),  MODE(0) | SLEW_FAST | RX_ENABLE | PULLUP_SEL | PULLUD_EN },  /* MDIO_DATA */
  {OFFSET(mdio_clk),   MODE(0) | SLEW_FAST | RX_DISABLE| PULLUP_SEL | PULLUD_EN },  /* MDIO_CLK */
  {-1},
};

static struct module_pin_mux rmii1_pin_mux[] = {
  {OFFSET(mii1_crs),     MODE(1) | SLEW_FAST | RX_ENABLE | PULLDN_SEL| PULLUD_EN}, /* RMII1_CRS */
  {OFFSET(mii1_rxerr),   MODE(1) | SLEW_FAST | RX_ENABLE | PULLDN_SEL| PULLUD_EN}, /* RMII1_RXERR */
  {OFFSET(mii1_txen),    MODE(1) | SLEW_FAST | RX_DISABLE| PULLDN_SEL| PULLUD_EN}, /* RMII1_TXEN */
  {OFFSET(mii1_txd1),    MODE(1) | SLEW_FAST | RX_DISABLE| PULLDN_SEL| PULLUD_EN}, /* RMII1_TXD1 */
  {OFFSET(mii1_txd0),    MODE(1) | SLEW_FAST | RX_DISABLE| PULLDN_SEL| PULLUD_EN}, /* RMII1_TXD0 */
  {OFFSET(mii1_rxd1),    MODE(1) | SLEW_FAST | RX_ENABLE | PULLDN_SEL| PULLUD_EN}, /* RMII1_RXD1 */
  {OFFSET(mii1_rxd0),    MODE(1) | SLEW_FAST | RX_ENABLE | PULLDN_SEL| PULLUD_EN}, /* RMII1_RXD0 */
  {OFFSET(mdio_data),    MODE(0) | SLEW_FAST | RX_ENABLE | PULLUP_SEL| PULLUD_EN}, /* MDIO_DATA */
  {OFFSET(mdio_clk),     MODE(0) | SLEW_FAST | RX_DISABLE| PULLUP_SEL| PULLUD_EN}, /* MDIO_CLK */
  {OFFSET(rmii1_refclk), MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL| PULLUD_EN}, /* RMII1_REFCLK */
  {-1},
};
#endif

#ifdef CONFIG_SPI
/* SPI0 Pinmux settings */
static struct module_pin_mux spi0_pin_mux[] = {
    {OFFSET(spi0_sclk), MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_DIS }, /*SPI0_SCLK */
    {OFFSET(spi0_d0),   MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_DIS }, /*SPI0_D0 */
    {OFFSET(spi0_d1),   MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_DIS }, /*SPI0_D1 */
    {OFFSET(spi0_cs0),  MODE(0) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_DIS }, /*SPI0_CS0 */
    {OFFSET(spi0_cs1),  MODE(7) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_DIS }, /*SPI0_CS1 */
    {OFFSET(ecap0_in_pwm0_out), MODE(7) | SLEW_FAST | RX_ENABLE | PULLDN_SEL | PULLUD_DIS }, 
    {-1},
};
#endif

static struct evm_pin_mux i10x_base_pin_mux[] = {
    {uart0_pin_mux, PROFILE_ALL, DEV_ON_BASEBOARD},
    {gpmc_pin_mux, PROFILE_ALL, DEV_ON_BASEBOARD},
    {DBG_LED_CPU_pin_mux, PROFILE_ALL, DEV_ON_BASEBOARD},
#ifdef CONFIG_SPI
    {spi0_pin_mux, PROFILE_ALL, DEV_ON_BASEBOARD},
#endif
    {0},
};

#ifndef CONFIG_NO_ETH
static struct evm_pin_mux i10x_rmii_base_pin_mux[] =
{
    {rmii1_pin_mux, PROFILE_ALL, DEV_ON_BASEBOARD},
    {0},
};

static struct evm_pin_mux i10x_mii_base_pin_mux[] =
{
    {mii1_pin_mux, PROFILE_ALL, DEV_ON_BASEBOARD},
    {0},
};

static struct evm_pin_mux *i10x_mii_pin_mux[] = {
    i10x_mii_base_pin_mux,
};

static struct evm_pin_mux *i10x_rmii_pin_mux[] = {
    i10x_rmii_base_pin_mux,
};
#endif

static struct evm_pin_mux *i10x_pin_mux[] = {
    i10x_base_pin_mux,
};

/*
 * Configure the pin mux for the module
 */
static void configure_module_pin_mux(struct module_pin_mux *mod_pin_mux)
{
    int i = 0;

    if (!mod_pin_mux)
    {
        return;
    }
    debug("configure_module_pin_mux()\n");

    for (i = 0; mod_pin_mux[i].reg_offset != -1; i++){
        MUX_CFG(mod_pin_mux[i].val, mod_pin_mux[i].reg_offset);
        debug("%d, Off = 0x%04X, Val = 0x%08X\n", i, mod_pin_mux[i].reg_offset, mod_pin_mux[i].val);
    }
}


/*
 * Check each module in the daughter board(first argument) whether it is
 * available in the selected profile(second argument). If the module is not
 * available in the selected profile, skip the corresponding configuration.
 */
static void set_evm_pin_mux(struct evm_pin_mux *pin_mux,
            int prof, unsigned int dghtr_brd_flg)
{
    int i = 0;

    if (!pin_mux){
        printf("set_evm_pin_mux() - Error\n");
        return;
    }

    /* Configure pin mux */
    for (i = 0; pin_mux[i].mod_pin_mux != 0; i++)  {
      configure_module_pin_mux(pin_mux[i].mod_pin_mux);
    }
}

void configure_evm_pin_mux(unsigned char dghtr_brd_id, char version[4], unsigned short
        profile, unsigned int daughter_board_flag)
{
    /* At the moment the arguments are ignored as only one board and one profile exist */
    set_evm_pin_mux(i10x_pin_mux[0], profile, daughter_board_flag);
}

void configure_i10x_mii_pin_mux(unsigned char dghtr_brd_id, char version[4], unsigned short
        profile, unsigned int daughter_board_flag)
{
    /* At the moment the arguments are ignored as only one board and one profile exist */
    set_evm_pin_mux(i10x_mii_pin_mux[0], profile, daughter_board_flag);
}

void configure_i10x_rmii_pin_mux(unsigned char dghtr_brd_id, char version[4], unsigned short
        profile, unsigned int daughter_board_flag)
{
    /* At the moment the arguments are ignored as only one board and one profile exist */
    set_evm_pin_mux(i10x_rmii_pin_mux[0], profile, daughter_board_flag);
}

void enable_i2c0_pin_mux(void)
{
    configure_module_pin_mux(i2c0_pin_mux);
}

void enable_uart0_pin_mux(void)
{
    configure_module_pin_mux(uart0_pin_mux);
}

void enable_DBG_LED_CPU_pin_mux(void)
{
    configure_module_pin_mux(DBG_LED_CPU_pin_mux);
}

void enable_SYSBOOT_pin_mux(void)
{
    configure_module_pin_mux(SYSBOOT_pin_mux);
}

/*
void enable_gpio0_7_pin_mux(void)
{
    configure_module_pin_mux(gpio0_7_pin_mux);
}
*/
