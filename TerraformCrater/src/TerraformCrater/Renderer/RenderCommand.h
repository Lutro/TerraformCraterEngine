#pragma once

#include "RendererAPI.h"

namespace TerraformCrater {

	class RenderCommand
	{

	public:
		inline void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}

	private:
		static RendererAPI* s_RendererAPI;
	};


}

