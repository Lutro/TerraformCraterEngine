workspace "TerraformCrater"
	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "TerraformCrater/vendor/GLFW/include"

include "TerraformCrater/vendor/GLFW"

-- Sandbox

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

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
		"TerraformCrater/src"
	}

	links 
	{
		"TerraformCrater"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TC_PLATFORM_WINDOWS"
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

	filter { "system:windows", "configurations:Debug" }
		buildoptions "/MD"


project "TerraformCrater"
	location "TerraformCrater"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tcpch.h"
	pchsource "TerraformCrater/src/tcpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

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

	filter { "system:windows", "configurations:Debug" }
		buildoptions "/MD"


