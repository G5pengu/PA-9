#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Arrow.hpp"
#include "NoteTimeCalc.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
//#include <Windows.h>

const float LANE_X[4] = { 780.f, 900.f, 1020.f, 1140.f };
const float HIT_LINE_Y = 540.f;
const float LANE_WIDTH = 100.f;
const int MAX_MISSES = 5;

class Game {
public:
    Game();
    ~Game();
    void run();

    bool gameOver;


private:
    // Window
    sf::RenderWindow window;

    sf::Music music;

    // Background
    sf::Texture bgTex[2];
    sf::Sprite* bgSprites[2];

    sf::Texture win;
    sf::Sprite* winSprite;
    int bgFrame;
    float bgTimer;
    float bgFrameRate;

    // Game state
    std::vector<Arrow> arrows;
    int score;
    int missCount;
    NoteTimeCalc noteTime;
    sf::Clock songClock;
    int currentBeat;
    float travelTime;
    float ratingTimer;

    // Methods
    void processEvents();
    void update(float dt);
    void draw();
    void handleKeyPress(sf::Keyboard::Key key);
    void spawnArrow();
    void detectMisses();
    static Direction indexToDir(int i);
};