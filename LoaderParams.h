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
    int currentFrame, currentRow;

public:
    LoaderParams(int lx, int ly, int swidth, int sheight, int dwidth, int dheight, std::string lTextureID, int cRow = 0, int cFrame = 0) : x(lx), y(ly),
                                                                                                      srcWidth(swidth),
                                                                                                      srcHeight(sheight),
                                                                                                      destWidth(dwidth),
                                                                                                      destHeight(dheight),
                                                                                                      currentRow(cRow),
                                                                                                      currentFrame(cFrame),
                                                                                                      textureID(lTextureID) {}

    // getter functions to the variables
    int getX() const { return x; }
    int getY() const { return y; }
    int getSrcWidth() const { return srcWidth; }
    int getSrcHeight() const { return srcHeight; }
    int getDestWidth() const { return destWidth; }
    int getDestHeight() const { return destHeight; }
    int getCurrentRow() const { return currentRow; }
    int getCurrentFrame() const { return currentFrame; }
    std::string getID() const { return textureID; }
};

#endif