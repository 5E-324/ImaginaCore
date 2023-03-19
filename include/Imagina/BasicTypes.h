#pragma once

#include "Complex.h"
#include "MultiPrecision.h"

namespace Imagina {
	using GRReal = float; // Real type for graphics
	using SRReal = double; // Real type for fractal with standard precision and standard range
	using HRReal = double; // Real type for fractal with standard precision and highest range
	using HPReal = MPReal;//FixedGeneric32;//double; // Real type for fractal with high precision

	using SRComplex = Complex<SRReal>;
	using HRComplex = Complex<HRReal>;
	using HPComplex = Complex<HPReal>;

	using GRInt = int32_t;
	using ITInt = int64_t;
	using ITUint = uint64_t;
}