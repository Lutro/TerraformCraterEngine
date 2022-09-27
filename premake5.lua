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
IncludeDir["Glad"] = "TerraformCrater/vendor/Glad/include"
IncludeDir["ImGui"] = "TerraformCrater/vendor/imgui"
IncludeDir["glm"] = "TerraformCrater/vendor/glm"

include "TerraformCrater/vendor/GLFW"
include "TerraformCrater/vendor/Glad"
include "TerraformCrater/vendor/imgui"


project "TerraformCrater"
	location "TerraformCrater"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tcpch.h"
	pchsource "TerraformCrater/src/tcpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"TC_PLATFORM_WINDOWS",
			"TC_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "TC_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "TC_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "TC_DIST"
		optimize "on"



-- Sandbox

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"TerraformCrater/src",
		"TerraformCrater/vendor",
		"%{IncludeDir.glm}"
	}

	links 
	{
		"TerraformCrater"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"TC_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "TC_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "TC_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "TC_DIST"
		optimize "on"