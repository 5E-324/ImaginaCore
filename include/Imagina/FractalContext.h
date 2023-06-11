#pragma once

#include "PixelManager.h"
#include "Evaluator.h"

namespace Imagina {
	class im_export FractalContext {
	public:
		IController *Controller = nullptr;
		IPixelManager *PixelManager = nullptr;
		IGpuTextureManager *GpuTextureManager = nullptr;
		IEvaluator *Evaluator = nullptr;
		ILocationManager *LocationManager = nullptr;

		std::function<void(HRReal, HRReal)> OnReferenceChange;

		void UseController(IController *controller);
		void UsePixelManager(IPixelManager *pixelManager);
		void UsePixelManager(IGpuPixelManager *pixelManager);
		void UseEvaluator(IEvaluator *evaluator);
		void UseLocationManager(ILocationManager *locationManager);

		void Link();

		//void SetImmediateTarget(const HRLocation &location);

		void UpdateRelativeCoordinate(HRReal differenceX, HRReal differenceY);
		void Update(SRReal deltaTime);
	};
}