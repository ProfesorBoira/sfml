#include "funciones.h"

Beltran::Beltran(sf::Vector2f posicion)
    : velocidad(150.f), listo(false)
{
    if (!textura.loadFromFile("assets/sprite2-1.png"))
        return; // listo queda en false

    textura.setSmooth(false);
    sprite.setTexture(textura);
    exp1.loadFromFile("assets/exp1.png");
    exp2.loadFromFile("assets/exp2.png");
    exp3.loadFromFile("assets/exp3.png");
    sprite.setScale(1.f, 1.f);
    sprite.setOrigin(textura.getSize().x / 2.f, textura.getSize().y / 2.f);
    sprite.setPosition(posicion);
    tiempo=0;
    listo = true;
    estado=1;
}
Beltran::Beltran(const Beltran& otro)
    : velocidad(otro.velocidad),
      tiempo(otro.tiempo),
      estado(otro.estado),
      listo(otro.listo)
{
    // 1. Copiar las texturas (ahora son objetos independientes en memoria)
    textura = otro.textura;
    exp1    = otro.exp1;
    exp2    = otro.exp2;
    exp3    = otro.exp3;

    // 2. Copiar el sprite (posición, escala, color...)
    sprite = otro.sprite;

    // 3. LO CRÍTICO: redirigir el puntero interno a NUESTRAS texturas
    switch (estado) {
        case 1:            sprite.setTexture(textura); break;
        case 2:            sprite.setTexture(exp1);    break;
        case 3:            sprite.setTexture(exp2);    break;
        default:           sprite.setTexture(exp3);    break;
    }
}
Beltran& Beltran::operator=(const Beltran& otro)
{
    // Guarda contra auto-asignación: "b1 = b1"
    if (this == &otro) return *this;

    // Exactamente lo mismo que el constructor de copia:
    velocidad = otro.velocidad;
    tiempo    = otro.tiempo;
    estado    = otro.estado;
    listo     = otro.listo;

    textura = otro.textura;
    exp1    = otro.exp1;
    exp2    = otro.exp2;
    exp3    = otro.exp3;

    sprite = otro.sprite;

    switch (estado) {
        case 1:  sprite.setTexture(textura); break;
        case 2:  sprite.setTexture(exp1);    break;
        case 3:  sprite.setTexture(exp2);    break;
        default: sprite.setTexture(exp3);    break;
    }

    return *this; // permite encadenar: a = b = c
}


bool Beltran::estaListo() const { return listo; }

// Movimiento absoluto
void Beltran::setPosicion(sf::Vector2f posicion)
{
    sprite.setPosition(posicion);
}

// Movimiento relativo (llamar cada frame con dt)
void Beltran::mover(sf::Vector2f direccion, float dt)
{
    sprite.move(direccion * velocidad * dt);
    tiempo=tiempo+dt;
}

void Beltran::dibujar(sf::RenderWindow &ventana) const
{
    if (!listo) return;
    ventana.draw(sprite);
}

void Beltran::actualizar(sf::Vector2f destino, float dt){
    //sf::Vector2f miposicion, direccion;
    //miposicion = sprite.getPosition();
    
    //direccion.x = (destino.x - miposicion.x); direccion.y = (destino.y - miposicion.y);
    //direccion.x /= modulo(direccion); direccion.y /= modulo(direccion);

    //float velocidad = 1.5;

    //sprite.move(direccion*velocidad*dt);
    tiempo=tiempo+dt;
    if (tiempo < 2.0f)
    {
        //no hacer nada
    }
    else if (tiempo < 2.1f)
    {
        if(estado==1){
            sprite.setTexture(exp1, true);  // true reajusta el rectángulo al tamaño de la nueva textura
            sprite.setScale(0.5f, 0.5f);
            auto bounds = sprite.getLocalBounds();
            sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        }
        estado=2;
    }
    else if (tiempo < 2.2f)
    {
        if(estado==2){
            sprite.setTexture(exp2, true);  // true reajusta el rectángulo al tamaño de la nueva textura
            sprite.setScale(0.5f, 0.5f);
        }
        estado=3;
    }
    else if (tiempo < 2.3f)
    {
        if(estado==3){
            sprite.setTexture(exp3, true);  // true reajusta el rectángulo al tamaño de la nueva textura
            sprite.setScale(0.5f, 0.5f);
        } 
        estado=4;
    }
    else if (tiempo >2.5f){

           float t = tiempo - 2.5f; // desde explosión
           float alpha = 255 - t * 255 / 0.5f; // desaparece en 0.5 s
           if(alpha > 0) {
              sprite.setColor(sf::Color(255,255,255,(sf::Uint8)alpha));
           }
        
    }
    if (tiempo >4){
        sprite.setColor(sf::Color(0,0,0,0));
        listo = false;
    }



}
