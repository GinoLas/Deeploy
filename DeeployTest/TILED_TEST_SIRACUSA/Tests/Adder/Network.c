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

int8_t *DeeployNetwork_MEMORYARENA_L1;
int8_t *DeeployNetwork_MEMORYARENA_L2;
int8_t *DeeployNetwork_input_0;
int8_t *DeeployNetwork_input_1;
int32_t *DeeployNetwork_output_0;

static PI_L1 uint8_t DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_numTiles[2] = {0, 1};

static PI_L1 uint8_t DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_numTiles[2] = {0, 1};

static PI_L1 uint8_t DeeployNetwork_TILING_CODEGEN_L1_Add_numTiles[2] = {0, 1};

//----- CUSTOM LOGGING UTILITY -----
PI_L2 char log2_buffer[LOG2_BUF_SIZE];
volatile int log2_index = 0;

void cluster_log(const char *msg)
{
    int len = strlen(msg);
    if (log2_index + len < LOG2_BUF_SIZE) {
        memcpy(&log2_buffer[log2_index], msg, len);
        log2_index += len;
    }
}
//----------------------------------

void *DeeployNetwork_inputs[2];
void *DeeployNetwork_outputs[1];
extern struct pi_device cluster_dev;
typedef struct {
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref;
} Crypto_Add_input_0_tiling_closure_args_t;

static void Crypto_Add_input_0_tiling_closure(void *Crypto_Add_input_0_tiling_closure_args) {
  // CLOSURE ARG CAST
  Crypto_Add_input_0_tiling_closure_args_t *args = (Crypto_Add_input_0_tiling_closure_args_t *)Crypto_Add_input_0_tiling_closure_args;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref;

  // CLOSURE FUNCTION CALL

  // Crypto Node (Name: Crypto_Add_input_0, Op: Crypto)
  uint32_t i = 0;
  int8_t Crypto_Add_input_0_core_id = pi_core_id();
  int8_t Crypto_Add_input_0_log2Core = log2(NUM_CORES);
  int16_t Crypto_Add_input_0_chunk = (125 >> Crypto_Add_input_0_log2Core) + ((125 & (NUM_CORES - 1)) != 0);
  int16_t Crypto_Add_input_0_chunk_start = MIN(Crypto_Add_input_0_chunk * Crypto_Add_input_0_core_id, 125);
  int16_t Crypto_Add_input_0_chunk_stop = MIN(Crypto_Add_input_0_chunk_start + Crypto_Add_input_0_chunk, 125);


  cluster_log("### CRYPTO DEBUG INIT ###\n");
  //cluster_log("CORE_ID: %d\n", Crypto_Add_input_0_core_id);
  // printf("LOG2_CORE: %d", Crypto_Add_input_0_log2core);
  //cluster_log("CHUNK: %d\n", Crypto_Add_input_0_chunk);
  //cluster_log("CHUNK_START: %d\n", Crypto_Add_input_0_chunk_start);
  //cluster_log("CHUNK_STOP: %d\n", Crypto_Add_input_0_chunk_stop);
  cluster_log("### CRYPTO DEBUG END ###\n");

  printf("WITHOUT loop unrolling...");
  for (; i < 125; i++) {
    DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref[i] = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref[i];
  }


  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref;
} Crypto_Add_input_0_cluster_fork_args_t;

static void Crypto_Add_input_0_cluster_fork(void *Crypto_Add_input_0_cluster_fork_args) {
  // CLOSURE ARG CAST
  Crypto_Add_input_0_cluster_fork_args_t *args = (Crypto_Add_input_0_cluster_fork_args_t *)Crypto_Add_input_0_cluster_fork_args;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref;

  // CLOSURE FUNCTION CALL
  Crypto_Add_input_0_tiling_closure_args_t DeeployNetwork_Crypto_Add_input_0_tiling_closure_args = (Crypto_Add_input_0_tiling_closure_args_t){
      .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref,
      .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref};

  // Crypto_Add_input_0_tiling_closure CLOSURE CALL
  Crypto_Add_input_0_tiling_closure(&DeeployNetwork_Crypto_Add_input_0_tiling_closure_args);

  pi_cl_team_barrier();

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr;
} Crypto_Add_input_0_closure_args_t;

