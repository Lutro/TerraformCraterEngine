#include "tcpch.h"
#include "Platform/OpenGL/OpenGLShader.h"
//#include "TerraformCrater/Core/Timer.h"

#include <fstream>
#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>


namespace TerraformCrater {

	OpenGLShader::OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath)
	{
		// 1. retrieve the vertex/fragment source code from filePath
		std::string vertexCode = ReadFile(vertexPath);
		std::string fragmentCode = ReadFile(fragmentPath);
		//std::ifstream vShaderFile;
		//std::ifstream fShaderFile;
		//// ensure ifstream objects can throw exceptions:
		//vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		//fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		//try
		//{
		//	// open files
		//	vShaderFile.open(vertexPath);
		//	fShaderFile.open(fragmentPath);
		//	std::stringstream vShaderStream, fShaderStream;
		//	// read file's buffer contents into streams
		//	vShaderStream << vShaderFile.rdbuf();
		//	fShaderStream << fShaderFile.rdbuf();
		//	// close file handlers
		//	vShaderFile.close();
		//	fShaderFile.close();
		//	// convert stream into string
		//	vertexCode = vShaderStream.str();
		//	fragmentCode = fShaderStream.str();
		//}
		//catch (std::ifstream::failure& e)
		//{
		//	std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << std::endl;
		//}
		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();


		// 2. compile shaders
		unsigned int vertex, fragment;

		// vertex shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);

		// fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);

		// shader Program
		GLuint program = glCreateProgram();
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);
		glLinkProgram(program);

		m_RendererID = program;
		
		// delete the shaders as they're linked into our program now and no longer necessary
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
		: m_Name(name)
	{

		std::unordered_map<GLenum, std::string> sources;
		sources[GL_VERTEX_SHADER] = vertexSrc;
		sources[GL_FRAGMENT_SHADER] = fragmentSrc;

		
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	std::string OpenGLShader::ReadFile(const std::string& filepath)
	{
		
		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary); // ifstream closes itself due to RAII
		if (in)
		{
			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			if (size != -1)
			{
				result.resize(size);
				in.seekg(0, std::ios::beg);
				in.read(&result[0], size);
			}
			else
			{
				TC_CORE_ERROR("Could not read from file '{0}'", filepath);
			}
		}
		else
		{
			TC_CORE_ERROR("Could not open file '{0}'", filepath);
		}

		return result;
	}


	//void OpenGLShader::CreateProgram()
	//{
	//	GLuint program = glCreateProgram();

	//	std::vector<GLuint> shaderIDs;
	//	for (auto&& [stage, spirv] : m_OpenGLSPIRV)
	//	{
	//		GLuint shaderID = shaderIDs.emplace_back(glCreateShader(stage));
	//		glShaderBinary(1, &shaderID, GL_SHADER_BINARY_FORMAT_SPIR_V, spirv.data(), spirv.size() * sizeof(uint32_t));
	//		glSpecializeShader(shaderID, "main", 0, nullptr, nullptr);
	//		glAttachShader(program, shaderID);
	//	}

	//	glLinkProgram(program);

	//	GLint isLinked;
	//	glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
	//	if (isLinked == GL_FALSE)
	//	{
	//		GLint maxLength;
	//		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

	//		std::vector<GLchar> infoLog(maxLength);
	//		glGetProgramInfoLog(program, maxLength, &maxLength, infoLog.data());
	//		TC_CORE_ERROR("Shader linking failed ({0}):\n{1}", m_FilePath, infoLog.data());

	//		glDeleteProgram(program);

	//		for (auto id : shaderIDs)
	//			glDeleteShader(id);
	//	}

	//	for (auto id : shaderIDs)
	//	{
	//		glDetachShader(program, id);
	//		glDeleteShader(id);
	//	}

	//	m_RendererID = program;
	//}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetInt(const std::string& name, int value)
	{
		UploadUniformInt(name, value);
	}

	void OpenGLShader::SetIntArray(const std::string& name, int* values, uint32_t count)
	{
		UploadUniformIntArray(name, values, count);
	}

	void OpenGLShader::SetFloat(const std::string& name, float value)
	{
		

		UploadUniformFloat(name, value);
	}

	void OpenGLShader::SetFloat2(const std::string& name, const glm::vec2& value)
	{
		
		UploadUniformFloat2(name, value);
	}

	void OpenGLShader::SetFloat3(const std::string& name, const glm::vec3& value)
	{
		
		UploadUniformFloat3(name, value);
	}

	void OpenGLShader::SetFloat4(const std::string& name, const glm::vec4& value)
	{
		
		UploadUniformFloat4(name, value);
	}

	void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& value)
	{
		UploadUniformMat4(name, value);
	}

	void OpenGLShader::UploadUniformInt(const std::string& name, int value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform1i(location, value);
	}

	void OpenGLShader::UploadUniformIntArray(const std::string& name, int* values, uint32_t count)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform1iv(location, count, values);
	}

	void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform1f(location, value);
	}

	void OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2& value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform2f(location, value.x, value.y);
	}

	void OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3& value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform3f(location, value.x, value.y, value.z);
	}

	void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& matrix)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}

}