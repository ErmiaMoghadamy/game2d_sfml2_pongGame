#include <SFML/Graphics.hpp>


struct GameState {
    sf::RenderWindow &window;
    sf::Vector2f ball_r;
    sf::Vector2f ball_dr;
    double tick_speed;
};

int main() {
    sf::RenderWindow window( sf::VideoMode(720, 480), "Pong Game");
    sf::CircleShape shape(20.f);

    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(200, 200);

    GameState  game_state = {
        window,
        {200.f, 200.f},
        {23, 23},
        10
    };

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }


        // TODO: Implement 'Rocket Movement'
        // float dx = 0.f;
        // float dy = 0.f;
        //
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        //     sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        //     dx -= game_state.speed * dt;
        //     }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        //     sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        //     dx += game_state.speed * dt;
        //     }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
        //     sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        //     dy -= game_state.speed * dt;
        //     }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
        //     sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        //     dy += game_state.speed * dt;
        //     }

        sf::Vector2u window_size = window.getSize();
        int radius = shape.getRadius();

        if (game_state.ball_r.x + (game_state.ball_dr.x*dt*game_state.tick_speed) - radius <= 0 || game_state.ball_r.x + (game_state.ball_dr.x*dt*game_state.tick_speed) > window_size.x-radius) {
            game_state.ball_dr.x *= -1;
        }

        if (game_state.ball_r.y + (game_state.ball_dr.y*dt*game_state.tick_speed) - radius <= 0 || game_state.ball_r.y + (game_state.ball_dr.y*dt*game_state.tick_speed) > window_size.y-radius) {
            game_state.ball_dr.y *= -1;
        }

        game_state.ball_r.x += game_state.ball_dr.x*dt*game_state.tick_speed;
        game_state.ball_r.y += game_state.ball_dr.y*dt*game_state.tick_speed;
        shape.setPosition(game_state.ball_r);

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }
    return 0;
}