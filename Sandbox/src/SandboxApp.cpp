#include <TerraformCrater.h>

#include "imgui/imgui.h"

class ExampleLayer : public TerraformCrater::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (TerraformCrater::Input::IsKeyPressed(258))
			TC_TRACE("Tab key is pressed!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(TerraformCrater::Event& event) override
	{
		if (event.GetEventType() == TerraformCrater::EventType::KeyPressed)
		{
			TerraformCrater::KeyPressedEvent& e = (TerraformCrater::KeyPressedEvent&)event;
			TC_TRACE("{0}", (char)e.GetKeyCode());

		}
	}
};


class Sandbox : public TerraformCrater::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};


TerraformCrater::Application* TerraformCrater::CreateApplication()
{
	return new Sandbox();
}