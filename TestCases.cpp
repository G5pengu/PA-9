#include "TestCases.hpp"

#include <fstream>
#include <vector>

//Name: Zac Calvert & Sam P.
//Date: 4/29/2026

using std::vector;

TestCases::TestCases()
{
    //constructor - does not do anything
}

//verifies that sprites and fonts can be initialized correctly without opening the render window

//used ai for init()
//Warning: I am not a good ai input engineer
//prompt: if (!texture.loadFromFile("assets/bg0.png"))
//{
//    all_works = false;
//}
//do this but for all of these files
bool TestCases::init()
{
    std::cout << "[initTest] Starting asset initialization test...\n";
    bool all_works = true;

    // -------------------------------------------------------------------------
    // TEXTURES
    // -------------------------------------------------------------------------
    sf::Texture tex_bg1;
    if (!tex_bg1.loadFromFile("assets/bg1.png"))
    {
        std::cerr << "[initTest] FAIL: bg1.png\n";
        all_works = false;
    }
    else std::cout << "[initTest] PASS: bg1.png\n";

    sf::Texture tex_leaderboard;
    if (!tex_leaderboard.loadFromFile("assets/leaderBoard.png"))
    {
        std::cerr << "[initTest] FAIL: leaderBoard.png\n";
        all_works = false;
    }
    else std::cout << "[initTest] PASS: leaderBoard.png\n";

    // -------------------------------------------------------------------------
    // FONTS
    // -------------------------------------------------------------------------

    sf::Font font_comic;
    if (!font_comic.openFromFile("assets/comic.ttf"))
    {
        std::cerr << "[initTest] FAIL: comic.ttf\n";
        all_works = false;
    }
    else std::cout << "[initTest] PASS: comic.ttf\n";

    // -------------------------------------------------------------------------
    // SOUND BUFFERS (.wav / .ogg)
    // -------------------------------------------------------------------------
    sf::SoundBuffer buf_wav_example;
    if (!buf_wav_example.loadFromFile("assets/file_example_WAV_1MG.wav"))
    {
        std::cerr << "[initTest] FAIL: file_example_WAV_1MG.wav\n";
        all_works = false;
    }
    else std::cout << "[initTest] PASS: file_example_WAV_1MG.wav\n";

    sf::SoundBuffer buf_sample3s;
    if (!buf_sample3s.loadFromFile("assets/sample-3s.wav"))
    {
        std::cerr << "[initTest] FAIL: sample-3s.wav\n";
        all_works = false;
    }
    else std::cout << "[initTest] PASS: sample-3s.wav\n";

    sf::SoundBuffer buf_speech;
    if (!buf_speech.loadFromFile("assets/sample-speech-1m.wav"))
    {
        std::cerr << "[initTest] FAIL: sample-speech-1m.wav\n";
        all_works = false;
    }
    else std::cout << "[initTest] PASS: sample-speech-1m.wav\n";

    sf::SoundBuffer buf_pipe;
    if (!buf_pipe.loadFromFile("assets/pipe.ogg"))
    {
        std::cerr << "[initTest] FAIL: pipe.ogg\n";
        all_works = false;
    }
    else std::cout << "[initTest] PASS: pipe.ogg\n";

    sf::SoundBuffer buf_song;
    if (!buf_song.loadFromFile("assets/song.ogg"))
    {
        std::cerr << "[initTest] FAIL: song.ogg\n";
        all_works = false;
    }
    else std::cout << "[initTest] PASS: song.ogg\n";

    // -------------------------------------------------------------------------
    // CSV FILES  (just verify they open — no SFML type for these)
    // -------------------------------------------------------------------------
    for (const std::string& csv : { std::string("assets/LeaderBoard.csv"), std::string("assets/Test.csv") })
    {
        std::ifstream f(csv);
        if (!f.is_open())
        {
            std::cerr << "[initTest] FAIL: " << csv << "\n";
            all_works = false;
        }
        else std::cout << "[initTest] PASS: " << csv << "\n";
    }

    // -------------------------------------------------------------------------
    // RESULT
    // -------------------------------------------------------------------------
    if (all_works)
        std::cout << "[initTest] All assets loaded successfully.\n";
    else
        std::cerr << "[initTest] One or more assets FAILED to load.\n";

    return all_works;
}

