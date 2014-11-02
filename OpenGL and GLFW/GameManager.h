#include <iostream>
#include <glfw3.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

class GameManager {
private:
    bool _running;
    GLFWwindow *_window;
    GameManager(bool, GLFWwindow*);
    ~GameManager(void);
public:
    static GameManager& getGameManager(void);
    static void destroyGameManager(void);
    void runGameLoop(void);
};
