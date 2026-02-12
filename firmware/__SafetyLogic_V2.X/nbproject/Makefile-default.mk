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
FINAL_IMAGE=${DISTDIR}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  .generated_files/flags/default/cf5c0b3d9d1b5d30e486f6d18f1bc47c8b6c5aa1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD4=1 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S  .generated_files/flags/default/edd60ba9bfd9a25b23a08e668cf3a11ed531e844 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.ok ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d"  -o ${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD4=1 
	@${FIXDEPS} "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.d" "${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  .generated_files/flags/default/e7075f145018724ee0725046db3d30b2bb1a057f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d",--gdwarf-2 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/531344610/CLASSB_CPURegistersTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPURegistersTest.S  .generated_files/flags/default/f5d72b70d25cab2239793a8b684c40194655ff97 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
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
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c  .generated_files/flags/default/aea9dd5234d8f150cd7b4771bd6de94c5b575374 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/f23636a09cc7153bda4c1c46dd6916f3979962b6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c  .generated_files/flags/default/a98aa76c0fc98f0808be311207d68400b0c742f2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/14d31f2e4be16baeecb19f4f309dce9fdc55931 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/7a3d378d6fa35cfeee097966a0b0ed9ddd7ad3c4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/19f423426a407e8294ca95c085f1a88c01c1667f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/369a72cc49b2d637d65044604ba50a8b3ffd79ac .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/5ac6731b8540873188228c234ce40c4113461e48 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/39a0d042eb5fc0d0abcb334e421786af0212bc39 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/ed3581eba550c349e315318f47da6c0450011009 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_can.o: ../src/function_can.c  .generated_files/flags/default/c5d33c0044402aa0cb803dbf9f395bfa44432a7b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_can.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_can.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_can.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_can.o ../src/function_can.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_initialization.o: ../src/function_initialization.c  .generated_files/flags/default/c4438052223a155041f65f0d9e20dc4a23e0c84f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_initialization.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_initialization.o ../src/function_initialization.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_math.o: ../src/function_math.c  .generated_files/flags/default/716d5ad8f0348e1563791a0bdac706947333eac6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_math.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_math.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_math.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_math.o ../src/function_math.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_spi.o: ../src/function_spi.c  .generated_files/flags/default/5e418bdfbb014d1448428cc9498cae607c2a7859 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_spi.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_spi.o ../src/function_spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_task.o: ../src/function_task.c  .generated_files/flags/default/b2138125d825f06f90ef7b6a47a5c93de4415a17 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_task.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_task.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_task.o ../src/function_task.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/interrupts.o: ../src/interrupts.c  .generated_files/flags/default/ade822095e257f233c8eef9aa7e4de1f480f83cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/interrupts.o.d" -o ${OBJECTDIR}/_ext/1360937237/interrupts.o ../src/interrupts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/param_define.o: ../src/param_define.c  .generated_files/flags/default/e81959c8c3249e2f8edd678d3250c608206cbb6c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/param_define.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/param_define.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/param_define.o.d" -o ${OBJECTDIR}/_ext/1360937237/param_define.o ../src/param_define.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c  .generated_files/flags/default/aced2d559271301622f7baec52e40e619d3db782 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c  .generated_files/flags/default/415dfcf0d970fc84c6811c7af9977b7255db77db .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c  .generated_files/flags/default/f7212bcfa429e0c1e09f16f28e3ad575a3711a81 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c  .generated_files/flags/default/e8590c64897a59d75711d21ac21de46b09775de9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c  .generated_files/flags/default/273782427461481c1d02bf31d6d82a286e38848 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c  .generated_files/flags/default/924f8d5c7327cdb54a6b28a1e63fcb6641ca535 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c  .generated_files/flags/default/74df62d91ebfbe59d4b1674ed4a7513e6863c186 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c  .generated_files/flags/default/d2cacaac30c7f0fc0ff156f878d6107f907506fe .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c  .generated_files/flags/default/6aa3b548754f1710dcc0d3a32e930a4a30b4858e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/9b70c5a8d8250e038489abf7c5ef89a68b2f25bf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1872847683" 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
else
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c  .generated_files/flags/default/46f4e64d3515d509d81d8f12e48d5617bd66bd23 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/83cd61fd98d939543f566cd85d418f97c828a535 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c  .generated_files/flags/default/8de5f56ff1945c8fbf6af54b342f3d05a1fd0d6c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/fa69ab76ff6a745ade8d0572ac6a4a2f1f0ee2e5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/d010b93d1031f7da063eeb73b84a143dce176537 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/2a24b8782284a45270d1fa2329265d29dbcf8732 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/ee6366dfe6e8c433d540df00a1d8fa2227e36978 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/7c8643b84a0f53d82011c4d3a697abeb93de7323 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/a4a22af389aab9a84ba825d53e6e26cf13b6f1e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/40e3f5092810526f73f082524499176f9e54d89e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_can.o: ../src/function_can.c  .generated_files/flags/default/683185bd590cdee61e5abbb23d22e4edfbce0e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_can.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_can.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_can.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_can.o ../src/function_can.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_initialization.o: ../src/function_initialization.c  .generated_files/flags/default/c37d72ebe0ab2f635236872b04273f530755ade1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_initialization.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_initialization.o ../src/function_initialization.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_math.o: ../src/function_math.c  .generated_files/flags/default/f572210f38df4a246d0d9dbd222b8c453c61c613 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_math.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_math.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_math.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_math.o ../src/function_math.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_spi.o: ../src/function_spi.c  .generated_files/flags/default/780badfced33f503d52fd2683ea4c085475e4c34 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_spi.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_spi.o ../src/function_spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/function_task.o: ../src/function_task.c  .generated_files/flags/default/f5ab420ee5df4058a567a137e31d22f9e8d92e8c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/function_task.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/function_task.o.d" -o ${OBJECTDIR}/_ext/1360937237/function_task.o ../src/function_task.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/interrupts.o: ../src/interrupts.c  .generated_files/flags/default/a4521076328a8dfba7570d0b9d91ae431a359c23 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/interrupts.o.d" -o ${OBJECTDIR}/_ext/1360937237/interrupts.o ../src/interrupts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1360937237/param_define.o: ../src/param_define.c  .generated_files/flags/default/64539576770facbb7cc8de4afb3c56be90ae778 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/param_define.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/param_define.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/param_define.o.d" -o ${OBJECTDIR}/_ext/1360937237/param_define.o ../src/param_define.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c  .generated_files/flags/default/f41eae8832f1cc5ff4490e51ce186e5b87f7aa9b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockLineFrequencyTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockLineFrequencyTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c  .generated_files/flags/default/8f2076967140bb9043821f1300e3ecd6a3461430 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_ClockTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_ClockTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c  .generated_files/flags/default/2177eff63f738563fff0cd369d27232730451a77 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CPUPCTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CPUPCTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c  .generated_files/flags/default/298909abded4a9126da46f4ba6b82be7e5084a5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCbyte.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCbyte.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c  .generated_files/flags/default/bad5f4da643caf9bc34f5bedab9f20767f4bf1e5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_CRCFlashTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_CRCFlashTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c  .generated_files/flags/default/a41a641f55575dcf2a55165d7f28e2e45b9ac306 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMCheckerBoardTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMCheckerBoardTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c  .generated_files/flags/default/79c70397c69abec59d1ecae1b1247423ad03be3e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchBTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchBTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c  .generated_files/flags/default/676c12c2b6f9c31ba20e856fb6a622986cfeaf47 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCStackTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCStackTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o: ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c  .generated_files/flags/default/b78b3169ba0deeeb651f4545fb4d6f839f1ade0c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/531344610" 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../microchip/harmony/v2_06/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o.d" -o ${OBJECTDIR}/_ext/531344610/CLASSB_RAMMarchCTest.o ../../../../../../../../microchip/harmony/v2_06/framework/classb/src/CLASSB_RAMMarchCTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-error -w    
	
${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/6a99bcdbf060ebea68d32c3a89ac95dfcdbd30a4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
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
${DISTDIR}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MZ2048EFH100_peripherals.a  ../myscript___100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD4=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\..\..\microchip\harmony\v2_06\bin\framework\peripheral\PIC32MZ2048EFH100_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD4=1,--defsym=_min_heap_size=0,--defsym=_min_stack_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MZ2048EFH100_peripherals.a ../myscript___100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\..\..\microchip\harmony\v2_06\bin\framework\peripheral\PIC32MZ2048EFH100_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--defsym=_min_stack_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/__SafetyLogic_V2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
