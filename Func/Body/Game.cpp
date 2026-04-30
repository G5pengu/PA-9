#include "../Header/Game.hpp"

Direction Game::indexToDir(int i) {
    switch (i) {
    case 0: return Direction::LEFT;
    case 1: return Direction::DOWN;
    case 2: return Direction::UP;
    case 3: return Direction::RIGHT;
    default: return Direction::LEFT;
    }
}

/*spawnTimer(0.f)*/
Game::Game() : window(sf::VideoMode({ 1920u, 1080u }), "FNF Arrow Tester"), bgSprites{ nullptr, nullptr }, bgFrame(0), bgTimer(0.f), bgFrameRate(.4f), score(0),
missCount(0), gameOver(false), ratingTimer(0.f), noteTime(144.f, 1.5f), currentBeat(0), travelTime(1.5f)
{
    std::srand((unsigned)std::time(nullptr));
    window.setFramerateLimit(60);

    if (!bgTex[0].loadFromFile("assets/bg0.png")) {}
    else {
        bgSprites[0] = new sf::Sprite(bgTex[0]);
        sf::Vector2u s = bgTex[0].getSize();
        bgSprites[0]->setScale(sf::Vector2f(1920.f / s.x, 1080.f / s.y));
    }

    if (!bgTex[1].loadFromFile("assets/bg1.png")) {}
    else {
        bgSprites[1] = new sf::Sprite(bgTex[1]);
        sf::Vector2u s = bgTex[1].getSize();
        bgSprites[1]->setScale(sf::Vector2f(1920.f / s.x, 1080.f / s.y));

        if (gameOver && winSprite) {
            window.draw(*winSprite);

            soundManager.play_sound(1, 50.f);
        }
    }
}

Game::~Game() {
    delete bgSprites[0];
    delete bgSprites[1];
}

/*
soundManager

Music:

Index 0: song

Sounds:

Index 0: Buzzer
Index 1: Pipe

*/
void Game::run() {
    soundManager.input_music("assets/song.ogg");
    soundManager.play_music(0, 100, false);
    sf::SoundBuffer temp;
    temp.loadFromFile("assets/IncorrectBuzzer.ogg");
    soundManager.input_sound(temp);
    temp.loadFromFile("assets/pipe.ogg");
    soundManager.input_sound(temp);


    sf::Clock clock;
    while (window.isOpen() && !gameOver) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        draw();
    }
}

void Game::processEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

        if (!gameOver) {
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                handleKeyPress(keyPressed->code);
            }
        }
    }
}

void Game::handleKeyPress(sf::Keyboard::Key key) {
    Direction pressedDir;
    switch (key) {
    case sf::Keyboard::Key::Left: pressedDir = Direction::LEFT; break;
    case sf::Keyboard::Key::Down: pressedDir = Direction::DOWN; break;
    case sf::Keyboard::Key::Up: pressedDir = Direction::UP; break;
    case sf::Keyboard::Key::Right: pressedDir = Direction::RIGHT; break;
    default: return;
    }

    for (auto& arrow : arrows) {
        if (arrow.direction == pressedDir && !arrow.wasGoodHit) {
            HitRating result = arrow.tryHit(HIT_LINE_Y);
            if (result == HitRating::GREAT) {
                score += 500;
                ratingTimer = 0.6f;
            }
            else if (result == HitRating::GOOD) {

                score += 250;
                ratingTimer = 0.6f;
            }
            break;
        }
    }
}

void Game::update(float dt) {
    //if (gameOver) return;

    // Background animation
    bgTimer += dt;
    if (bgTimer >= bgFrameRate) {
        bgTimer = 0.f;
        bgFrame = (bgFrame + 1) % 2;
    }

    float songTime = soundManager.get_music_stream().getPlayingOffset().asSeconds() - noteTime.get_offset_time();
    float nextBeatTime = noteTime.beatToTime(currentBeat) - travelTime;

    if (songTime >= nextBeatTime) {
        spawnArrow();
        currentBeat++;
    }

    for (auto& a : arrows) {
        a.update(150.f * dt);
    }

    detectMisses();

    for (int i = (int)arrows.size() - 1; i >= 0; i--) {
        if (arrows[i].getPosition().y < -50.f || arrows[i].wasGoodHit) {
            arrows.erase(arrows.begin() + i);
        }
    }

    if (ratingTimer > 0.f) {
        ratingTimer -= dt;
    }

    if (missCount >= MAX_MISSES) {
        gameOver = true;
    }

    if (soundManager.get_music_stream().getStatus() == sf::Music::Status::Stopped && !gameOver) {
        gameOver = true;
         //play win music or whatever
    }
}

void Game::spawnArrow() {
    int randDir = std::rand() % 4;
    Arrow a(indexToDir(randDir));
    a.setPosition(sf::Vector2f(LANE_X[randDir], 1920.f));
    arrows.push_back(a);
}

void Game::detectMisses() {
    for (int i = 0; i < arrows.size(); i++) {
        if (arrows[i].getPosition().y < HIT_LINE_Y - 50.f && !arrows[i].wasGoodHit) {
            missCount++;
            arrows[i].wasGoodHit = true;
            ratingTimer = 0.6f;
            soundManager.play_sound(0, 50.f);
        }
    }
}

void Game::draw() {
    window.clear(sf::Color(30, 30, 30));

    if (bgSprites[bgFrame]) {
        window.draw(*bgSprites[bgFrame]);
    }

    if (!gameOver) {
        for (int i = 0; i < 4; i++) {
            Arrow::drawHitZones(window, HIT_LINE_Y, LANE_X[i] - LANE_WIDTH / 2.f, LANE_WIDTH);
        }

        for (auto& a : arrows) {
            window.draw(a);
        }
    }
    window.display();
}