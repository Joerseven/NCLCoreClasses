//
// Created by jdhyd on 12/15/2023.
//

#ifndef NCLCORECLASSES_GLFWWINDOW_H
#define NCLCORECLASSES_GLFWWINDOW_H

#include "Window.h"
#include "glfw/glfw3.h"

class GlfwWindow : public NCL::Window {
public:
    GlfwWindow(const std::string& title, int sizeX, int sizeY, bool fullScreen, int offsetX, int offsetY);
    ~GlfwWindow();
    bool InternalUpdate() override;
private:
    GLFWwindow* internalWindow;

};


#endif //NCLCORECLASSES_GLFWWINDOW_H
