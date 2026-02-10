#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/app.c ../src/main.c ../src/function_can.c ../src/function_initialization.c ../src/function_math.c ../src/function_spi.c ../src/function_task.c ../src/interrupts.c ../src/param_define.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/function_can.o ${OBJECTDIR}/_ext/1360937237/function_initialization.o ${OBJECTDIR}/_ext/1360937237/function_math.o ${OBJECTDIR}/_ext/1360937237/function_spi.o ${OBJECTDIR}/_ext/1360937237/function_task.o ${OBJECTDIR}/_ext/1360937237/interrupts.o ${OBJECTDIR}/_ext/1360937237/param_define.o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d ${OBJECTDIR}/_ext/1688732426/system_init.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/function_can.o.d ${OBJECTDIR}/_ext/1360937237/function_initialization.o.d ${OBJECTDIR}/_ext/1360937237/function_math.o.d ${OBJECTDIR}/_ext/1360937237/function_spi.o.d ${OBJECTDIR}/_ext/1360937237/function_task.o.d ${OBJECTDIR}/_ext/1360937237/interrupts.o.d ${OBJECTDIR}/_ext/1360937237/param_define.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/function_can.o ${OBJECTDIR}/_ext/1360937237/function_initialization.o ${OBJECTDIR}/_ext/1360937237/function_math.o ${OBJECTDIR}/_ext/1360937237/function_spi.o ${OBJECTDIR}/_ext/1360937237/function_task.o ${OBJECTDIR}/_ext/1360937237/interrupts.o ${OBJECTDIR}/_ext/1360937237/param_define.o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o

# Source Files
SOURCEFILES=../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/app.c ../src/main.c ../src/function_can.c ../src/function_initialization.c ../src/function_math.c ../src/function_spi.c ../src/function_task.c ../src/interrupts.c ../src/param_define.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFH100
MP_LINKER_FILE_OPTION=,--script="..\myscript___100.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  .generated_files/flags/default/9c8130cb283c8d1a9fe2a2fd405cf839b1d7768f .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S  .generated_files/flags/default/453ba909acf4d1538b7129f319ffe0d43712bd67 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.ok ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d"  -o ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1 
	@${FIXDEPS} "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d" "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  .generated_files/flags/default/479716fe04a7ffcff5d09cb83e1ecac747f32421 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d",--gdwarf-2 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S  .generated_files/flags/default/f5d72b70d25cab2239793a8b684c40194655ff97 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.ok ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d"  -o ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.asm.d",--gdwarf-2 
	@${FIXDEPS} "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d" "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c  .generated_files/flags/default/9270605a3dc4e00389d2fd84322b95d3ba24773d .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/eea8916f7e02b0a39f356b5d93c6027bf8d411f2 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c  .generated_files/flags/default/d807d4bb7de847609a1b7d854f1bd0f9f94d0ed3 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/93556cb8bdbab00534ea5e582354e4281e8b165a .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/7b8f3777af8809943d4816a08a134e37b7d2bf8a .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/952e4fdf1a5a442883eeb5710e4e7b72c7f2da44 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/25d8b10162bffd00588c955f0f01b97d2465269b .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/de12cfba067ef5b417d26b8048cc5c6f53373b76 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/f47337b42cf82c329a93b22597f2c2c67a1a9903 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/15c6cc536ced059fc8c53764ec3a9823cd9f9684 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_can.o: ../src/function_can.c  .generated_files/flags/default/ca021df8ecbd2b91f032ecf6ab19bfad1d56aa40 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_can.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_can.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_can.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_can.o ../src/function_can.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_initialization.o: ../src/function_initialization.c  .generated_files/flags/default/684e6218807db458cf511c4bd1bfdd8134b296df .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_initialization.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_initialization.o ../src/function_initialization.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_math.o: ../src/function_math.c  .generated_files/flags/default/653d995015b6038b5a525ea1111db8c0d97c2ba4 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_math.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_math.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_math.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_math.o ../src/function_math.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_spi.o: ../src/function_spi.c  .generated_files/flags/default/3a3bdf842c3f5944ed0ab99b8506b9aa2031fdd6 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_spi.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_spi.o ../src/function_spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_task.o: ../src/function_task.c  .generated_files/flags/default/13ade9ec73fd072fd701aee595c92e0adbc9204f .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_task.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_task.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_task.o ../src/function_task.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/interrupts.o: ../src/interrupts.c  .generated_files/flags/default/4c233db571a7f8a795cb44aff9ab0cedf325c991 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/interrupts.o.d" -o ${OBJECTDIR}/_ext/1360937237/interrupts.o ../src/interrupts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/param_define.o: ../src/param_define.c  .generated_files/flags/default/b8944678ae7bcae3ebde0a066af29674623db571 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/param_define.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/param_define.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/param_define.o.d" -o ${OBJECTDIR}/_ext/1360937237/param_define.o ../src/param_define.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c  .generated_files/flags/default/e35a4316036460c5c9cb151449e13a08c3f709bb .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c  .generated_files/flags/default/af48fe58650665034e5199ee1f0823a9e0c3b224 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c  .generated_files/flags/default/54276ea87d26243558d0c44d2b2343061d3c6cee .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c  .generated_files/flags/default/7fd9386ecb17ec6dcd43a5bbaba5eddaa2614e7f .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c  .generated_files/flags/default/2bd92ffc989ca669676eb76557bacd9eaec59579 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c  .generated_files/flags/default/421ff1727f38fdbbd09251ce9d8eaf20d5837ccf .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c  .generated_files/flags/default/9e2f282c359dbbe8d68f7b24e21e6650199b3fda .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c  .generated_files/flags/default/ae2e42bd3ea334438eb98819f345013e46a66be3 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c  .generated_files/flags/default/b865e43acdb63925f5410dd72e52fdef94c96af0 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/62e7608f94e17cdfc12bc1fb3bff4e713dcb993c .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1872847683" 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
