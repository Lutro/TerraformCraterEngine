#include <TerraformCrater.h>

class Sandbox : public TerraformCrater::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


TerraformCrater::Application* TerraformCrater::CreateApplication()
{
	return new Sandbox();
}