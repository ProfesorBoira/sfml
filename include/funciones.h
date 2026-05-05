#pragma once
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>
#include <cmath>

class Javier
{
public:
    Javier(const std::string &rutaPNG, sf::Vector2f posicion, float escala = 1.f);
    bool estaListo() const;
    void setPosicion(sf::Vector2f posicion);
    void mover(sf::Vector2f direccion, float dt);
    void setVelocidad(float v);
    void setEscala(float escala);
    void setRotacion(float angulo);
    void rotar(float grados);
    sf::Vector2f getPosicion() const;
    void dibujar(sf::RenderWindow &ventana) const;

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    bool listo;
};

class Raul
{
public:
    Raul(const sf::Vector2f posicion);
    bool estaListo() const;
    void setPosicion(sf::Vector2f posicion);
    sf::Vector2f getPosicion() const;
    void mover(sf::Vector2f direccion, float dt);
    void dibujar(sf::RenderWindow &ventana) const;

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    bool listo;
};

class Fran
{
public:
    Fran(const sf::Vector2f posicion);
    bool estaListo() const;
    void setPosicion(sf::Vector2f posicion);
    void mover(sf::Vector2f direccion, float dt);
    void actualizar(sf::Vector2f destino, float dt);
    void dibujar(sf::RenderWindow &ventana) const;

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    bool listo;
};

class Beltran
{
public:
    Beltran(const sf::Vector2f posicion);
    Beltran(const Beltran& otro);         // constructor de copia  ← añadir
    Beltran& operator=(const Beltran& otro); // asignación         ← añadir
    bool estaListo() const;
    void setPosicion(sf::Vector2f posicion);
    void mover(sf::Vector2f direccion, float dt);
    void actualizar(sf::Vector2f destino, float dt);
    void dibujar(sf::RenderWindow &ventana) const;

private:
    sf::Texture textura,exp1,exp2,exp3;
    sf::Sprite sprite;
    float velocidad;
    bool listo;
    float tiempo;
    int estado;  //1=vivo, 2=exp1, 3=exp2, 4=exp3
};

class Uriel
{
public:
    Uriel(const sf::Vector2f posicion);
    bool estaListo() const;
    void setPosicion(sf::Vector2f posicion);
    void mover(sf::Vector2f direccion, float dt);
    void actualizar(sf::Vector2f destino, float dt);
    void dibujar(sf::RenderWindow &ventana) const;

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    bool listo;
};

class Adrian
{
public:
    Adrian(const sf::Vector2f posicion);
    bool estaListo() const;
    void setPosicion(sf::Vector2f posicion);
    void mover(sf::Vector2f direccion, float dt);
    void actualizar(sf::Vector2f destino, float dt);
    void dibujar(sf::RenderWindow &ventana) const;

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    bool listo;
};

inline float modulo(sf::Vector2f vector)
{
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

inline sf::Vector2f rotarVector(sf::Vector2f vector, float grados)
{
    float radianes = grados * 3.14159265f / 180.f;
    float cosA = std::cos(radianes);
    float sinA = std::sin(radianes);
    return sf::Vector2f(vector.x * cosA - vector.y * sinA, vector.x * sinA + vector.y * cosA);
}
