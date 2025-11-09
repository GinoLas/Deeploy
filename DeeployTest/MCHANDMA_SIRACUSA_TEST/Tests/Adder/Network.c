#include "DeeployPULPMath.h"
#include "bsp/ram.h"
#include "dory_mem.h"
#include "mchan_siracusa.h"
#include "pmsis.h"
#include "pulp_nn_kernels.h"
#include "stdint.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Network.h"

int8_t *DeeployNetwork_input_0;
int8_t *DeeployNetwork_input_1;
int32_t *DeeployNetwork_output_0;
void *DeeployNetwork_inputs[2];
void *DeeployNetwork_outputs[1];
extern struct pi_device cluster_dev;
typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1;
} Add_tiling_closure_args_t;

static void Add_tiling_closure(void *Add_tiling_closure_args) {
  // CLOSURE ARG CAST
  Add_tiling_closure_args_t *args = (Add_tiling_closure_args_t *)Add_tiling_closure_args;
  int8_t *DeeployNetwork_Add_crypto_out_0 = args->DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1 = args->DeeployNetwork_Add_crypto_out_1;

  // CLOSURE FUNCTION CALL

  // Add (Name: Add, Op: Add)
  BEGIN_SINGLE_CORE
  for (uint32_t i = 0; i < 125; i++) {
    DeeployNetwork_output_0[i] = DeeployNetwork_Add_crypto_out_0[i] + DeeployNetwork_Add_crypto_out_1[i] + 0;
  }
  END_SINGLE_CORE

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1;
} Add_cluster_fork_args_t;

static void Add_cluster_fork(void *Add_cluster_fork_args) {
  // CLOSURE ARG CAST
  Add_cluster_fork_args_t *args = (Add_cluster_fork_args_t *)Add_cluster_fork_args;
  int8_t *DeeployNetwork_Add_crypto_out_0 = args->DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1 = args->DeeployNetwork_Add_crypto_out_1;

  // CLOSURE FUNCTION CALL
  Add_tiling_closure_args_t DeeployNetwork_Add_tiling_closure_args = (Add_tiling_closure_args_t){
      .DeeployNetwork_Add_crypto_out_0 = DeeployNetwork_Add_crypto_out_0, .DeeployNetwork_Add_crypto_out_1 = DeeployNetwork_Add_crypto_out_1};

  // Add_tiling_closure CLOSURE CALL
  Add_tiling_closure(&DeeployNetwork_Add_tiling_closure_args);

  pi_cl_team_barrier();

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1;
} Add_closure_args_t;

static void Add_closure(void *Add_closure_args) {
  // CLOSURE ARG CAST
  Add_closure_args_t *args = (Add_closure_args_t *)Add_closure_args;
  int8_t *DeeployNetwork_Add_crypto_out_0 = args->DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1 = args->DeeployNetwork_Add_crypto_out_1;

  // CLOSURE FUNCTION CALL
  Add_cluster_fork_args_t DeeployNetwork_Add_cluster_fork_args = (Add_cluster_fork_args_t){.DeeployNetwork_Add_crypto_out_0 = DeeployNetwork_Add_crypto_out_0,
                                                                                           .DeeployNetwork_Add_crypto_out_1 = DeeployNetwork_Add_crypto_out_1};

  pi_cl_team_fork(NUM_CORES, (void *)Add_cluster_fork, &DeeployNetwork_Add_cluster_fork_args);

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1;
} Add_closure_L3_args_t;

static void Add_closure_L3(void *Add_closure_L3_args) {
  // CLOSURE ARG CAST
  Add_closure_L3_args_t *args = (Add_closure_L3_args_t *)Add_closure_L3_args;
  int8_t *DeeployNetwork_Add_crypto_out_0 = args->DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1 = args->DeeployNetwork_Add_crypto_out_1;

  // CLOSURE FUNCTION CALL
  Add_closure_args_t DeeployNetwork_Add_closure_args = (Add_closure_args_t){.DeeployNetwork_Add_crypto_out_0 = DeeployNetwork_Add_crypto_out_0,
                                                                            .DeeployNetwork_Add_crypto_out_1 = DeeployNetwork_Add_crypto_out_1};

  // Add_closure CLOSURE CALL
  Add_closure(&DeeployNetwork_Add_closure_args);

  // CLOSURE ARG WRITEBACK
}

void RunNetwork() {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1;

  DeeployNetwork_Add_crypto_out_0 = (int8_t *)pi_l2_malloc(sizeof(int8_t) * 125);

  // Crypto Node (Name: Crypto_Add_input_0, Op: Crypto)
  BEGIN_SINGLE_CORE
  printf("Hi, I am a Crypto Node!!!\n");
  for (uint32_t i = 0; i < 125; i++) {
    DeeployNetwork_Add_crypto_out_0[i] = DeeployNetwork_input_0[i] + 0;
  }
  END_SINGLE_CORE

  DeeployNetwork_Add_crypto_out_1 = (int8_t *)pi_l2_malloc(sizeof(int8_t) * 125);

  // Crypto Node (Name: Crypto_Add_input_1, Op: Crypto)
  BEGIN_SINGLE_CORE
  printf("Hi, I am a Crypto Node!!!\n");
  for (uint32_t i = 0; i < 125; i++) {
    DeeployNetwork_Add_crypto_out_1[i] = DeeployNetwork_input_1[i] + 0;
  }
  END_SINGLE_CORE
  Add_closure_L3_args_t DeeployNetwork_Add_closure_L3_args = (Add_closure_L3_args_t){.DeeployNetwork_Add_crypto_out_0 = DeeployNetwork_Add_crypto_out_0,
                                                                                     .DeeployNetwork_Add_crypto_out_1 = DeeployNetwork_Add_crypto_out_1};

  // Add_closure_L3 CLOSURE CALL
  Add_closure_L3(&DeeployNetwork_Add_closure_L3_args);

  pi_l2_free(DeeployNetwork_Add_crypto_out_0, sizeof(int8_t) * 125);

  pi_l2_free(DeeployNetwork_Add_crypto_out_1, sizeof(int8_t) * 125);
}

void InitNetwork() {

  DeeployNetwork_input_0 = (int8_t *)pi_l2_malloc(sizeof(int8_t) * 125);

  DeeployNetwork_input_1 = (int8_t *)pi_l2_malloc(sizeof(int8_t) * 125);

  DeeployNetwork_output_0 = (int32_t *)pi_l2_malloc(sizeof(int32_t) * 125);

  DeeployNetwork_inputs[0] = (void *)DeeployNetwork_input_0;
  DeeployNetwork_inputs[1] = (void *)DeeployNetwork_input_1;
  DeeployNetwork_outputs[0] = (void *)DeeployNetwork_output_0;
}
