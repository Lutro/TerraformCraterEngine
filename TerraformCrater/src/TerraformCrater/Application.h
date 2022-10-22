#pragma once

#include "Core.h"

#include "Window.h"
#include "TerraformCrater/LayerStack.h"
#include "TerraformCrater/Events/Event.h"
#include "TerraformCrater/Events/ApplicationEvent.h"
#include "TerraformCrater/Core/TimeStep.h"

#include "TerraformCrater/ImGui/ImGuiLayer.h"

namespace TerraformCrater {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window;  }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

