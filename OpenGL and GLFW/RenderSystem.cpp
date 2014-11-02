#include "RenderSystem.h"


RenderSystem::RenderSystem() : _window(glfwGetCurrentContext()) {}


RenderSystem::~RenderSystem() {}

RenderSystem& RenderSystem::getRenderSystem() {
    static RenderSystem *renderSystem = 0;
    if (renderSystem == 0) {
        renderSystem = new RenderSystem();
        glClearColor(1, 1, 1, 1);
    }
    return *renderSystem;
}

void RenderSystem::destroyRenderSystem() {
    RenderSystem *system = &getRenderSystem();
    delete system;
}

void RenderSystem::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(_window);
    glfwPollEvents();
}
