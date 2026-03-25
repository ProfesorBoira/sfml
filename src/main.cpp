#include <SFML/Graphics.hpp>
   sf::RectangleShape player({50.f, 50.f});                    # Crea objeto player
   sf::RectangleShape enemy({40.f, 40.f});                     # Crea objeto enemy
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego");  # Crea una ventana window

 
    player.setFillColor(sf::Color::Green);
    player.setPosition(375.f, 500.f);


    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(200.f, 0.f);
 
    float enemySpeed = 200.f;
    float speed = 400.f;
 
    sf::Clock clock;                                            # Inicializamos clock

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event;                                        # Objeto event
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-speed * dt, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(speed * dt, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move(0, -speed * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move(0, speed * dt);

        enemy.move(0, enemySpeed * dt);
        player.rotate(speed/10*dt);

        window.clear();
        window.draw(player);
        window.draw(enemy);
        window.display();
    }
}