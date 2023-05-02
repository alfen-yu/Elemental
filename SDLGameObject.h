#ifndef __SDLGameObject__
#define __SDLGameObject__
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject: public GameObject {
    protected:
        Vector2D position;
        int x, y;
        int width, height;
        int currentFrame, currentRow;
        std::string textureID;
    public:
        SDLGameObject(const LoaderParams* params);

        virtual void draw();
        virtual void update();
        // virtual void clean();
};

#endif 