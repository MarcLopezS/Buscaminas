#ifndef MODE_H
#define MODE_H
#include "Game.h"

class Mode
{
    public:
        Mode();
        virtual ~Mode();

        std::string getMode();
        void setMode(std::string);

        void printMode();

        void playGame();

    protected:

    private:
        std::string mode;
};

#endif // MODE_H
