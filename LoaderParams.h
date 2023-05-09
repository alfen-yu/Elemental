#ifndef __LoaderParams__
#define __LoaderParams
#include <iostream>

class LoaderParams
{
private:
    // variables for loading an image
    int x, y;
    std::string textureID;
    int srcWidth, srcHeight;
    int destWidth, destHeight;

public:
    LoaderParams(int lx, int ly, int swidth, int sheight, int dwidth, int dheight, std::string lTextureID) : x(lx), y(ly),
                                                                                                      srcWidth(swidth),
                                                                                                      srcHeight(sheight),
                                                                                                      destWidth(dwidth),
                                                                                                      destHeight(dheight),
                                                                                                      textureID(lTextureID) {}

    // getter functions to the variables
    int getX() const { return x; }
    int getY() const { return y; }
    int getSrcWidth() const { return srcWidth; }
    int getSrcHeight() const { return srcHeight; }
    int getDestWidth() const { return destWidth; }
    int getDestHeight() const { return destHeight; }
    std::string getID() const { return textureID; }
};

#endif