#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /Volumes/Storage/shared/imarchenko/ti/ccs1020/ccs/utils/simplelink_cc13x2_26x2_sdk_4_40_04_04/source;/Volumes/Storage/shared/imarchenko/ti/ccs1020/ccs/utils/simplelink_cc13x2_26x2_sdk_4_40_04_04/kernel/tirtos/packages
override XDCROOT = /Volumes/Storage/shared/imarchenko/ti/ccs1020/xdctools_3_62_00_08_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /Volumes/Storage/shared/imarchenko/ti/ccs1020/ccs/utils/simplelink_cc13x2_26x2_sdk_4_40_04_04/source;/Volumes/Storage/shared/imarchenko/ti/ccs1020/ccs/utils/simplelink_cc13x2_26x2_sdk_4_40_04_04/kernel/tirtos/packages;/Volumes/Storage/shared/imarchenko/ti/ccs1020/xdctools_3_62_00_08_core/packages;..
HOSTOS = MacOS
endif
