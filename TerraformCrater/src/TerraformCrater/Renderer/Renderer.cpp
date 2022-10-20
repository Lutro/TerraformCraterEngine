#include "tcpch.h"
#include "Renderer.h"

namespace TerraformCrater
{
	void Renderer::BeginScene()
	{
	}
	void Renderer::EndScene()
	{
	}
	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
	{
		RenderCommand::DrawIndexed(vertexArray);
	}
	//RendererAPI Renderer::s_RendererAPI = RendererAPI::OpenGL;
}
