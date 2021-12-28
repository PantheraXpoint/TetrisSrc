#include "Tile.h"

// Constructor
Tile::Tile() {

}

// Destructor
Tile::~Tile() {

}

// Handle tile's horizontal movement
void Tile::move(int dx)
{
	for (int i = 0; i < blocksCount; i++)
	{
		prevState[i].set(currentState[i]);
		currentState[i].setX(currentState[i].getX() + dx);
	}

	validate();
}

// Handle tile rotation
void Tile::rotate()
{
	Point center = currentState[1];

	for (int i = 0; i < blocksCount; i++)
	{
		int x = currentState[i].getY() - center.getY();
		int y = currentState[i].getX() - center.getX();
		currentState[i].setX(center.getX() - x);
		currentState[i].setY(center.getY() + y);
	}

	validate();
}

// Handle tile's ticking movement
void Tile::tick()
{
	for (int i = 0; i < blocksCount; i++)
	{
		prevState[i].set(currentState[i]);
		currentState[i].setY(currentState[i].getY() + 1);
	}

	if (!isValid()) getShape();
	

}

// Generate a new shape for the title
void Tile::getShape()
{
	// Handle tiles collision (mark collapsed tile position)
	for (int i = 0; i < blocksCount; i++)
	{
		field[prevState[i].getY()][prevState[i].getX()] = color;
	}

	// Change the current color
	color = 1 + rand() % 7;

	// Get the new figure type 
	int blockType = rand() % 7;
	for (int i = 0; i < blocksCount; i++)
	{
		currentState[i].setX(figures[blockType][i] % 2);
		currentState[i].setY(figures[blockType][i] / 2);
	}
}

// Check if a tile's position is valid.
bool Tile::isValid()
{
	for (int i = 0; i < blocksCount; i++)
	{
		if (currentState[i].getX() < 0 || currentState[i].getX() >= nRows || currentState[i].getY() >= nCols)
			return false;
		else if (field[currentState[i].getY()][currentState[i].getX()])
			return false;
	}

	return true;
}

// If the title is in out-of-range sets of positions, validate it.
void Tile::validate()
{
	if (!isValid()) {
		for (int i = 0; i < blocksCount; i++)
		{
			currentState[i].set(prevState[i]);
		}
	}
}

int Tile::getCurrentXAtIndex(int idx) {
	return currentState[idx].getX();
}

int Tile::getCurrentYAtIndex(int idx) {
	return currentState[idx].getY();
}

int Tile::getPrevXAtIndex(int idx) {
	return prevState[idx].getX();
}

int Tile::getPrevYAtIndex(int idx) {
	return prevState[idx].getY();
}