static void Crypto_Add_input_0_closure(void *Crypto_Add_input_0_closure_args) {
  // CLOSURE ARG CAST
  Crypto_Add_input_0_closure_args_t *args = (Crypto_Add_input_0_closure_args_t *)Crypto_Add_input_0_closure_args;
  int8_t *DeeployNetwork_Add_crypto_out_0 = args->DeeployNetwork_Add_crypto_out_0;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr;

  // CLOSURE FUNCTION CALL
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 0);
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 125);
  void *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_input_0_ref = (void *)DeeployNetwork_input_0 + 0;
  void *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_Add_crypto_out_0_ref = (void *)DeeployNetwork_Add_crypto_out_0 + 0;
  uint32_t channel_id_future = mchan_channel_alloc();

  // TILING LOOP
  for (int TILING_I = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_numTiles[*DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr];
       TILING_I < DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_numTiles[(*DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr) + 1];
       TILING_I++) {

    mchan_transfer_1d(1441917, DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref,
                      DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_input_0_ref);
    mchan_channel_wait(channel_id_future);
    Crypto_Add_input_0_cluster_fork_args_t DeeployNetwork_Crypto_Add_input_0_cluster_fork_args = (Crypto_Add_input_0_cluster_fork_args_t){
        .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_in_ref,
        .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref};

    pi_cl_team_fork(NUM_CORES, (void *)Crypto_Add_input_0_cluster_fork, &DeeployNetwork_Crypto_Add_input_0_cluster_fork_args);

    mchan_transfer_1d(1310845, DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_data_out_ref,
                      DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_Add_crypto_out_0_ref);
    mchan_channel_wait(channel_id_future);

    // CLOSE TILING LOOP
  }
  *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr += 1;

  mchan_channel_free(channel_id_future);

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr;
} Crypto_Add_input_0_closure_L3_args_t;

static void Crypto_Add_input_0_closure_L3(void *Crypto_Add_input_0_closure_L3_args) {
  // CLOSURE ARG CAST
  Crypto_Add_input_0_closure_L3_args_t *args = (Crypto_Add_input_0_closure_L3_args_t *)Crypto_Add_input_0_closure_L3_args;
  int8_t *DeeployNetwork_Add_crypto_out_0 = args->DeeployNetwork_Add_crypto_out_0;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr;

  // CLOSURE FUNCTION CALL
  Crypto_Add_input_0_closure_args_t DeeployNetwork_Crypto_Add_input_0_closure_args = (Crypto_Add_input_0_closure_args_t){
      .DeeployNetwork_Add_crypto_out_0 = DeeployNetwork_Add_crypto_out_0,
      .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr};

  // Crypto_Add_input_0_closure CLOSURE CALL
  Crypto_Add_input_0_closure(&DeeployNetwork_Crypto_Add_input_0_closure_args);

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref;
} Crypto_Add_input_1_tiling_closure_args_t;

static void Crypto_Add_input_1_tiling_closure(void *Crypto_Add_input_1_tiling_closure_args) {
  // CLOSURE ARG CAST
  Crypto_Add_input_1_tiling_closure_args_t *args = (Crypto_Add_input_1_tiling_closure_args_t *)Crypto_Add_input_1_tiling_closure_args;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref;

  // CLOSURE FUNCTION CALL

  // Crypto Node (Name: Crypto_Add_input_1, Op: Crypto)
  uint32_t i = 0;
  int8_t Crypto_Add_input_1_core_id = pi_core_id();
  int8_t Crypto_Add_input_1_log2Core = log2(NUM_CORES);
  int16_t Crypto_Add_input_1_chunk = (125 >> Crypto_Add_input_1_log2Core) + ((125 & (NUM_CORES - 1)) != 0);
  int16_t Crypto_Add_input_1_chunk_start = MIN(Crypto_Add_input_1_chunk * Crypto_Add_input_1_core_id, 125);
  int16_t Crypto_Add_input_1_chunk_stop = MIN(Crypto_Add_input_1_chunk_start + Crypto_Add_input_1_chunk, 125);

  BEGIN_SINGLE_CORE
  printf("### CRYPTO DEBUG INIT ###");
  printf("CORE_ID: %d", Crypto_Add_input_1_core_id);
  // printf("LOG2_CORE: %d", Crypto_Add_input_1_log2core);
  printf("CHUNK: %d", Crypto_Add_input_1_chunk);
  printf("CHUNK_START: %d", Crypto_Add_input_1_chunk_start);
  printf("CHUNK_STOP: %d", Crypto_Add_input_1_chunk_stop);
  printf("### CRYPTO DEBUG END ###");

  fprintf(1, "HI I AM A CRYPTO NODE LOOK AT ME");

  printf("WITHOUT loop unrolling...");
  for (; i < 125; i++) {
    DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref[i] = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref[i];
  }
  END_SINGLE_CORE

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref;
} Crypto_Add_input_1_cluster_fork_args_t;

