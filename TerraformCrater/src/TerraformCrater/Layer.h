#pragma once

#include "TerraformCrater/Core.h"
#include "TerraformCrater/Events/Event.h"

namespace TerraformCrater {
	/**
	* 
	*/
	class TERRAFORM_CRATER_API Layer
	{
	public:
		/**
		 * @brief 
		 * @param name 
		*/
		Layer(const std::string& name = "Layer");
		/**
		 * @brief 
		*/
		virtual ~Layer();
		/**
		 * @brief 
		*/
		virtual void OnAttach() {}
		/**
		 * @brief 
		*/
		virtual void OnDetach() {}
		/**
		 * @brief 
		*/
		virtual void OnUpdate() {}
		/**
		 * @brief 
		*/
		virtual void OnImGuiRender() {}
		/**
		 * @brief 
		 * @param event 
		*/
		virtual void OnEvent(Event& event) {}

		/**
		 * @brief 
		 * @return The debug name of layer
		*/
		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		/**
		 * @brief 
		*/
		std::string m_DebugName;

	};

}

