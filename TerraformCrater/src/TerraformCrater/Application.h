#pragma once

#include "Core.h"

namespace TerraformCrater {

	class TERRAFORM_CRATER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

