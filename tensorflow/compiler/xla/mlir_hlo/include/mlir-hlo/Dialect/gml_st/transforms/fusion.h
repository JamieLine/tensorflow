/* Copyright 2022 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef MLIR_HLO_DIALECT_GML_ST_TRANSFORMS_FUSION_H
#define MLIR_HLO_DIALECT_GML_ST_TRANSFORMS_FUSION_H

#include "mlir-hlo/Dialect/gml_st/IR/gml_st_ops.h"

namespace mlir {
namespace gml_st {

// Create fused operation based on the specificed subset. The result is
// equivalent to the given `materialize` op.
FailureOr<Value> createFusedOp(OpBuilder &b, MaterializeOp materializeOp);

/// Populate fusion patterns.
void populateFusionPatterns(MLIRContext *ctx,
                            function_ref<LogicalResult(Operation *)> filterFn,
                            RewritePatternSet *patterns);

}  // namespace gml_st
}  // namespace mlir

#endif  // MLIR_HLO_DIALECT_GML_ST_TRANSFORMS_FUSION_H
