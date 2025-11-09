
#ifndef __DEEPLOY_HEADER__
#define __DEEPLOY_HEADER__
#include "DeeployPULPMath.h"
#include "bsp/ram.h"
#include "dory_mem.h"
#include "mchan_siracusa.h"
#include "pmsis.h"
#include "pulp_nn_kernels.h"
#include "stdint.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
void RunNetwork();
void InitNetwork();

extern int8_t *DeeployNetwork_input_0;
static const uint32_t DeeployNetwork_input_0_len = 125;
extern int8_t *DeeployNetwork_input_1;
static const uint32_t DeeployNetwork_input_1_len = 125;
extern int32_t *DeeployNetwork_output_0;
static const uint32_t DeeployNetwork_output_0_len = 125;
static const uint32_t DeeployNetwork_num_inputs = 2;
static const uint32_t DeeployNetwork_num_outputs = 1;
extern void *DeeployNetwork_inputs[2];
extern void *DeeployNetwork_outputs[1];
static const uint32_t DeeployNetwork_inputs_bytes[2] = {125, 125};
static const uint32_t DeeployNetwork_outputs_bytes[1] = {500};
#endif