static void Crypto_Add_input_1_cluster_fork(void *Crypto_Add_input_1_cluster_fork_args) {
  // CLOSURE ARG CAST
  Crypto_Add_input_1_cluster_fork_args_t *args = (Crypto_Add_input_1_cluster_fork_args_t *)Crypto_Add_input_1_cluster_fork_args;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref;

  // CLOSURE FUNCTION CALL
  Crypto_Add_input_1_tiling_closure_args_t DeeployNetwork_Crypto_Add_input_1_tiling_closure_args = (Crypto_Add_input_1_tiling_closure_args_t){
      .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref,
      .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref};

  // Crypto_Add_input_1_tiling_closure CLOSURE CALL
  Crypto_Add_input_1_tiling_closure(&DeeployNetwork_Crypto_Add_input_1_tiling_closure_args);

  pi_cl_team_barrier();

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_1;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr;
} Crypto_Add_input_1_closure_args_t;

static void Crypto_Add_input_1_closure(void *Crypto_Add_input_1_closure_args) {
  // CLOSURE ARG CAST
  Crypto_Add_input_1_closure_args_t *args = (Crypto_Add_input_1_closure_args_t *)Crypto_Add_input_1_closure_args;
  int8_t *DeeployNetwork_Add_crypto_out_1 = args->DeeployNetwork_Add_crypto_out_1;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr;

  // CLOSURE FUNCTION CALL
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 0);
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 125);
  void *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_input_1_ref = (void *)DeeployNetwork_input_1 + 0;
  void *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_Add_crypto_out_1_ref = (void *)DeeployNetwork_Add_crypto_out_1 + 0;
  uint32_t channel_id_future = mchan_channel_alloc();

  // TILING LOOP
  for (int TILING_I = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_numTiles[*DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr];
       TILING_I < DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_numTiles[(*DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr) + 1];
       TILING_I++) {

    mchan_transfer_1d(1441917, DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref,
                      DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_input_1_ref);
    mchan_channel_wait(channel_id_future);
    Crypto_Add_input_1_cluster_fork_args_t DeeployNetwork_Crypto_Add_input_1_cluster_fork_args = (Crypto_Add_input_1_cluster_fork_args_t){
        .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_in_ref,
        .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref};

    pi_cl_team_fork(NUM_CORES, (void *)Crypto_Add_input_1_cluster_fork, &DeeployNetwork_Crypto_Add_input_1_cluster_fork_args);

    mchan_transfer_1d(1310845, DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_data_out_ref,
                      DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_Add_crypto_out_1_ref);
    mchan_channel_wait(channel_id_future);

    // CLOSE TILING LOOP
  }
  *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr += 1;

  mchan_channel_free(channel_id_future);

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_1;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr;
} Crypto_Add_input_1_closure_L3_args_t;

static void Crypto_Add_input_1_closure_L3(void *Crypto_Add_input_1_closure_L3_args) {
  // CLOSURE ARG CAST
  Crypto_Add_input_1_closure_L3_args_t *args = (Crypto_Add_input_1_closure_L3_args_t *)Crypto_Add_input_1_closure_L3_args;
  int8_t *DeeployNetwork_Add_crypto_out_1 = args->DeeployNetwork_Add_crypto_out_1;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr = args->DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr;

  // CLOSURE FUNCTION CALL
  Crypto_Add_input_1_closure_args_t DeeployNetwork_Crypto_Add_input_1_closure_args = (Crypto_Add_input_1_closure_args_t){
      .DeeployNetwork_Add_crypto_out_1 = DeeployNetwork_Add_crypto_out_1,
      .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr};

  // Crypto_Add_input_1_closure CLOSURE CALL
  Crypto_Add_input_1_closure(&DeeployNetwork_Crypto_Add_input_1_closure_args);

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref;
  int32_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref;
} Add_tiling_closure_args_t;

