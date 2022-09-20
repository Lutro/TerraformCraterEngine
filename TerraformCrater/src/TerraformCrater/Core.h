#pragma once


#ifdef TC_PLATFORM_WINDOWS
	#ifdef TC_BUILD_DLL
		#define TERRAFORM_CRATER_API __declspec(dllexport)
	#else
		#define TERRAFORM_CRATER_API __declspec(dllimport)
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

#define BIT(x) (1 << x)