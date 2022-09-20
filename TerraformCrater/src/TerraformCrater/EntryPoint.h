#pragma once

#ifdef TC_PLATFORM_WINDOWS

extern TerraformCrater::Application* TerraformCrater::CreateApplication();

int main(int argc, char** argv)
{
	auto app = TerraformCrater::CreateApplication();
	app->Run();
	delete app;
}


#endif