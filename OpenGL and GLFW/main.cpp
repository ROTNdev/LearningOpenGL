#include "GameManager.h"

int main() {
    GameManager *gameManager = &GameManager::getGameManager();
    system("pause");
    GameManager::destroyGameManager();
}
