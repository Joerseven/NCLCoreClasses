//
// Created by jdhyd on 12/17/2023.
//

#ifndef NCLCORECLASSES_SIMPLEOGLRENDERER_H
#define NCLCORECLASSES_SIMPLEOGLRENDERER_H

#include "KHR\khrplatform.h"
#include "glad\gl.h"
#include "KHR/WGLext.h"
#include "Window.h"
#include "RendererBase.h"

using namespace NCL;

class SimpleOGLRenderer : public RendererBase {
public:
    SimpleOGLRenderer(Window& w);
    ~SimpleOGLRenderer();

    void OnWindowResize(int w, int h) override;
    bool HasInitialised() const override {
        return initState;
    }

protected:
    void BeginFrame() override;
    void RenderFrame() override;
    void EndFrame() override;
    void SwapBuffers() override;


private:
    bool initState;


};


#endif //NCLCORECLASSES_SIMPLEOGLRENDERER_H