//calls a test function that is in "net.cpp"
void TestCases::net()
{
    netTest();
}

//verifies that sf::Keyboard::isKeyPressed() compiles and returns without crashing.
//Does not require a window or any user interaction.

//used ai for this test function
bool TestCases::input()
{
    std::cout << "[inputTest] Starting input test...\n";
    bool all_works = true;

    // -------------------------------------------------------------------------
    // KEYBOARD
    // NOTE: Replace these with YOUR input function here
    // -------------------------------------------------------------------------
    struct KeyCheck
    {
        sf::Keyboard::Key key;
        std::string       name;
    };

    const std::vector<KeyCheck> keys =
    {
        { sf::Keyboard::Key::W,      "W"      },
        { sf::Keyboard::Key::A,      "A"      },
        { sf::Keyboard::Key::S,      "S"      },
        { sf::Keyboard::Key::D,      "D"      },
        { sf::Keyboard::Key::Up,     "Up"     },
        { sf::Keyboard::Key::Down,   "Down"   },
        { sf::Keyboard::Key::Left,   "Left"   },
        { sf::Keyboard::Key::Right,  "Right"  },
        { sf::Keyboard::Key::Enter,  "Enter"  },
        { sf::Keyboard::Key::Escape, "Escape" },
        { sf::Keyboard::Key::Space,  "Space"  },
    };

    for (const auto& k : keys)
    {
        try
        {
            bool state = sf::Keyboard::isKeyPressed(k.key);
            std::cout << "[inputTest] PASS: " << k.name
                << " polled successfully (currently "
                << (state ? "pressed" : "not pressed") << ")\n";
        }
        catch (...)
        {
            std::cerr << "[inputTest] FAIL: " << k.name << " threw an exception.\n";
            all_works = false;
        }
    }

    // -------------------------------------------------------------------------
    // RESULT
    // -------------------------------------------------------------------------
    if (all_works)
        std::cout << "[inputTest] All input checks passed.\n";
    else
        std::cerr << "[inputTest] One or more input checks FAILED.\n";

    return all_works;
}

