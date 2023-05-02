#ifndef __LoaderParams__
#define __LoaderParams
#include <iostream>

class LoaderParams
{
private:
    // variables for loading an image
    int x, y;
    std::string textureID;
    int width, height;

public:
    LoaderParams(int lx, int ly, int lwidth, int lheight, std::string lTextureID) : x(lx), y(ly),
                                                                                                      width(lwidth),
                                                                                                      height(lheight),
                                                                                                      textureID(lTextureID) {}

    // getter functions to the variables
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::string getID() const { return textureID; }
};

#endif