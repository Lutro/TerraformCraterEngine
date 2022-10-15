#include "tcpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace TerraformCrater {



	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	//void OpenGLVertexArray::AddVertexBuffer(const VertexBuffer* vertexBuffer)
	//{
	//	TC_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

	//	glBindVertexArray(m_RendererID);
	//	vertexBuffer->Bind();

	//	const auto& layout = vertexBuffer->GetLayout();
	//	for (const auto& element : layout)
	//	{
	//		switch (element.Type)
	//		{
	//		case ShaderDataType::Float:
	//		case ShaderDataType::Float2:
	//		case ShaderDataType::Float3:
	//		case ShaderDataType::Float4:
	//		{
	//			glEnableVertexAttribArray(m_VertexBufferIndex);
	//			glVertexAttribPointer(m_VertexBufferIndex,
	//				element.GetComponentCount(),
	//				ShaderDataTypeToOpenGLBaseType(element.Type),
	//				element.Normalized ? GL_TRUE : GL_FALSE,
	//				layout.GetStride(),
	//				(const void*)element.Offset);
	//			m_VertexBufferIndex++;
	//			break;
	//		}
	//		case ShaderDataType::Int:
	//		case ShaderDataType::Int2:
	//		case ShaderDataType::Int3:
	//		case ShaderDataType::Int4:
	//		case ShaderDataType::Bool:
	//		{
	//			glEnableVertexAttribArray(m_VertexBufferIndex);
	//			glVertexAttribIPointer(m_VertexBufferIndex,
	//				element.GetComponentCount(),
	//				ShaderDataTypeToOpenGLBaseType(element.Type),
	//				layout.GetStride(),
	//				(const void*)element.Offset);
	//			m_VertexBufferIndex++;
	//			break;
	//		}
	//		case ShaderDataType::Mat3:
	//		case ShaderDataType::Mat4:
	//		{
	//			uint8_t count = element.GetComponentCount();
	//			for (uint8_t i = 0; i < count; i++)
	//			{
	//				glEnableVertexAttribArray(m_VertexBufferIndex);
	//				glVertexAttribPointer(m_VertexBufferIndex,
	//					count,
	//					ShaderDataTypeToOpenGLBaseType(element.Type),
	//					element.Normalized ? GL_TRUE : GL_FALSE,
	//					layout.GetStride(),
	//					(const void*)(element.Offset + sizeof(float) * count * i));
	//				glVertexAttribDivisor(m_VertexBufferIndex, 1);
	//				m_VertexBufferIndex++;
	//			}
	//			break;
	//		}
	//		default:
	//			TC_CORE_ASSERT(false, "Unknown ShaderDataType!");
	//		}
	//	}

	//	m_VertexBuffers.push_back(vertexBuffer);
	//}

	//void OpenGLVertexArray::SetIndexBuffer(const IndexBuffer* indexBuffer)
	//{
	//	glBindVertexArray(m_RendererID);
	//	indexBuffer->Bind();

	//	m_IndexBuffer = indexBuffer;
	//}

}