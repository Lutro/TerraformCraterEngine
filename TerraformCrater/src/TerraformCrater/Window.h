#include "TerraformCrater/Core.h"
#include "TerraformCrater/Events/Event.h"

namespace TerraformCrater {
	/**
	 * @brief 
	*/
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "TC Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	// Interface representing a desktop system based window
	
	/**
	 * @brief 
	*/
	class TERRAFORM_CRATER_API Window
	{
	public:
		/**
		 * @brief 
		*/
		using EventCallbackFn = std::function<void(Event&)>;

		/**
		 * @brief 
		*/
		virtual ~Window() {}

		/**
		 * @brief 
		*/
		virtual void OnUpdate() = 0;

		/**
		 * @brief 
		 * @return 
		*/
		virtual unsigned int GetWidth() const = 0;
		/**
		 * @brief 
		 * @return 
		*/
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes

		/**
		 * @brief 
		 * @param callback 
		*/
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		/**
		 * @brief 
		 * @param enabled 
		*/
		virtual void SetVSync(bool enabled) = 0;
		/**
		 * @brief 
		 * @return 
		*/
		virtual bool IsVSync() const = 0;
		/**
		 * @brief 
		 * @return 
		*/
		virtual void* GetNativeWindow() const = 0;
		/**
		 * @brief 
		 * @param props 
		 * @return 
		*/
		static Window* Create(const WindowProps& props = WindowProps());

	};
}