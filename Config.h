#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf;

const int nRows = 20;
const int nCols = 10;

extern int figures[7][4] = {
    1, 3, 5, 7, // I
    2, 4, 5, 7, // Z
    3, 5, 4, 6, // S
    3, 5, 4, 7, // T
    2, 3, 5, 7, // L
    3, 5, 7, 6, // J
    2, 3, 4, 5, // O
};
extern int field[nRows][nCols] = { 0 };

extern int color = 1;

extern Texture bgTexture, frameTexture, tilesTexture;
extern Sprite tiles, bg, frame;

void initBackground();