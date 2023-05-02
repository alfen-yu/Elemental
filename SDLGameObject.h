#ifndef __SDLGameObject__
#define __SDLGameObject__
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
protected:
    Vector2D position;     // position of an object
    Vector2D velocity;     // change in the position
    Vector2D acceleration; // gradual or just increase in velocity

    int width, height;
    int currentFrame, currentRow;

    std::string textureID;

public:
    SDLGameObject(const LoaderParams *params);

    virtual void draw();
    virtual void update();
    // virtual void clean();
};

#endif