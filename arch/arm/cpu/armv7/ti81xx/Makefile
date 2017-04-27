#
# Copyright (C) 2009, Texas Instruments, Incorporated
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation version 2.
#
# This program is distributed "as is" WITHOUT ANY WARRANTY of any
# kind, whether express or implied; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#

include $(TOPDIR)/config.mk

LIB	= $(obj)lib$(SOC).o

obj-y	+= cache.o

obj-y	+= mem.o
obj-y	+= sys_info.o

obj-$(CONFIG_NAND_TI81XX)	+= elm.o
