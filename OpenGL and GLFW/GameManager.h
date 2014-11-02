#pragma once
#include <glfw3.h>
#include "RenderSystem.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

class GameManager {
private:
    bool _running;
    GLFWwindow *_window;
    RenderSystem *_renderSystem;
    GameManager(bool, GLFWwindow*);
    ~GameManager(void);
public:
    static GameManager& getGameManager(void);
    static void destroyGameManager(void);
    void runGameLoop(void);
};
