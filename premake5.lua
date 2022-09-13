workspace "TerraformCrater"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "TerraformCrater"
	location "TerraformCrater"
	kind "SharedLib"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tcpch.h"
	pchsource "%{prj.name}/src/tcpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

	defines
	{
		"TC_PLATFORM_WINDOWS",
		"TC_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug" 
		defines "TC_DEBUG"
		symbols "On"
	
	filter "configurations:Release" 
		defines "TC_RELEASE"
		optimize "On"
	
	filter "configurations:Dist" 
		defines "TC_DIST"
		optimize "On"



project "Sandbox"
	location "TSandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"TerraformCrater/vendor/spdlog/include",
		"TerraformCrater/vendor",
		"TerraformCrater/src"
	}

	links 
	{
		"TerraformCrater"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

	defines
	{
		"TC_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug" 
		defines "TC_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release" 
		defines "TC_RELEASE"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist" 
		defines "TC_DIST"
		runtime "Release"
		optimize "On"

