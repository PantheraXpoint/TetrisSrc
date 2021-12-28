#include "Tile.h"

class GamePlay {
private:
	int dx = 0;
	bool rotate = 0;
	float timer = 0, delay = 0.3;
	Clock clock;
	RenderWindow window;
	float _time;
	Tile tile;
	float offsetX = 28.0f;
	float offsetY = 31.0f;
public:
	GamePlay();

	~GamePlay();
	void setup();

	void operation();

	void PressOption();

	bool checkWin();

	void checkBingoLine();

	void play();

	void pause();

	void exit();

	void tileDraw();

	void tableDraw();

	void draw();

	void resetTileState();

};