else
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c  .generated_files/flags/default/b0eb1a43297cf0ac44cbcc0de400e42b367c19b3 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/65d76a314ac5a1ee013b8125875238bd117468d2 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c  .generated_files/flags/default/418d0d8cc4ef1d0f2e3b8b43199cc0434fa4000a .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/dffd69fa1e1548d08e1fef8cd82f39d57188ac55 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/7cdcee994583c5aa48a083d7fc0df851b9c5384c .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/76dca96e114d55551c13e3c236e95d9725386f21 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/eae48e9780a4d8b61941f604f8e1542f66b32ca9 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/e7c9658ed6c3faceb6cb23f96c9a112210c20720 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/d8a6d04d2346947ba7b0757658f1837628ab0a35 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/39d58b242aeec453a2dd86ee42c0acc14a670e6e .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_can.o: ../src/function_can.c  .generated_files/flags/default/1c449c68c43ada4be275d681aba3709825061172 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_can.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_can.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_can.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_can.o ../src/function_can.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_initialization.o: ../src/function_initialization.c  .generated_files/flags/default/82d2dfd4a647b825058d89ee2f35fc88ca5f937b .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_initialization.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_initialization.o ../src/function_initialization.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_math.o: ../src/function_math.c  .generated_files/flags/default/cac84218b2ca18fdc8f91cc465cc4184c62eb3bd .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_math.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_math.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_math.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_math.o ../src/function_math.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_spi.o: ../src/function_spi.c  .generated_files/flags/default/4d951094fd984e8af9aef1e8e19cff2a27f96245 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_spi.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_spi.o ../src/function_spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_task.o: ../src/function_task.c  .generated_files/flags/default/ff800c11ba5dea7b1c61cf34d2fbe4c23675aede .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_task.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_task.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_task.o ../src/function_task.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/interrupts.o: ../src/interrupts.c  .generated_files/flags/default/1ab7b0279da343aa65a20e0e451f37ac4e8c61cb .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/interrupts.o.d" -o ${OBJECTDIR}/_ext/1360937237/interrupts.o ../src/interrupts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/param_define.o: ../src/param_define.c  .generated_files/flags/default/2d5e6438ec32aba1c3a049cca20f01bfb9305153 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/param_define.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/param_define.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/param_define.o.d" -o ${OBJECTDIR}/_ext/1360937237/param_define.o ../src/param_define.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c  .generated_files/flags/default/f41eae8832f1cc5ff4490e51ce186e5b87f7aa9b .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c  .generated_files/flags/default/8f2076967140bb9043821f1300e3ecd6a3461430 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c  .generated_files/flags/default/2177eff63f738563fff0cd369d27232730451a77 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c  .generated_files/flags/default/298909abded4a9126da46f4ba6b82be7e5084a5 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c  .generated_files/flags/default/bad5f4da643caf9bc34f5bedab9f20767f4bf1e5 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c  .generated_files/flags/default/a41a641f55575dcf2a55165d7f28e2e45b9ac306 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c  .generated_files/flags/default/79c70397c69abec59d1ecae1b1247423ad03be3e .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c  .generated_files/flags/default/676c12c2b6f9c31ba20e856fb6a622986cfeaf47 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c  .generated_files/flags/default/b78b3169ba0deeeb651f4545fb4d6f839f1ade0c .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/6a99bcdbf060ebea68d32c3a89ac95dfcdbd30a4 .generated_files/flags/default/b9a611e7d3f9e13f36a974aabff414fb1e968c
	@${MKDIR} "${OBJECTDIR}/_ext/1872847683" 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MZ2048EFH100_peripherals.a  ../myscript___100.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\..\..\microchip\harmony\v2_06\bin\framework\peripheral\PIC32MZ2048EFH100_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=0,--defsym=_min_stack_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MZ2048EFH100_peripherals.a ../myscript___100.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\..\..\microchip\harmony\v2_06\bin\framework\peripheral\PIC32MZ2048EFH100_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--defsym=_min_stack_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
