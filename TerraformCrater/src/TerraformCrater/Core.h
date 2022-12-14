#pragma once


#ifdef TC_PLATFORM_WINDOWS
#if TC_DYNAMIC_LINK
	#ifdef TC_BUILD_DLL
		/**
		 * @def Terraform Api
		*/
		#define TERRAFORM_CRATER_API __declspec(dllexport)
	#else
		#define TERRAFORM_CRATER_API __declspec(dllimport)
	#endif
#else
	#define TERRAFORM_CRATER_API
#endif
#else
	#error Terraform Crater Engine only supports Windows !
#endif


#ifdef TC_ENABLE_ASSERTS
	#define TC_ASSERT(x, ...) { if(!(x)) { TC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TC_CORE_ASSERT(x, ...) { if(!(x)) { TC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TC_ASSERT(x, ...)
	#define TC_CORE_ASSERT(x, ...)
#endif

#define TC_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }


#define BIT(x) (1 << x)