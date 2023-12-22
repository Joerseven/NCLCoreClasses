//
// Created by Joe Hydon on 21/12/2023.
//

#ifndef NCLCORECLASSES_GLFWKEYBOARD_H
#define NCLCORECLASSES_GLFWKEYBOARD_H

#include "GlfwKeyboard.h"
#include "GLFW/glfw3.h"
#include "Keyboard.h"
#include "Window.h"

using namespace NCL;

class GlfwKeyboard : public NCL::Keyboard {
public:
    GlfwKeyboard(GLFWwindow* gWindow);
};


#endif //NCLCORECLASSES_GLFWKEYBOARD_H
