#pragma once
#include "Types.h"
#include "Declarations.h"

namespace Imagina {
	class IController {
	public:
		virtual HRLocation GetRenderLocation() = 0;

		virtual void SetPixelManager(IPixelManager *pixelManager) = 0;
		virtual void SetLocationManager(ILocationManager *locationManager) = 0;

		virtual void UpdateRelativeCoordinate(HRReal differenceX, HRReal differenceY) = 0;

		virtual void Update(SRReal deltaTime) = 0;
	};

	class im_export NavigationController : public IController {
	private:
		HRLocation targetLocation = HRLocation(0.0, 0.0, 2.0);
		HRLocation renderLocation = HRLocation(0.0, 0.0, 2.0);
		HRLocation immediateTarget = HRLocation(0.0, 0.0, 2.0);

		IPixelManager *pixelManager = nullptr;
		ILocationManager *locationManager = nullptr;

		bool zooming = false;
		SRReal remainingZoomTime = 0.0;

	public:
		virtual HRLocation GetRenderLocation() override;

		virtual void SetPixelManager(IPixelManager *pixelManager) override;
		virtual void SetLocationManager(ILocationManager *locationManager) override;

		virtual void UpdateRelativeCoordinate(HRReal differenceX, HRReal differenceY) override;

		virtual void Update(SRReal deltaTime) override;

		void ZoomIn(SRReal centerX, SRReal centerY);
		void ZoomOut(SRReal centerX, SRReal centerY);
		void Move(SRReal x, SRReal y);
	};
}