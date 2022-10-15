#include "tcpch.h"
#include "VertexArray.h"

#include "TerraformCrater/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace TerraformCrater {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    TC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLVertexArray();
		}

		TC_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}