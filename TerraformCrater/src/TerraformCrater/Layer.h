#pragma once

#include "TerraformCrater/Core.h"
#include "TerraformCrater/Events/Event.h"

namespace TerraformCrater {

	class TERRAFORM_CRATER_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};

}

