#include "tcpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace TerraformCrater {

	RendererAPI* RendererAPI::s_RendererAPI = new OpenGLRendererAPI();
}