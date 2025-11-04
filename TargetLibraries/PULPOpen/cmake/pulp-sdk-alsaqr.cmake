# SPDX-FileCopyrightText: 2024 ETH Zurich and University of Bologna
#
# SPDX-License-Identifier: Apache-2.0

include(cmake/pulp-sdk-base.cmake)

set(PULP_SDK_HOME $ENV{PULP_SDK_HOME})

set(ALSAQR_COMPILE_FLAGS
  -include ${PULP_SDK_HOME}/rtos/pulpos/pulp/include/pos/chips/alsaqr/config.h
  -DCONFIG_ALSAQR
  -DCONFIG_BOARD_VERSION_ALSAQR
  -DCONFIG_PROFILE_ALSAQR
  -DSKIP_PLL_INIT
  -DUSE_HYPERFLASH
  -DUSE_HYPERRAM
  -DPULP_CHIP_STR=alsaqr
)

set(ALSAQR_INCLUDES
  ${PULP_SDK_HOME}/rtos/pulpos/pulp/include/pos/chips/alsaqr
  ${PULP_SDK_HOME}/rtos/pulpos/pulp/drivers/i3c/include
  ${PULP_SDK_HOME}/rtos/pulpos/pulp/drivers/alsaqr_padmux/include
)

set(PULP_SDK_ALSAQR_C_SOURCE
  ${PULP_SDK_HOME}/rtos/pulpos/pulp/kernel/chips/alsaqr/pll.c
  ${PULP_SDK_HOME}/rtos/pulpos/pulp/kernel/chips/alsaqr/soc.c
  ${PULP_SDK_HOME}/rtos/pulpos/pulp/drivers/alsaqr_padmux/src/alsaqr_padctrl.c
)

set_source_files_properties(${PULP_SDK_ALSAQR_ASM_SOURCE} PROPERTIES COMPILE_FLAGS -DLANGUAGE_ASSEMBLY)
add_library(pulp-sdk OBJECT ${PULP_SDK_BASE_C_SOURCE} ${PULP_SDK_BASE_ASM_SOURCE} ${PULP_SDK_ALSAQR_C_SOURCE} ${PULP_SDK_ALSAQR_ASM_SOURCE})

set(PULP_SDK_COMPILE_FLAGS ${ALSAQR_COMPILE_FLAGS} ${PULP_SDK_BASE_COMPILE_FLAGS})
set(PULP_SDK_INCLUDES ${ALSAQR_INCLUDES} ${PULP_SDK_BASE_INCLUDE})

target_include_directories(pulp-sdk SYSTEM PUBLIC ${PULP_SDK_INCLUDES})
target_compile_options(pulp-sdk PUBLIC ${PULP_SDK_COMPILE_FLAGS})
target_compile_options(pulp-sdk PRIVATE
  -Wno-sign-conversion
  -Wno-unused-function
  -Wno-unused-parameter
  -Wno-conversion
  -Wno-sign-conversion
  -Wno-unused-variable
  -Wno-sign-compare
  -Wno-return-type
  -fno-inline-functions
)
target_compile_options(pulp-sdk INTERFACE
  -Wno-unused-function
)


set(ALSAQR_LINK_OPTIONS
  -Wl,--gc-sections
  -L${PULP_SDK_HOME}/rtos/pulpos/pulp/kernel
  -Tchips/alsaqr/link.ld
)

target_link_libraries(pulp-sdk PUBLIC
  ${ALSAQR_LINK_OPTIONS}
)