static void Add_tiling_closure(void *Add_tiling_closure_args) {
  // CLOSURE ARG CAST
  Add_tiling_closure_args_t *args = (Add_tiling_closure_args_t *)Add_tiling_closure_args;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref;
  int32_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref;

  // CLOSURE FUNCTION CALL

  // Add (Name: Add, Op: Add)
  BEGIN_SINGLE_CORE
  for (uint32_t i = 0; i < 125; i++) {
    DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref[i] =
        DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref[i] + DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref[i] + 0;
  }
  END_SINGLE_CORE

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref;
  int32_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref;
} Add_cluster_fork_args_t;

static void Add_cluster_fork(void *Add_cluster_fork_args) {
  // CLOSURE ARG CAST
  Add_cluster_fork_args_t *args = (Add_cluster_fork_args_t *)Add_cluster_fork_args;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref;
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref;
  int32_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref = args->DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref;

  // CLOSURE FUNCTION CALL
  Add_tiling_closure_args_t DeeployNetwork_Add_tiling_closure_args =
      (Add_tiling_closure_args_t){.DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref = DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref,
                                  .DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref = DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref,
                                  .DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref = DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref};

  // Add_tiling_closure CLOSURE CALL
  Add_tiling_closure(&DeeployNetwork_Add_tiling_closure_args);

  pi_cl_team_barrier();

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr;
} Add_closure_args_t;

static void Add_closure(void *Add_closure_args) {
  // CLOSURE ARG CAST
  Add_closure_args_t *args = (Add_closure_args_t *)Add_closure_args;
  int8_t *DeeployNetwork_Add_crypto_out_0 = args->DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1 = args->DeeployNetwork_Add_crypto_out_1;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr = args->DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr;

  // CLOSURE FUNCTION CALL
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 500);
  int8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 625);
  int32_t *DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref = (int32_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 0);
  void *DeeployNetwork_TILING_CODEGEN_L1_Add_Add_crypto_out_0_ref = (void *)DeeployNetwork_Add_crypto_out_0 + 0;
  void *DeeployNetwork_TILING_CODEGEN_L1_Add_Add_crypto_out_1_ref = (void *)DeeployNetwork_Add_crypto_out_1 + 0;
  void *DeeployNetwork_TILING_CODEGEN_L1_Add_output_0_ref = (void *)DeeployNetwork_output_0 + 0;
  uint32_t channel_id_future = mchan_channel_alloc();

  // TILING LOOP
  for (int TILING_I = DeeployNetwork_TILING_CODEGEN_L1_Add_numTiles[*DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr];
       TILING_I < DeeployNetwork_TILING_CODEGEN_L1_Add_numTiles[(*DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr) + 1]; TILING_I++) {

    mchan_transfer_1d(1441917, DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref, DeeployNetwork_TILING_CODEGEN_L1_Add_Add_crypto_out_0_ref);
    mchan_transfer_1d(1441917, DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref, DeeployNetwork_TILING_CODEGEN_L1_Add_Add_crypto_out_1_ref);
    mchan_channel_wait(channel_id_future);
    Add_cluster_fork_args_t DeeployNetwork_Add_cluster_fork_args =
        (Add_cluster_fork_args_t){.DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref = DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_1_ref,
                                  .DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref = DeeployNetwork_TILING_CODEGEN_L1_Add_data_in_2_ref,
                                  .DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref = DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref};

    pi_cl_team_fork(NUM_CORES, (void *)Add_cluster_fork, &DeeployNetwork_Add_cluster_fork_args);

    mchan_transfer_1d(1311220, DeeployNetwork_TILING_CODEGEN_L1_Add_data_out_ref, DeeployNetwork_TILING_CODEGEN_L1_Add_output_0_ref);
    mchan_channel_wait(channel_id_future);

    // CLOSE TILING LOOP
  }
  *DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr += 1;

  mchan_channel_free(channel_id_future);

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr;
} Add_closure_L3_args_t;

