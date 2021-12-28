#include "Config.h"


void initBackground() {
	bgTexture.loadFromFile("images/background.png");
	frameTexture.loadFromFile("images/tiles.png");
	tilesTexture.loadFromFile("images/tiles.png");

	bg.setTexture(bgTexture);
	frame.setTexture(frameTexture);
	tiles.setTexture(tilesTexture);
}