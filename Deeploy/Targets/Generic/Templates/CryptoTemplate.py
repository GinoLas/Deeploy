# SPDX-FileCopyrightText: 2021 ETH Zurich and University of Bologna
#
# SPDX-License-Identifier: Apache-2.0

from typing import Dict, List, Tuple

from Deeploy.DeeployTypes import NetworkContext, NodeTemplate, OperatorRepresentation


class _CryptoTemplate(NodeTemplate):

    def alignToContext(self, ctxt: NetworkContext,
                       operatorRepresentation: OperatorRepresentation) -> Tuple[NetworkContext, Dict, List[str]]:

        data_in = ctxt.lookup(operatorRepresentation['data_in'])
        data_out = ctxt.lookup(operatorRepresentation['data_out'])

        input_offset = 0
        if hasattr(data_in, "_signed") and hasattr(data_in, "nLevels"):
            input_offset = (data_in._signed == 0) * int(data_in.nLevels / 2)
        output_offset = 0
        if hasattr(data_out, "_signed") and hasattr(data_out, "nLevels"):
            output_offset = -(data_out._signed == 0) * int(data_out.nLevels // 2)

        operatorRepresentation['offset'] = input_offset + output_offset

        return ctxt, operatorRepresentation, []


referenceTemplate = _CryptoTemplate("""
// Crypto Node (Name: ${nodeName}, Op: ${nodeOp})
BEGIN_SINGLE_CORE
    printf("Hi, I am a Crypto Node!!!\\n");
    for (uint32_t i=0;i<${size};i++){
        ${data_out}[i] = ${data_in}[i] + ${offset};
    }
END_SINGLE_CORE
""")
