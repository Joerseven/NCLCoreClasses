//
// Created by Joe Hydon on 22/12/2023.
//

#include "GlfwMouse.h"

GlfwMouse::GlfwMouse(GLFWwindow *window) {
    glfwSetCursorPosCallback(window, [](GLFWwindow *w, double xpos, double ypos){
        auto mouse = (GlfwMouse*)Window::GetMouse();
        mouse->absolutePosition = Vector2((float)xpos, (float)ypos);
    });
}
