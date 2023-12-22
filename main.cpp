//
// Created by jdhyd on 12/15/2023.
//

#include "Window.h"
#include "GameTimer.h"

using namespace NCL;

int main() {
    Window* w = Window::CreateGameWindow("Cross platform glfw go brrr");

    if (!w->HasInitialised()) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }

    while (w->UpdateWindow()) {
        float dt = w->GetTimer().GetTimeDeltaSeconds();
        if (dt > 0.1f) {
            std::cout << "Skipping large delta time" << std::endl;
        }
        if (Window::GetKeyboard()->KeyPressed(KeyCodes::Q)) {
            std::cout << "Detecting key press" << std::endl;
        }
        std::cout << Window::GetMouse()->GetAbsolutePosition().x
        << " , "  << Window::GetMouse()->GetAbsolutePosition().y << std::endl;

    }
}