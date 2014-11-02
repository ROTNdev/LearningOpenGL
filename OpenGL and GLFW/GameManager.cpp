#include "GameManager.h"

GameManager::GameManager(bool running, GLFWwindow *window) : _running(running), _window(window), _renderSystem(&RenderSystem::getRenderSystem()) {}

GameManager::~GameManager() {
    RenderSystem::destroyRenderSystem();
}

GameManager& GameManager::getGameManager() {
    static GameManager *gameManager = 0;
    if (gameManager == 0) {

        glfwInit();

        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);

        GLFWwindow *window = glfwCreateWindow(1280, 720, "sp00ki fps", 0, 0);
        glfwMakeContextCurrent(window);

        gameManager = new GameManager(true, window);
    }
    return *gameManager;
}

void GameManager::destroyGameManager() {
    GameManager *gameManager = &getGameManager();
    delete gameManager;
    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GameManager::runGameLoop() {
    while (_running) {
        _running = !glfwWindowShouldClose(_window);
        _renderSystem->render();
    }
}
