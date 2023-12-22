//
// Created by jdhyd on 12/15/2023.
//

#ifndef NCLCORECLASSES_GLFWWINDOW_H
#define NCLCORECLASSES_GLFWWINDOW_H

#include "Window.h"
#include "GLFW/glfw3.h"
#include "GlfwKeyboard.h"
#include "GlfwMouse.h"

class GlfwWindow : public NCL::Window {
public:
    GlfwWindow(const std::string& title, int sizeX, int sizeY, bool fullScreen, int offsetX, int offsetY);
    ~GlfwWindow() override;
    bool InternalUpdate() override;
private:
    GLFWwindow* internalWindow;
    GlfwKeyboard* glfwKeyboard;
    GlfwMouse* glfwMouse;

};


#endif //NCLCORECLASSES_GLFWWINDOW_H
