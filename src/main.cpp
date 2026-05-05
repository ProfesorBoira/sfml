#include "funciones.h"
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego"); // Crea una ventana window

    //INCIALIZACIÓN DE OBJETOS***********************************************************************************
    std::vector<Fran> plaga;plaga.reserve(20);
    std::vector<Beltran> bombas; bombas.reserve(1500);
    sf::Vector2f ponAqui, alaVamosPalla;


    for (int i = 0; i < 20; i++)
    {
        ponAqui.x=300+200*sin(2*3.14159265/20*i);
        ponAqui.y=300+200*cos(2*3.14159265/20*i);
        if (i<10){
            plaga.emplace_back(ponAqui);
        }    else {
            plaga.emplace_back(ponAqui);}
    }   

    //Javier javier("assets/javier.png", {40.f, 30.f}, 0.1f);
    Raul raul({300.f, 300.f});
    Beltran beltran({60.f, 60.f});
    Fran fran({600.f, 600.f});
    Uriel uriel({120.f, 120.f});
    Adrian adrian({140.f, 140.f});

    sf::Clock clock; // Inicializamos clock

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event; // Objeto event
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f posbomba(0.f, 0.f);
                    posbomba.x = event.mouseButton.x;
                    posbomba.y = event.mouseButton.y;
                        bombas.emplace_back(posbomba);

                }
            }
        }
 
        // Player mover
        // Movimiento con WASD
        sf::Vector2f dir(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            dir.y -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            dir.y += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            dir.x -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            dir.x += 1.f;
        raul.mover(dir, dt);
        alaVamosPalla=raul.getPosicion();
        for (auto& e : plaga)
        {
            e.actualizar(alaVamosPalla, dt/100);
        }
        for (auto& e : bombas)
        {
            e.actualizar({0.f, 0.f}, dt);
        }

       bombas.erase(
            std::remove_if(bombas.begin(), bombas.end(),[](const Beltran& e)
            {
                return !e.estaListo();
            }),
            bombas.end()
        );



        window.clear();
        
        for (auto& e : plaga)
        {
            e.dibujar(window);
        }
        for (auto& e : bombas)
        {
             e.dibujar(window);
        }

        beltran.dibujar(window);
        //javier.dibujar(window);
        fran.dibujar(window);
        raul.dibujar(window);
        uriel.dibujar(window);
        adrian.dibujar(window);
        
        window.display();
 


    }
}