bool TestCases::arrowSpawn()
{
    std::cout << "[arrowSpawnTest] Starting arrow spawn test...\n";
    bool all_works = true;

    // -------------------------------------------------------------------------
    // SCREEN SETUP
    // NOTE: Replace these with YOUR screen width/height variables here
    // -------------------------------------------------------------------------
    const float screenWidth = 800.f;
    const float screenHeight = 600.f;
    const float arrowSpacing = screenWidth / 5.f;

    // -------------------------------------------------------------------------
    // SPAWN ALL 4 ARROWS OFF BOTTOM OF SCREEN
    // NOTE: Replace spawn positions with YOUR arrow spawn function here
    // -------------------------------------------------------------------------
    std::vector<Arrow> arrows =
    {
        Arrow(Direction::LEFT),
        Arrow(Direction::DOWN),
        Arrow(Direction::UP),
        Arrow(Direction::RIGHT),
    };

    float spawnY = screenHeight + 50.f;   // just below screen
    arrows[0].setPosition({ arrowSpacing * 1.f, spawnY });
    arrows[1].setPosition({ arrowSpacing * 2.f, spawnY });
    arrows[2].setPosition({ arrowSpacing * 3.f, spawnY });
    arrows[3].setPosition({ arrowSpacing * 4.f, spawnY });

    // -------------------------------------------------------------------------
    // TEST 1 — All arrows spawn off screen (below screenHeight)
    // -------------------------------------------------------------------------
    for (const auto& arrow : arrows)
    {
        if (arrow.getPosition().y <= screenHeight)
        {
            std::cerr << "[arrowSpawnTest] FAIL: Arrow did not spawn off screen. Y: "
                << arrow.getPosition().y << "\n";
            all_works = false;
        }
        else
        {
            std::cout << "[arrowSpawnTest] PASS: Arrow spawned off screen at Y: "
                << arrow.getPosition().y << "\n";
        }
    }

    // -------------------------------------------------------------------------
    // TEST 2 — All arrows have distinct X positions (no overlap)
    // -------------------------------------------------------------------------
    for (int i = 0; i < (int)arrows.size(); i++)
    {
        for (int j = i + 1; j < (int)arrows.size(); j++)
        {
            if (arrows[i].getPosition().x == arrows[j].getPosition().x)
            {
                std::cerr << "[arrowSpawnTest] FAIL: Two arrows share X position: "
                    << arrows[i].getPosition().x << "\n";
                all_works = false;
            }
        }
    }
    if (all_works)
        std::cout << "[arrowSpawnTest] PASS: All arrows have distinct X positions.\n";

    // -------------------------------------------------------------------------
    // TEST 3 — Arrows are ordered left to right by X position
    // -------------------------------------------------------------------------
    for (int i = 0; i < (int)arrows.size() - 1; i++)
    {
        if (arrows[i].getPosition().x >= arrows[i + 1].getPosition().x)
        {
            std::cerr << "[arrowSpawnTest] FAIL: Arrows are not ordered left to right.\n";
            all_works = false;
        }
    }
    if (all_works)
        std::cout << "[arrowSpawnTest] PASS: Arrows ordered left to right.\n";

    // -------------------------------------------------------------------------
    // TEST 4 — Direction enum is correctly assigned
    // -------------------------------------------------------------------------
    const std::vector<Direction> expectedDirs =
    {
        Direction::LEFT, Direction::DOWN, Direction::UP, Direction::RIGHT
    };
    const std::vector<std::string> dirNames = { "LEFT", "DOWN", "UP", "RIGHT" };

    for (int i = 0; i < (int)arrows.size(); i++)
    {
        if (arrows[i].direction != expectedDirs[i])
        {
            std::cerr << "[arrowSpawnTest] FAIL: Arrow " << dirNames[i]
                << " has wrong direction assigned.\n";
            all_works = false;
        }
        else
        {
            std::cout << "[arrowSpawnTest] PASS: Arrow " << dirNames[i]
                << " direction correctly assigned.\n";
        }
    }

    // -------------------------------------------------------------------------
    // TEST 5 — HitRating initializes to NONE
    // -------------------------------------------------------------------------
    for (int i = 0; i < (int)arrows.size(); i++)
    {
        if (arrows[i].rating != HitRating::NONE || arrows[i].wasGoodHit != false)
        {
            std::cerr << "[arrowSpawnTest] FAIL: Arrow " << dirNames[i]
                << " did not initialize with clean hit state.\n";
            all_works = false;
        }
        else
        {
            std::cout << "[arrowSpawnTest] PASS: Arrow " << dirNames[i]
                << " initialized with clean hit state.\n";
        }
    }

    // -------------------------------------------------------------------------
    // RESULT
    // -------------------------------------------------------------------------
    if (all_works)
        std::cout << "[arrowSpawnTest] All arrow spawn checks passed.\n";
    else
        std::cerr << "[arrowSpawnTest] One or more arrow spawn checks FAILED.\n";

    return all_works;
}

//Ai was used here "make me a test function that tests open the sfml window"
bool TestCases::windowTest()
{
    cout << "Window Test start....\n";

    bool all_works = true; 

    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML TEST");

    if (!window.isOpen())
    {
        std::cerr << "[windowTest] FAIL: Window failed to open.\n";
        return false;
    }
    std::cout << "[windowTest] PASS: Window opened successfully.\n";

    if (window.getSize().x != 1920u || window.getSize().y != 1080u)
    {
        std::cerr << "[windowTest] FAIL: Window size incorrect. "
            << "Got: " << window.getSize().x << "x" << window.getSize().y << "\n";
        all_works = false;
    }
    else
    {
        std::cout << "[windowTest] PASS: Window size correct (1920x1080).\n";
    }


    if (window.getTitle() != "SFML TEST")
    {
        std::cerr << "[windowTest] FAIL: Window title incorrect.\n";
        all_works = false;
    }
    else
    {
        std::cout << "[windowTest] PASS: Window title correct.\n";
    }

    sf::Clock clock;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if (clock.getElapsedTime().asSeconds() >= 3.f)
        {
            window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    std::cout << "[windowTest] PASS: Window closed cleanly.\n";

    if (all_works)
    {
        std::cout << "[windowTest] All window checks passed.\n";
    }
    else
    {
        std::cerr << "[windowTest] One or more window checks FAILED.\n";
    }

    return all_works;
}
