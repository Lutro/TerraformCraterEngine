#include "tcpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace TerraformCrater {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TC_CORE_ASSERT(windowHandle, "Window Handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TC_CORE_ASSERT(status, "Failed to initialize Glad!");

		TC_CORE_INFO("OpenGL Info");
		TC_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		TC_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		TC_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}