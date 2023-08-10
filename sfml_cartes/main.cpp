#include <SFML/Graphics.hpp>
#include <iostream>
#include "cartes.h"
#include "tapis.h"
#include "mouseEventHandler.h"

void circle();
void carte();

int main()
{
    //circle();
    carte();
    return 0;
}

void circle() {
    // Obtenez la résolution de l'écran
    sf::VideoMode terminalSize = sf::VideoMode::getDesktopMode();

    // Calcul des dimensions de la fenêtre pour obtenir les 3/4 de la résolution de l'écran
    unsigned int largeurFenetre = terminalSize.width * 3 / 4;
    unsigned int hauteurFenetre = terminalSize.height * 3 / 4;

    // Création fenêtre SFML centrée
    sf::RenderWindow window(sf::VideoMode(largeurFenetre, hauteurFenetre), "cercle");

    // Calcul de la position de la fenêtre pour la centrer
    unsigned int positionFenetreX = (terminalSize.width - largeurFenetre) / 2;
    unsigned int positionFenetreY = (terminalSize.height - hauteurFenetre) / 2;

    // Definition de la position de la fenêtre
    window.setPosition(sf::Vector2i(positionFenetreX, positionFenetreY));

    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Green);

    float centreX = largeurFenetre / 2;
    float centreY = hauteurFenetre / 2;

    shape.setPosition(centreX - 200, centreY - 200);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

void carte() {
    sf::VideoMode terminalSize = sf::VideoMode::getDesktopMode();
    unsigned int largeurFenetre = terminalSize.width * 3 / 4;
    unsigned int hauteurFenetre = terminalSize.height * 3 / 4;
    sf::RenderWindow window(sf::VideoMode(largeurFenetre, hauteurFenetre), "Jeu de cartes");
    unsigned int positionFenetreX = (terminalSize.width - largeurFenetre) / 2;
    unsigned int positionFenetreY = (terminalSize.height - hauteurFenetre) / 2;
    window.setPosition(sf::Vector2i(positionFenetreX, positionFenetreY));
    
    sf::Texture faceCarte;
    if (!faceCarte.loadFromFile("cartes_img/R-coeur.png")) {
        std::cerr << "erreur" << std::endl;
    }
    
    Carte carte(1, "coeur", faceCarte);
    carte.EchelleAuto(150);
    float centreX = largeurFenetre / 2;
    float centreY = hauteurFenetre / 2;
    carte.SetPosition(10, 10);

    sf::Vector2u taillefenetre = window.getSize();
    sf::Texture aspectTapis;
    if (!aspectTapis.loadFromFile("cartes_img/oldcar.jpg")) {
        std::cerr << "erreur" << std::endl;
    }
    Tapis tapis(aspectTapis);
    tapis.EchelleAuto(taillefenetre.x, taillefenetre.y);
    MouseEventHandler mouseHandler;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
           /* switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                std::cout << "coucou la souris" << std::endl;
                break;
            case sf::Event::MouseButtonReleased:
                std::cout << "bouton relache" << std::endl;

            }*/
            mouseHandler.MouseEvent(event, window);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        tapis.Render(window);
        carte.Render(window);
        window.display();
    }
}

