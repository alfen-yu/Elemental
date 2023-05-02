#ifndef __Cat__
#define __Cat__
#include "GameObject.h"

class Cat: public GameObject {
    public:
        void load(int x, int y, int width, int height, std::string textureID);
        void draw(SDL_Renderer* renderer);
        void update();
        // void clean();
};

#endif 