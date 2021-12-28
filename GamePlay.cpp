#include "GamePlay.h"

GamePlay::GamePlay() {
    initBackground();
    setup();
}

GamePlay::~GamePlay() {
    delete this;
}

void GamePlay::setup() {
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), "The Game!", Style::Fullscreen);
}

void GamePlay::PressOption() {
    Event e;
    while (window.pollEvent(e))
    {
        if (e.type == Event::Closed)
            window.close();

        if (e.type == Event::KeyPressed)
            if (e.key.code == Keyboard::Up)
                rotate = true;
            else if (e.key.code == Keyboard::Left)
                dx = -1;
            else if (e.key.code == Keyboard::Right)
                dx = 1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down))
        delay = 0.05;
}

void GamePlay::tileDraw() {
    for (int i = 0; i < 4; i++)
    {
        tiles.setTextureRect(IntRect(color * 18, 0, 18, 18));
        tiles.setPosition(tile.getCurrentXAtIndex(i) * 18, tile.getCurrentYAtIndex(i) * 18);
        tiles.move(offsetX, offsetY); //offset
        window.draw(tiles);
    }
}

void GamePlay::tableDraw() {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++)
        {
            if (field[i][j] == 0)
                continue;

            if (field[i][j] != 0) {
                tiles.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                tiles.setPosition(j * 18, i * 18);
                tiles.move(28, 31); //offset
                window.draw(tiles);
            }
        }
    }
}

void GamePlay::draw() {
    window.clear(Color::White);
    window.draw(bg);

    tableDraw();

    tileDraw();

    window.draw(frame);
    window.display();
}

void GamePlay::resetTileState() {
    dx = 0;
    rotate = 0;
    delay = 0.3;
}

void GamePlay::checkBingoLine() {
    int k = nRows - 1;
    for (int i = nRows - 1; i > 0; i--)
    {
        int count = 0;
        for (int j = 0; j < nCols; j++)
        {
            if (field[i][j])
                count++;
            field[k][j] = field[i][j];
        }
        if (count < nCols)
            k--;
    }
}

void GamePlay::operation() {
    while (window.isOpen())
    {
        _time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += _time;

        PressOption();

        ////// <- Move -> ///
        if (dx)
            tile.move(dx);

        //////Rotate//////
        if (rotate)
        {
            tile.rotate();
        }

        ///////Tick//////
        if (timer > delay)
        {
            tile.tick();
            timer = 0;
        }

        ///////check lines//////////
        checkBingoLine();

        resetTileState();
        
        draw();
    }
}