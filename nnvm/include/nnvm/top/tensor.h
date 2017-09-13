/*!
 *  Copyright (c) 2017 by Contributors
 * \file tensor.h
 * \brief Auxiliary param for tensor primitive.
 */
#ifndef NNVM_TOP_TENSOR_H_
#define NNVM_TOP_TENSOR_H_

#include <dmlc/base.h>
#include <dmlc/parameter.h>
#include <nnvm/tuple.h>

namespace nnvm {
namespace top {

struct ConcatenateParam : public dmlc::Parameter<ConcatenateParam> {
  int axis;
  DMLC_DECLARE_PARAMETER(ConcatenateParam) {
    DMLC_DECLARE_FIELD(axis).set_lower_bound(0).set_default(1)
    .describe("the axis to be concated.");
  }
};

struct SplitParam : public dmlc::Parameter<SplitParam> {
  // numpy convention, only support indices, not support list.
  Tuple<int> indices_or_sections;
  int axis;

  DMLC_DECLARE_PARAMETER(SplitParam) {
    DMLC_DECLARE_FIELD(indices_or_sections)
        .describe("Number of outputs to be splitted");
    DMLC_DECLARE_FIELD(axis).set_lower_bound(0).set_default(1)
        .describe("the axis to be splitted.");
  }
};

enum TypeFlag {
  kFloat32 = 0,
  kFloat64 = 1,
  kFloat16 = 2,
  kUint8 = 3,
  kInt32 = 4,
  kInt8  = 5,
  kInt64 = 6,
};

struct CastParam : public dmlc::Parameter<CastParam> {
  int dtype;
  DMLC_DECLARE_PARAMETER(CastParam) {
    DMLC_DECLARE_FIELD(dtype)
    .add_enum("float32", kFloat32)
    .add_enum("float64", kFloat64)
    .add_enum("float16", kFloat16)
    .add_enum("uint8", kUint8)
    .add_enum("int32", kInt32)
    .describe("Output data type.");
  }
};

struct ReshapeParam : public dmlc::Parameter<ReshapeParam> {
  Tuple<int64_t> shape;

  DMLC_DECLARE_PARAMETER(ReshapeParam) {
    DMLC_DECLARE_FIELD(shape);
  }
};

struct ScalarParam : public dmlc::Parameter<ScalarParam> {
  double scalar;

  DMLC_DECLARE_PARAMETER(ScalarParam) {
    DMLC_DECLARE_FIELD(scalar);
  }
};

}  // namespace top
}  // namespace nnvm

#endif  // NNVM_TOP_TENSOR_H_