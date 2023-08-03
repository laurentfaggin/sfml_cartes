#include <string>
#include <SFML/Graphics.hpp>
#include "cartes.h"


Carte::Carte(int p_valeur, std::string p_couleur, sf::Texture& p_texture) {
	this->m_valeur = p_valeur;
	this->m_couleur = p_couleur;
	this->m_sprite.setTexture(p_texture);
}

void Carte::Render(sf::RenderTarget& renderWindow) {
	renderWindow.draw(m_sprite);
}

void Carte::EchelleAuto(unsigned int largeurCarte) {
	sf::Vector2u textureSize = m_sprite.getTexture()->getSize();

	float scale = static_cast<float>(largeurCarte) / textureSize.x;


	m_sprite.setScale(scale, scale);
}

void Carte::SetPosition(float x, float y) {
	m_sprite.setPosition(x, y);
}

sf::Texture Carte::getTexture() {
	return *m_sprite.getTexture();
}

