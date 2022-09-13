#pragma once

#include "Core/Base.h"
#include "Core/Application.h"

#ifdef TC_PLATFORM_WINDOWS

extern TerraformCrater::Application* TerraformCrater::CreateApplication();

int main(int argc, char** argv)
{

	TerraformCrater::Log::Init();
	TC_CORE_WARN("Intialized Log!");
	int a = 5;
	TC_INFO("Hello! Var={0}", a);



	auto app = TerraformCrater::CreateApplication();
	app->Run();
	delete app;
}


#endif