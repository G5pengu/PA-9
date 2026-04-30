#include "../Header/Menu.hpp"

Menu::Menu()
{
    font.openFromFile("assets/comic.ttf"); 
}
 
Menu::~Menu()
{}

void Menu::display_leaders()
{
    cat();
    RenderWindow window(sf::VideoMode({ 1920,1080 }), "SFML TEST");
    Vector2f btnSize(140, 40);

    RectangleShape exitBtn(btnSize);

    Text title(font, "Leaderboard", 80);
    title.setPosition(Vector2f(720, 100));

    Texture leaderOutline;
    leaderOutline.loadFromFile("assets/leaderBoard.png");
    Sprite Loutline(leaderOutline);

    // Center X
    float centerX = 1080 / 2;

    // Bottom corner button (Exit)
    exitBtn.setPosition(Vector2f(250, 820));
    exitBtn.setFillColor(Color::Green);

    // Text for button
    Text exitText(font, "Exit", 20);
    exitText.setFillColor(Color::Black);


    Text backText(font, "Back", 40);

    // center text inside button

    exitText.setPosition(
        Vector2f(exitBtn.getPosition().x + exitBtn.getSize().x / 3,
            exitBtn.getPosition().y + exitBtn.getSize().y / 5));


    // ------------------------------
    // Leaderboard text (10 entries)
    // ------------------------------
    vector<Text> entries;

    for (int i = 0; i < 10; i++)
    {
        Leader leader = getLeader(i);
        string line = to_string(i + 1) + ": " + leader.user + " : " + to_string(leader.score).substr(0, 5) + " pts";

        Text text(font, line, 30);
        text.setPosition(Vector2f(800, 300 + i * 60)); // spaced vertically

        entries.push_back(text);
    }


    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();

            if (event->is<Event::MouseButtonPressed>())
            {
                Vector2f mousePos = (Vector2f)Mouse::getPosition(window);

                if (exitBtn.getGlobalBounds().contains(mousePos))
                {
                    cout << "clicked\n";
                    window.close(); // go back to main menu
                    menu();
                }
            }
        }

        window.clear(Color::Black);
        window.draw(Loutline);
        window.draw(title);
        //ai 
        for (auto& e : entries)
            window.draw(e);

        window.draw(exitBtn);
        window.draw(exitText);

        window.display();
    }

}
void Menu::menu()
{
    int width = 1920;
    int height = 1080;
    RenderWindow window(sf::VideoMode({ 1920,1080 }), "SFML TEST");
    int state = 1;
    int timer = 0;

    // Buttons
    Vector2f btnSize(250, 80);

    RectangleShape playBtn(btnSize);
    RectangleShape testBtn(btnSize);
    RectangleShape hwtoBtn(btnSize);
    RectangleShape leaderBtn(btnSize);
    RectangleShape exitBtn(btnSize);

    Texture back1;
    Texture back2;

    back1.loadFromFile("assets/Menu2.png");
    back2.loadFromFile("assets/Menu.png");

    Sprite background(back1);
    background.setScale(Vector2f(1.55,1.6));

    // Center X
    int x = 0;
    float centerX = 1920/7;
    float startY = 75;
    float spacing = 1920/7;

    playBtn.setPosition(Vector2f(centerX + spacing * x++, startY ));
    hwtoBtn.setPosition(Vector2f(centerX + spacing * x++, startY ));
    testBtn.setPosition(Vector2f(centerX + spacing * x++, startY ));
    leaderBtn.setPosition(Vector2f(centerX + spacing * x++, startY ));
    exitBtn.setPosition(Vector2f(centerX + spacing * x++, startY ));

    playBtn.setFillColor(Color::Color(220,20,60));
    hwtoBtn.setFillColor(Color::Color(128, 128, 128));
    testBtn.setFillColor(Color::Color(220, 20, 60));
    leaderBtn.setFillColor(Color::Color(128, 128, 128));
    exitBtn.setFillColor(Color::Color(220, 20, 60));

    // Text
    Text playText(font, "Play", 30);
    Text hwtoText(font, "How to Play", 30);
    Text TestText(font, "Test Cases", 30);
    Text leaderText(font, "Leaderboard", 30);
    Text exitText(font, "Exit", 30);
 
    x = 0;
    playText.setPosition(Vector2f(centerX + spacing * x++, startY ));
    hwtoText.setPosition(Vector2f(centerX + spacing * x++, startY ));
    TestText.setPosition(Vector2f(centerX + spacing * x++, startY ));
    leaderText.setPosition(Vector2f(centerX + spacing * x++, startY ));
    exitText.setPosition(Vector2f(centerX + spacing * x++, startY ));

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {

            if (event->is<Event::MouseButtonPressed>())
            {
                Vector2i mousePos = Mouse::getPosition(window);
                if (event->is<Event::MouseButtonPressed>())
                {
                    Vector2i mousePos = Mouse::getPosition(window);

                    if (playBtn.getGlobalBounds().contains((Vector2f)mousePos))
                    {
                        window.close();
                        run();
                    }
                    if (hwtoBtn.getGlobalBounds().contains((Vector2f)mousePos))
                    {
                        cout << "how to button\n";
                        window.close();
                        howto();
                    }
                    if (testBtn.getGlobalBounds().contains((Vector2f)mousePos))
                    {
                        cout << "test cases\n";
                    }
                    if (leaderBtn.getGlobalBounds().contains((Vector2f)mousePos))
                    {
                        cout << "clicked leader\n";
                        window.close();
                        display_leaders();
                    }
                    if (exitBtn.getGlobalBounds().contains((Vector2f)mousePos))
                    {
                        cout << "clicked\n";
                        window.close();
                    }

                }


            }
        }
        if (timer > 60) {
            if (state ==1)
            {
                background.setTexture(back1);
                state *= -1;
                timer = 0;
            }
            else if (state == -1)
            {
                background.setTexture(back2);
                state *= -1;
                timer = 0;
            }
        }
        else
        {
            timer++;
        }

        window.clear();

        window.draw(background);

        window.draw(playBtn);
        window.draw(hwtoBtn);
        window.draw(testBtn);
        window.draw(leaderBtn);
        window.draw(exitBtn);

        window.draw(playText);
        window.draw(hwtoText);
        window.draw(TestText);
        window.draw(leaderText);
        window.draw(exitText);

        window.display();
    }


}
void Menu::howto()
{
    RenderWindow window(sf::VideoMode({ 1200,700 }), "How to Play");
    Texture x;
    x.loadFromFile("assets/howto.png");
    Sprite s(x);

    RectangleShape backbtn(Vector2f(100,50));
    backbtn.setFillColor(Color::Red);
    backbtn.setPosition(Vector2f(50,50));

    Text backtxt(font, "Back", 20);
    backtxt.setPosition(Vector2f(50, 50));

    while (window.isOpen()) 
    {
        while (auto event = window.pollEvent())
        {

            if (event->is<Event::MouseButtonPressed>())
            {
                Vector2i mousePos = Mouse::getPosition(window);
                if (event->is<Event::MouseButtonPressed>())
                {
                    Vector2i mousePos = Mouse::getPosition(window);
                    
                    if (backbtn.getGlobalBounds().contains((Vector2f)mousePos))
                    {
                        window.close();
                        menu();
                    }
                }
            }
        }
        window.draw(s);

        window.draw(backbtn);
        window.draw(backtxt);
        

        window.display();
    }


}
void Menu::canvas_test()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML TEST");

    int spacing = 100;
    sf::Vector2u size = window.getSize();

    // Store everything
    std::vector<sf::CircleShape> dots;
    std::vector<sf::Text> labels;

    for (int x = 0; x < (int)size.x; x += spacing)
    {
        for (int y = 0; y < (int)size.y; y += spacing)
        {
            // Dot
            sf::CircleShape dot(3.f);
            dot.setFillColor(sf::Color::White);
            dot.setPosition(Vector2f((float)x, (float)y));
            dots.push_back(dot);

            // Label
            std::string label = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
            sf::Text text(font, label, 20);
            text.setFillColor(sf::Color(150, 150, 150));
            text.setPosition(Vector2f((float)x, (float)y - 12.f));
            labels.push_back(text);
        }
    }

    // Main loop
    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        // Draw everything (fast, reused)
        for (auto& d : dots)
            window.draw(d);

        for (auto& t : labels)
            window.draw(t);

        window.display();
    }
}