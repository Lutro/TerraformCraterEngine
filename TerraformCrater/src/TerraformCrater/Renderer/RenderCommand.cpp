#include "tcpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace TerraformCrater {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
}