static void Add_closure_L3(void *Add_closure_L3_args) {
  // CLOSURE ARG CAST
  Add_closure_L3_args_t *args = (Add_closure_L3_args_t *)Add_closure_L3_args;
  int8_t *DeeployNetwork_Add_crypto_out_0 = args->DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1 = args->DeeployNetwork_Add_crypto_out_1;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr = args->DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr;

  // CLOSURE FUNCTION CALL
  Add_closure_args_t DeeployNetwork_Add_closure_args =
      (Add_closure_args_t){.DeeployNetwork_Add_crypto_out_0 = DeeployNetwork_Add_crypto_out_0,
                           .DeeployNetwork_Add_crypto_out_1 = DeeployNetwork_Add_crypto_out_1,
                           .DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr = DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr};

  // Add_closure CLOSURE CALL
  Add_closure(&DeeployNetwork_Add_closure_args);

  // CLOSURE ARG WRITEBACK
}

void RunNetwork() {
  int8_t *DeeployNetwork_Add_crypto_out_0;
  int8_t *DeeployNetwork_Add_crypto_out_1;

  uint8_t bu_DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr = 0;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr = &bu_DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr;
  uint8_t bu_DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr = 0;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr = &bu_DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr;
  uint8_t bu_DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr = 0;
  uint8_t *DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr = &bu_DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr;
  DeeployNetwork_Add_crypto_out_0 = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L2 + 0);
  Crypto_Add_input_0_closure_L3_args_t DeeployNetwork_Crypto_Add_input_0_closure_L3_args = (Crypto_Add_input_0_closure_L3_args_t){
      .DeeployNetwork_Add_crypto_out_0 = DeeployNetwork_Add_crypto_out_0,
      .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_0_tileIdxPtr};

  // Crypto_Add_input_0_closure_L3 CLOSURE CALL
  Crypto_Add_input_0_closure_L3(&DeeployNetwork_Crypto_Add_input_0_closure_L3_args);

  DeeployNetwork_Add_crypto_out_1 = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L2 + 625);
  Crypto_Add_input_1_closure_L3_args_t DeeployNetwork_Crypto_Add_input_1_closure_L3_args = (Crypto_Add_input_1_closure_L3_args_t){
      .DeeployNetwork_Add_crypto_out_1 = DeeployNetwork_Add_crypto_out_1,
      .DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr = DeeployNetwork_TILING_CODEGEN_L1_Crypto_Add_input_1_tileIdxPtr};

  // Crypto_Add_input_1_closure_L3 CLOSURE CALL
  Crypto_Add_input_1_closure_L3(&DeeployNetwork_Crypto_Add_input_1_closure_L3_args);

  Add_closure_L3_args_t DeeployNetwork_Add_closure_L3_args =
      (Add_closure_L3_args_t){.DeeployNetwork_Add_crypto_out_0 = DeeployNetwork_Add_crypto_out_0,
                              .DeeployNetwork_Add_crypto_out_1 = DeeployNetwork_Add_crypto_out_1,
                              .DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr = DeeployNetwork_TILING_CODEGEN_L1_Add_tileIdxPtr};

  // Add_closure_L3 CLOSURE CALL
  Add_closure_L3(&DeeployNetwork_Add_closure_L3_args);
}

void InitNetwork() {

  DeeployNetwork_MEMORYARENA_L1 = (int8_t *)pmsis_l1_malloc(sizeof(int8_t) * 750);

  DeeployNetwork_MEMORYARENA_L2 = (int8_t *)pi_l2_malloc(sizeof(int8_t) * 750);

  DeeployNetwork_input_0 = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L2 + 250);
  DeeployNetwork_input_1 = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L2 + 125);
  DeeployNetwork_output_0 = (int32_t *)((char *)DeeployNetwork_MEMORYARENA_L2 + 125);
  DeeployNetwork_inputs[0] = (void *)DeeployNetwork_input_0;
  DeeployNetwork_inputs[1] = (void *)DeeployNetwork_input_1;
  DeeployNetwork_outputs[0] = (void *)DeeployNetwork_output_0;
}
