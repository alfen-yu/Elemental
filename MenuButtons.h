#ifndef __MenuButtons__
#define __MenuButtons__

#include "SDLGameObject.h"
#include "InputHandler.h"

class MenuButtons : public SDLGameObject {
    private:
        enum button_state {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };

        // implementing function pointers that handle the game states
        void (*callback) (); // C styled function pointers
        bool released;

    public:
        MenuButtons(const LoaderParams* params, void (*callback)());

        virtual void draw();
        virtual void update();
        virtual void clean();
};

#endif