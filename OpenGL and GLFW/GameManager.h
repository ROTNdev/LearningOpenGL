#include <iostream>
#include <glfw3.h>

class GameManager {
private:
    GameManager();
    ~GameManager();
public:
    static GameManager& getGameManager();
    static void destroyGameManager();
};
