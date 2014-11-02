#include "GameManager.h"

int main() {
    GameManager *gameManager = &GameManager::getGameManager();
    gameManager->runGameLoop();
    GameManager::destroyGameManager();
}
