#pragma once

#include "PlatformDetection.h"

#ifdef TC_DEBUG
	#if defined(TC_PLATFORM_WINDOWS)
		#define TC_DEBUGBREAK() __debugbreak()
	#elif defined(TC_PLATFORM_LINUX)
		#include <signal.h>
		#define TC_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define TC_ENABLE_ASSERTS
#else
	#define TC_DEBUGBREAK()
#endif

#define TC_EXPAND_MACRO(x) x
#define TC_STRINGIFY_MACRO(x) #x
//
#define BIT(x) (1 << x)

#define TC_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace TerraformCrater {

	/*template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}*/

}

#include "Log.h"
#include "Assert.h"
