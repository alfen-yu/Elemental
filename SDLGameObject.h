#ifndef __SDLGameObject__
#define __SDLGameObject__
#include "GameObject.h"

class SDLGameObject: public GameObject {
    protected:
        int x, y;
        int width, height;
        int currentFrame, currentRow;
        std::string textureID;
    public:
        SDLGameObject(const LoaderParams* params);

        virtual void draw();
        virtual void drawFrame();
        virtual void update();
        // virtual void clean();
};

#endif 