#pragma once
#include <SFML/Graphics.hpp>

namespace Image
{
	class ImageView
	{
	protected:
		sf::Texture image_texture;
		sf::Sprite image_sprite;

		sf::RenderWindow* game_window; 

	public:
		ImageView();
		virtual ~ImageView();

		virtual void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position);
		virtual void update();
		virtual void render();

		virtual void setTexture(sf::String texture_path);
		virtual void setTextureRect(sf::IntRect texture_rect);
		virtual void setScale(float width, float height);
		virtual void setScale(float width, float height, float tile_width, float tile_height);
		virtual void setPosition(sf::Vector2f position);
		virtual void setRotation(float rotation_angle);
		virtual void setOriginAtCentre();
		virtual void setImageAlpha(float alpha);
		virtual void setCentreAlinged();

		const sf::Sprite& getImageSprite();
	};
}

