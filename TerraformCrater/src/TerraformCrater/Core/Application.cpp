#include "tcpch.h"

#include "Application.h"
#include "../Events/ApplicationEvent.h"
//#include "Log.h"

namespace TerraformCrater {

	Application::Application()
	{

	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TC_TRACE(e);

		}
		if (e.IsInCategory(EventCategoryInput))
		{
			TC_TRACE(e);
		}


		while (true);
	}


}