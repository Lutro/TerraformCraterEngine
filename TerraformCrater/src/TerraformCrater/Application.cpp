#include "tcpch.h"
#include "Application.h"

#include "Input.h"

//#include <glad/glad.h>
//#include <stb_image.h>

#include "TerraformCrater/Renderer/Renderer.h"

#include <GLFW/glfw3.h>

namespace TerraformCrater {

//#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		TC_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(TC_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		{
			//// load and create a texture 
	  // // -------------------------
			//unsigned int texture1, texture2;
			//// texture 1
			//// ---------
			//glGenTextures(1, &texture1);
			//glBindTexture(GL_TEXTURE_2D, texture1);
			//// set the texture wrapping parameters
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			//// set texture filtering parameters
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			//// load image, create texture and generate mipmaps
			//int width, height, nrChannels;
			//stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
			//// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
			//unsigned char* data = stbi_load("assets/textures/container.jpg", &width, &height, &nrChannels, 0);
			//if (data)
			//{
			//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			//	glGenerateMipmap(GL_TEXTURE_2D);
			//}
			//else
			//{
			//	std::cout << "Failed to load texture" << std::endl;
			//}
			//stbi_image_free(data);
			//// texture 2
			//// ---------
			//glGenTextures(1, &texture2);
			//glBindTexture(GL_TEXTURE_2D, texture2);
			//// set the texture wrapping parameters
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			//// set texture filtering parameters
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			//// load image, create texture and generate mipmaps
			//data = stbi_load("assets/textures/awesomeface.png", &width, &height, &nrChannels, 0);
			//if (data)
			//{
			//	// note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
			//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			//	glGenerateMipmap(GL_TEXTURE_2D);
			//}
			//else
			//{
			//	std::cout << "Failed to load texture" << std::endl;
			//}
			//stbi_image_free(data);

			//// tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
			//// -------------------------------------------------------------------------------------------
			//m_Shader->Bind(); // don't forget to activate/use the shader before setting uniforms!
			//// either set it manually like so:
			//m_Shader->SetInt("texture1", 0);
			//// or set it via the texture class
			//m_Shader->SetInt("texture2", 1);

			//glActiveTexture(GL_TEXTURE0);
			//glBindTexture(GL_TEXTURE_2D, texture1);
			//glActiveTexture(GL_TEXTURE1);
			//glBindTexture(GL_TEXTURE_2D, texture2);
		}

	}
	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushLayer(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(TC_BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{
		while (m_Running) 
		{
			float time = (float)glfwGetTime();
			TimeStep timeStep = time - m_LastFrameTime;
			m_LastFrameTime = time;
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(timeStep);

			m_ImGuiLayer->Begin();

			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();

			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}


}