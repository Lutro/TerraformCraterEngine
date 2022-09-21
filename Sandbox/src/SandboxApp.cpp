#include <TerraformCrater.h>

class ExampleLayer : public TerraformCrater::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		TC_INFO("ExampleLayer::Update");
	}

	void OnEvent(TerraformCrater::Event& event) override
	{
		TC_TRACE("{0}", event);
	}
};


class Sandbox : public TerraformCrater::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new TerraformCrater::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};


TerraformCrater::Application* TerraformCrater::CreateApplication()
{
	return new Sandbox();
}