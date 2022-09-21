#pragma once


#include "TerraformCrater/Layer.h"
#include "TerraformCrater/Application.h"

#include "TerraformCrater/Events/ApplicationEvent.h"
#include "TerraformCrater/Events/KeyEvent.h"
#include "TerraformCrater/Events/MouseEvent.h"



namespace TerraformCrater {

	class TERRAFORM_CRATER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

		void Begin();
		void End();

		void SetDarkThemeColors();
	private:
		float m_Time = 0.0f;
	};
}


