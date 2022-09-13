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

#define BIT(x) (1 << x)