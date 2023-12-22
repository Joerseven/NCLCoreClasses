//
// Created by Joe Hydon on 21/12/2023.
//

#include "GlfwKeyboard.h"

GlfwKeyboard::GlfwKeyboard(GLFWwindow* gWindow) {
    glfwSetKeyCallback(gWindow, [](GLFWwindow* w, int key, int scancode, int action, int mods){
        if (key < NCL::KeyCodes::MAXVALUE) {
            auto thisKeyboard = (GlfwKeyboard*)Window::GetKeyboard();
            if (action == GLFW_PRESS) {
                thisKeyboard->keyStates[key] = true;
            }
            if (action == GLFW_RELEASE) {
                thisKeyboard->keyStates[key] = false;
            }
        }
    });
}
