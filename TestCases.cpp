#include "TestCases.hpp"
#include <fstream>
#include <vector>

//Name: Zac Calvert & Sam P.
//Date: 4/29/2026

using std::vector;

TestCases::TestCases()
{

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
bool TestCases::net()
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

bool TestCases::win()
{

}

bool TestCases::fail()
{

}