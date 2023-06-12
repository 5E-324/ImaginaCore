#pragma once

#include "Declarations.h"
#include "Evaluator.h"
#include "CApi.h"

namespace Imagina {
	class im_export LowPrecisionEvaluatorDelegate : public LowPrecisionEvaluator {
		struct Output {
			double Value;
		};
		ImCApi::IEvaluator *instance;
		ImCApi::pIEvaluator_Release release;
		ImCApi::pIEvaluator_GetOutputDescriptor getOutputDescriptor;
		ImCApi::pStandardEvaluator_SetEvaluationParameters setEvaluationParameters;
		ImCApi::pLowPrecisionEvaluator_Evaluate evaluate;

		PixelDataDescriptor *outputDescriptor = nullptr;
	public:
		LowPrecisionEvaluatorDelegate(
			ImCApi::IEvaluator *instance,
			ImCApi::pIEvaluator_Release release,
			ImCApi::pIEvaluator_GetOutputDescriptor getOutputDescriptor,
			ImCApi::pStandardEvaluator_SetEvaluationParameters setEvaluationParameters,
			ImCApi::pLowPrecisionEvaluator_Evaluate evaluate
		) : instance(instance), release(release), getOutputDescriptor(getOutputDescriptor), setEvaluationParameters(setEvaluationParameters), evaluate(evaluate) {}

		virtual ~LowPrecisionEvaluatorDelegate() override;

		virtual const PixelDataDescriptor *GetOutputDescriptor() override;

		virtual void SetEvaluationParameters(const StandardEvaluationParameters &parameters) override;

		virtual void Evaluate(IRasterizingInterface &rasterizingInterface) override;
	};
}