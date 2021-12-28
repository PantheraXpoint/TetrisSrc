#include "Config.h"

struct Point {
	int x;
	int y;

	void set(Point point) {
		x = point.x;
		y = point.y;
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
};

class Tile
{
private:
	Point currentState[4];
	Point prevState[4];
	const int blocksCount = 4;

public:
	Tile();
	~Tile();

	int getCurrentXAtIndex(int idx);

	int getCurrentYAtIndex(int idx);

	int getPrevXAtIndex(int idx);

	int getPrevYAtIndex(int idx);


	void move(int dx);
	void rotate();
	void tick();
	void getShape();
	bool isValid();
	void validate();
};
