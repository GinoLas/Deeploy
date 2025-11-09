from Deeploy.DeeployTypes import NodeTemplate

''' (pasted from FloatAddTemplate)
referenceTemplate = NodeTemplate("""
// Add Parallel with 1x6 unrolling (Name: ${nodeName}, Op: ${nodeOp})
int8_t ${nodeName}_core_id = pi_core_id();
int8_t ${nodeName}_log2Core = log2(NUM_CORES);
int16_t ${nodeName}_chunk = (${size} >> ${nodeName}_log2Core) + ((${size} & (NUM_CORES-1))!=0);
int16_t ${nodeName}_chunk_start = MIN(${nodeName}_chunk*${nodeName}_core_id, ${size});
int16_t ${nodeName}_chunk_stop = MIN(${nodeName}_chunk_start + ${nodeName}_chunk, ${size});

uint32_t i = ${nodeName}_chunk_start;
for (; i+5 < ${nodeName}_chunk_stop; i+=6) {
    ${data_out}[i] = ${data_in_1}[i] + ${data_in_2}[i];
    ${data_out}[i+1] = ${data_in_1}[i+1] + ${data_in_2}[i+1];
    ${data_out}[i+2] = ${data_in_1}[i+2] + ${data_in_2}[i+2];
    ${data_out}[i+3] = ${data_in_1}[i+3] + ${data_in_2}[i+3];
    ${data_out}[i+4] = ${data_in_1}[i+4] + ${data_in_2}[i+4];
    ${data_out}[i+5] = ${data_in_1}[i+5] + ${data_in_2}[i+5];
}

for (; i < ${nodeName}_chunk_stop; i++) {
    ${data_out}[i] = ${data_in_1}[i] + ${data_in_2}[i];
}
""")
'''

referenceTemplate = NodeTemplate("""
// Crypto Node (Name: ${nodeName}, Op: ${nodeOp})
int8_t ${nodeName}_core_id = pi_core_id();
int8_t ${nodeName}_log2Core = log2(NUM_CORES);
int16_t ${nodeName}_chunk = (${size} >> ${nodeName}_log2Core) + ((${size} & (NUM_CORES-1))!=0);
int16_t ${nodeName}_chunk_start = MIN(${nodeName}_chunk*${nodeName}_core_id, ${size});
int16_t ${nodeName}_chunk_stop = MIN(${nodeName}_chunk_start + ${nodeName}_chunk, ${size});

printf("### CRYPTO DEBUG INIT ###");
printf("CORE_ID: %d", ${nodeName}_core_id);
printf("LOG2_CORE: %d", ${nodeName}_log2core);      
printf("CHUNK: %d", ${nodeName}_chunk);                           
printf("CHUNK_START: %d", ${nodeName}_chunk_start);
printf("CHUNK_STOP: %d", ${nodeName}_chunk_stop);
printf("### CRYPTO DEBUG END ###");
                                
                                                                  
printf("WITHOUT loop unrolling...")
for (; i < ${size}; i++) {
    ${data_out}[i] = ${data_in_1}[i];
}
""")