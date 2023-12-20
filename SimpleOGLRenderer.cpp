//
// Created by jdhyd on 12/17/2023.
//

#include "SimpleOGLRenderer.h"

SimpleOGLRenderer::SimpleOGLRenderer(Window &w) : RendererBase(w) {
    initState = false;
    w.GetScreenSize();

}

SimpleOGLRenderer::~SimpleOGLRenderer() {

}

void SimpleOGLRenderer::OnWindowResize(int w, int h) {
    glViewport(0,0,w,h);
}

void SimpleOGLRenderer::BeginFrame() {

}

void SimpleOGLRenderer::RenderFrame() {

}

void SimpleOGLRenderer::EndFrame() {

}

void SimpleOGLRenderer::SwapBuffers() {

}
