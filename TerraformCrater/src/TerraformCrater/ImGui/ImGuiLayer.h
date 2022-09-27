#pragma once


#include "TerraformCrater/Layer.h"

#include "TerraformCrater/Events/ApplicationEvent.h"
#include "TerraformCrater/Events/KeyEvent.h"
#include "TerraformCrater/Events/MouseEvent.h"



namespace TerraformCrater {
	/**
	 * @brief 
	*/
	class TERRAFORM_CRATER_API ImGuiLayer : public Layer
	{
	public:
		/**
		 * @brief 
		*/
		ImGuiLayer();

		/**
		 * @brief
		*/
		~ImGuiLayer();

		/**
		 * @brief 
		*/
		virtual void OnAttach();

		/**
		 * @brief 
		*/
		virtual void OnDetach();

		/**
		 * @brief 
		*/
		virtual void OnImGuiRender() override;
		
		/**
		 * @brief 
		*/
		void Begin();
		/**
		 * @brief 
		*/
		void End();

		/**
		 * @brief 
		*/
		void SetDarkThemeColors();		

	private:
		/**
		 * @brief 
		*/
		float m_Time = 0.0f;
	};
}


