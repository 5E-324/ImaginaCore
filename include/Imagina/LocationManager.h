#pragma once

#include "Types.h"
#include "Declarations.h"
#include <functional>

namespace Imagina {
	class ILocationManager {
	public:
		std::function<void(HRReal, HRReal)> OnReferenceChange;

		virtual void SetEvaluator(IEvaluator *evaluator) = 0;
		virtual void LocationChanged(const HRLocation &location) = 0;
	};

	class im_export StandardLocationManager : public ILocationManager {
		IEvaluator *evaluator = nullptr;
		MultiPrecision &mp;
		HPReal referenceX, referenceY;

	public:
		StandardLocationManager(MultiPrecision &mp) : mp(mp), referenceX(0.0, mp), referenceY(0.0, mp) {}

		virtual void SetEvaluator(IEvaluator *evaluator) override;
		virtual void LocationChanged(const HRLocation &location) override;
	};
}