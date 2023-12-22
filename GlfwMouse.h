//
// Created by Joe Hydon on 22/12/2023.
//

#ifndef NCLCORECLASSES_GLFWMOUSE_H
#define NCLCORECLASSES_GLFWMOUSE_H

#include "Mouse.h"
#include "GLFW/glfw3.h"
#include "Window.h"

using namespace NCL;


class GlfwMouse: public NCL::Mouse {
public:
    GlfwMouse(GLFWwindow* window);
};


#endif //NCLCORECLASSES_GLFWMOUSE_H
