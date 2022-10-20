#include "tcpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace TerraformCrater
{

    Shader* Shader::Create(const std::string& vertexPath, const std::string& fragmentPath)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    TC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return new OpenGLShader(vertexPath, fragmentPath);
        }

        TC_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Shader* Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    TC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return new OpenGLShader(name, vertexSrc, fragmentSrc);
        }

        TC_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }


}