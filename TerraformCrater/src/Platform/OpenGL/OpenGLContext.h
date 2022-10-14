#pragma once

#include"TerraformCrater/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace TerraformCrater {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}