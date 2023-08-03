#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Tapis {
public:
	Tapis(sf::Texture& p_texture);
	void Render(sf::RenderTarget& renderWindow);
	void EchelleAuto(unsigned int p_largeurFenetre, unsigned int p_hauteurFenetre);
	sf::Texture getTexture();

private:
	sf::Sprite m_sprite;
};
