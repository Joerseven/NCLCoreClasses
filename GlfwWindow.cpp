//
// Created by jdhyd on 12/15/2023.
//

#include "GlfwWindow.h"


GlfwWindow::GlfwWindow(const std::string &title, int sizeX, int sizeY, bool fullScreen, int offsetX, int offsetY) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    internalWindow = glfwCreateWindow(sizeX, sizeY, title.c_str(), nullptr, nullptr);
    if (internalWindow == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        init = false;
        return;
    }

    glfwMakeContextCurrent(internalWindow);

    init = true;
}

bool GlfwWindow::InternalUpdate() {
    glfwSwapBuffers(internalWindow);
    glfwPollEvents();

    return !glfwWindowShouldClose(internalWindow);
}

GlfwWindow::~GlfwWindow() {
    glfwTerminate();
}
