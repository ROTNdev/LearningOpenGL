#include "GameManager.h"

GameManager::GameManager() {}

GameManager::~GameManager() {}

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

        gameManager = new GameManager();
        std::cout << "GameManager created!" << std::endl;
    }
    return *gameManager;
}

void GameManager::destroyGameManager() {
    GameManager *gameManager = &getGameManager();
    delete gameManager;
    std::cout << "GameManager is kill!" << std::endl;
    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}
