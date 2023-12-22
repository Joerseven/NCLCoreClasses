CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
set(PROJECT_NAME NCLCoreClasses)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)

################################################################################
# Source groups
################################################################################
set(Asset_Handling
    "Assets.cpp"
    "Assets.h"
    "SimpleFont.cpp"
    "SimpleFont.h"
    "TextureLoader.cpp"
    "TextureLoader.h"
    "TextureWriter.cpp"
    "TextureWriter.h"
)
source_group("Asset Handling" FILES ${Asset_Handling})

set(Header_Files
    "Camera.h"
	"headers.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Maths
    "Maths.cpp"
    "Maths.h"

    "Plane.cpp"
    "Plane.h"
	"Frustum.cpp"
    "Frustum.h"
    "Quaternion.cpp"
    "Quaternion.h"

	"Vector.h"
    "Matrix.h"
)
source_group("Maths" FILES ${Maths})

set(Rendering
    "MeshAnimation.cpp"
    "MeshAnimation.h"
    "Mesh.cpp"
    "Mesh.h"
	
	"MshLoader.cpp"
    "MshLoader.h"
	
    "MeshMaterial.cpp"
    "MeshMaterial.h"
    "RendererBase.cpp"
    "RendererBase.h"
    "Shader.cpp"
    "Shader.h"
    "Texture.cpp"
    "Texture.h"
)
source_group("Rendering" FILES ${Rendering})

set(Source_Files
    "Camera.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(Windowing_and_Input
    "GameTimer.cpp"
    "GameTimer.h"
    "Keyboard.cpp"
    "Keyboard.h"
    "Mouse.cpp"
    "Mouse.h"
    "Window.cpp"
    "Window.h"
	"Controller.cpp"
    "Controller.h"
	"KeyboardMouseController.cpp"
    "KeyboardMouseController.h"
	"glad/gl.h"
	"glad/gl.c"
)
source_group("Windowing and Input" FILES ${Windowing_and_Input})

set(Windowing_and_Input__Win32
    "Win32Keyboard.cpp"
    "Win32Keyboard.h"
    "Win32Mouse.cpp"
    "Win32Mouse.h"
    "Win32Window.cpp"
    "Win32Window.h"
)
source_group("Windowing and Input\\Win32" FILES ${Windowing_and_Input__Win32})

set(ALL_FILES
    ${Asset_Handling}
    ${Header_Files}
    ${Maths}
    ${Rendering}
    ${Source_Files}
    ${Windowing_and_Input}
    ${Windowing_and_Input__Win32}
		GlfwWindow.cpp GlfwWindow.h main.cpp GlfwKeyboard.cpp GlfwKeyboard.h GlfwMouse.cpp GlfwMouse.h)

# GLFW

add_subdirectory(glfw)
################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES
    INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
)

target_include_directories(${PROJECT_NAME} PUBLIC glfw)


set(ASSET_ROOT "${CMAKE_SOURCE_DIR}/Assets/" CACHE STRING "" FORCE)
add_compile_definitions(ASSETROOTLOCATION="${ASSET_ROOT}")
OPTION(USE_GLFW ON)

if (USE_GLFW)
	add_compile_definitions(USEGLFW=USE_GLFW)
endif()


target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

################################################################################
# Compile and link options
################################################################################
if(MSVC)

	target_precompile_headers(${PROJECT_NAME} PRIVATE
			<memory>
			<unordered_set>
			<vector>
			<string>
			<fstream>
			<sstream>
			<iostream>
			<string>
			<iosfwd>
			<set>
			<map>
			<chrono>
			<thread>
			<filesystem>
			<functional>
			<algorithm>
			<assert.h>
			)

    target_compile_options(${PROJECT_NAME} PRIVATE
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING};
		/std:c++20
    )
endif()