################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
build-15037121:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-15037121-inproc

build-15037121-inproc: ../release.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"/Volumes/Storage/shared/imarchenko/ti/ccs1020/xdctools_3_62_00_08_core/xs" --xdcpath="/Volumes/Storage/shared/imarchenko/ti/ccs1020/ccs/utils/simplelink_cc13x2_26x2_sdk_3_30_00_03/source;/Volumes/Storage/shared/imarchenko/ti/ccs1020/ccs/utils/simplelink_cc13x2_26x2_sdk_3_30_00_03/kernel/tirtos/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.simplelink:CC1352 -r release -c "/Volumes/Storage/shared/imarchenko/ti/ccs1020/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS" --compileOptions " -DDeviceFamily_CC13X2 " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-15037121 ../release.cfg
configPkg/compiler.opt: build-15037121
configPkg/: build-15037121


