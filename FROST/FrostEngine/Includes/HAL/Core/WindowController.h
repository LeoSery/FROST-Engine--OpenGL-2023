#pragma once

#include <GLFW/glfw3.h>

#include <stdexcept>

namespace Frost::HAL::Core
{
	class WindowController
	{
	public:
		void Init()
		{
			glfwInit();

			// Set context as OpenGL 4.6 Core, forward compat, with debug depending on build config
			glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#ifndef NDEBUG
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#else /* !NDEBUG */
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_FALSE);
#endif /* !NDEBUG */
			glfwWindowHint(GLFW_SRGB_CAPABLE, GL_TRUE);
			glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			GLFWwindow* window = glfwCreateWindow(800, 480, "Ynov - Engine Dev Starter Pack", nullptr, nullptr);
			if (!window)
				throw std::runtime_error("Unable to initialize GLFW");

			glfwMakeContextCurrent(window);
		}
	};
}
