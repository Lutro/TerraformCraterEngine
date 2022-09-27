#pragma once

#include "TerraformCrater/Window.h"

#include <GLFW/glfw3.h>

namespace TerraformCrater {
	/**
	 * @brief 
	*/
	class WindowsWindow : public Window
	{
	public:
		/**
		 * @brief 
		 * @param props 
		*/
		WindowsWindow(const WindowProps& props);
		/**
		 * @brief 
		*/
		virtual ~WindowsWindow();

		/**
		 * @brief 
		*/
		void OnUpdate() override;

		/**
		 * @brief 
		 * @return 
		*/
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		/**
		 * @brief 
		 * @return 
		*/
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window Attributes

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		/**
		 * @brief 
		 * @param enabled 
		*/
		void SetVSync(bool enabled) override;
		/**
		 * @brief 
		 * @return 
		*/
		bool IsVSync() const override;

		/**
		 * @brief 
		 * @return 
		*/
		inline virtual void* GetNativeWindow() const { return m_Window; }
	private:
		/**
		 * @brief 
		 * @param props 
		*/
		virtual void Init(const WindowProps& props);
		/**
		 * @brief 
		*/
		virtual void Shutdown();
	private:
		/**
		 * @brief 
		*/
		GLFWwindow* m_Window;

		/**
		 * @brief 
		*/
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height; 
			bool VSync;

			EventCallbackFn EventCallback;
		};

		/**
		 * @brief 
		*/
		WindowData m_Data;

	};

}

