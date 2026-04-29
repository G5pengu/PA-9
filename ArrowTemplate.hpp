#include <SFML/Graphics.hpp>
#include <cmath>

class Triangle : public sf::ConvexShape {
public:
    Triangle(float size = 50.f) {
        setPointCount(3);
        setPoint(0, sf::Vector2f(0.f, -size));
        setPoint(1, sf::Vector2f(-size, size));
        setPoint(2, sf::Vector2f(size, size));
    }
};

enum class Direction { LEFT, DOWN, UP, RIGHT };
enum class HitRating { NONE, GOOD, GREAT };

class Arrow : public Triangle {
public:
    Direction direction;
    bool wasGoodHit;
    float speed;
    HitRating rating;

    static constexpr float GREAT_ZONE = 20.f;
    static constexpr float GOOD_ZONE = 50.f;

    Arrow(Direction dir, float size = 50.f) : Triangle(size), direction(dir), wasGoodHit(false), speed(1.f), rating(HitRating::NONE)
    {
        applyDirectionRotation();
        applyDirectionColor();
    }

    void update(float scrollSpeed) {
        move(sf::Vector2f(0.f, -scrollSpeed * speed));
    }

    HitRating tryHit(float hitLineY) {
        if (wasGoodHit) {
            return HitRating::NONE;
        }

        float dist = std::abs(getPosition().y - hitLineY);

        if (dist <= GREAT_ZONE) {
            rating = HitRating::GREAT;
            wasGoodHit = true;
        }
        else if (dist <= GOOD_ZONE) {
            rating = HitRating::GOOD;
            wasGoodHit = true;
        }
        else {
            rating = HitRating::NONE;
        }

        return rating;
    }

    static void drawHitZones(sf::RenderWindow& window, float hitLineY, float laneX, float laneWidth) {
        auto makeLine = [&](float y, sf::Color color) {
            sf::RectangleShape line(sf::Vector2f(laneWidth, 2.f));
            line.setFillColor(color);
            line.setPosition(sf::Vector2f(laneX, y));
            window.draw(line);
        };

        makeLine(hitLineY, sf::Color::White);
        makeLine(hitLineY - GREAT_ZONE, sf::Color(0, 255, 100));
        makeLine(hitLineY + GREAT_ZONE, sf::Color(0, 255, 100));
        makeLine(hitLineY - GOOD_ZONE, sf::Color(255, 200, 0));
        makeLine(hitLineY + GOOD_ZONE, sf::Color(255, 200, 0));
    }

private:
    void applyDirectionRotation() {
        switch (direction) {
        case Direction::LEFT: setRotation(sf::degrees(270.f));  break;
        case Direction::DOWN: setRotation(sf::degrees(180.f)); break;
        case Direction::UP: setRotation(sf::degrees(0.f));   break;
        case Direction::RIGHT: setRotation(sf::degrees(90.f)); break;
        }
    }

    void applyDirectionColor() {
        switch (direction) {
        case Direction::LEFT: setFillColor(sf::Color(0xC24B99FF)); break;
        case Direction::DOWN: setFillColor(sf::Color(0x00AAFFFF)); break;
        case Direction::UP: setFillColor(sf::Color(0x12FA05FF)); break;
        case Direction::RIGHT: setFillColor(sf::Color(0xFF5C5CFF)); break;
        }
    }
};