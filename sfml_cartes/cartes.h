#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Carte
{
public:
    Carte(int p_valeur, std::string p_couleur, sf::Texture& p_texture);
    void Render(sf::RenderTarget& renderWindow);
    void EchelleAuto(unsigned int largeurCarte);
    void SetPosition(float x, float y);
    sf::Texture getTexture();

   
private:
    sf::Sprite m_sprite;
    int m_valeur;
    std::string m_couleur;
};