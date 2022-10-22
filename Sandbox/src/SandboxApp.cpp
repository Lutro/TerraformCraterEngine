#include <TerraformCrater.h>

#include "imgui/imgui.h"

class ExampleLayer : public TerraformCrater::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		// set up vertex data (and buffer(s)) and configure vertex attributes
		// ------------------------------------------------------------------

		float vertices[] = {
			// positions          // colors          
			-0.5f, -0.5f, 0.0f,  0.8f, 0.2f, 0.8f, 1.0f, // top right
			 0.5f, -0.5f, 0.0f,  0.2f, 0.3f, 0.8f, 1.0f, // bottom right
			 0.0f,  0.5f, 0.0f,  0.8f, 0.8f, 0.2f, 1.0f // bottom left
		};

		float squareVertices[] = {
			// positions          // colors           // texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
		};

		// Indices
		unsigned int indices[] = {
		  0, 1, 2 // first triangle
		};

		unsigned int  squareIndices[] = {
		  0, 1, 3, // first triangle
		  1, 2, 3  // second triangle
		};

		m_SquareVA.reset(TerraformCrater::VertexArray::Create());
		std::shared_ptr<TerraformCrater::VertexBuffer> squareVB;
		squareVB.reset(TerraformCrater::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{TerraformCrater::ShaderDataType::Float3, "a_Position", true},
			{TerraformCrater::ShaderDataType::Float3, "a_Color", true },
			{TerraformCrater::ShaderDataType::Float2, "a_Texture", true}
			});
		m_SquareVA->AddVertexBuffer(squareVB);
		std::shared_ptr<TerraformCrater::IndexBuffer> squareIB;
		squareIB.reset(TerraformCrater::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);





		// Vertex Array
		m_VertexArray.reset(TerraformCrater::VertexArray::Create());

		// Vertex Buffer
		std::shared_ptr<TerraformCrater::VertexBuffer> VBO;
		VBO.reset(TerraformCrater::VertexBuffer::Create(vertices, sizeof(vertices)));
		VBO->SetLayout({
			{TerraformCrater::ShaderDataType::Float3, "a_Position"},
			{TerraformCrater::ShaderDataType::Float4, "a_Color"}
			});
		m_VertexArray->AddVertexBuffer(VBO);

		// Index Buffer
		std::shared_ptr<TerraformCrater::IndexBuffer> IBO;
		IBO.reset(TerraformCrater::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(IBO);


		// build and compile our shader program
   // ------------------------------------

		blueShader.reset(TerraformCrater::Shader::Create("assets/shaders/blueShader.vs", "assets/shaders/blueShader.fs"));
		m_Shader.reset(TerraformCrater::Shader::Create("assets/shaders/texture.vs", "assets/shaders/texture.fs"));

	}

	void OnUpdate(TerraformCrater::TimeStep ts) override
	{
		TC_TRACE("Delta time : {0}s, ({1}ms)", ts.GetSeconds(), ts.GetMilliSeconds());
		// Key Input
		if (TerraformCrater::Input::IsKeyPressed(TerraformCrater::Key::Left))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (TerraformCrater::Input::IsKeyPressed(TerraformCrater::Key::Right))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (TerraformCrater::Input::IsKeyPressed(TerraformCrater::Key::Down))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;
		else if (TerraformCrater::Input::IsKeyPressed(TerraformCrater::Key::Up))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		if (TerraformCrater::Input::IsKeyPressed(TerraformCrater::Key::A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (TerraformCrater::Input::IsKeyPressed(TerraformCrater::Key::D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;


		TerraformCrater::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		TerraformCrater::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		TerraformCrater::Renderer::BeginScene(m_Camera);

		TerraformCrater::Renderer::Submit(m_Shader, m_SquareVA);
		TerraformCrater::Renderer::Submit(blueShader, m_VertexArray);

		TerraformCrater::Renderer::EndScene();
	
	}

	virtual void OnImGuiRender() override
	{
	
	}

	void OnEvent(TerraformCrater::Event& event) override
	{
		//TerraformCrater::EventDispatcher dispatcher(event);
		//dispatcher.Dispatch<TerraformCrater::KeyPressedEvent>(TC_BIND_EVENT_FN(ExampleLayer::OnKeyPressedEvent));
	}


private:
	std::shared_ptr<TerraformCrater::Shader> m_Shader;
	std::shared_ptr<TerraformCrater::Shader> blueShader;

	std::shared_ptr<TerraformCrater::VertexArray> m_VertexArray;
	std::shared_ptr<TerraformCrater::VertexArray> m_SquareVA;

	TerraformCrater::OrthographicCamera m_Camera;

	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;
};


class Sandbox : public TerraformCrater::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};


TerraformCrater::Application* TerraformCrater::CreateApplication()
{
	return new Sandbox();
}