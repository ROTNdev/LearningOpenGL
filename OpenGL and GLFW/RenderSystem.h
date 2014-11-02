#pragma once
#include <glfw3.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

class RenderSystem {
private:
    GLFWwindow *_window;
    RenderSystem();
    ~RenderSystem();
public:
    static RenderSystem& getRenderSystem();
    static void destroyRenderSystem();
    void render();
};

