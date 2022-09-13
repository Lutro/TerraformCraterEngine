#pragma once

#include "../Core.h"
#include "Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace TerraformCrater {

	class TERRAFORM_CRATER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		
	};

}


// Core log Macros

#define TC_CORE_TRACE(...)     ::TerraformCrater::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TC_CORE_INFO(...)      ::TerraformCrater::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TC_CORE_WARN(...)      ::TerraformCrater::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TC_CORE_ERROR(...)     ::TerraformCrater::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TC_CORE_FATAL(...)     ::TerraformCrater::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define TC_CORE_CRITICAL(...)  ::TerraformCrate::Log::GetCoreLogger()->critical(__VA_ARGS__)



// Client log macros
#define TC_TRACE(...)   ::TerraformCrater::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TC_INFO(...)    ::TerraformCrater::Log::GetClientLogger()->info(__VA_ARGS__)
#define TC_WARN(...)    ::TerraformCrater::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TC_ERROR(...)   ::TerraformCrater::Log::GetClientLogger()->error(__VA_ARGS__)
#define TC_FATAL(...)   ::TerraformCrater::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define TC_CRITICAL(...)  ::TerraformCrate::Log::GetClientLogger()->critical(__VA_ARGS__)