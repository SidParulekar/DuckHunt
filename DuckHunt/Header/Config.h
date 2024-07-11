#pragma once
#include <SFML/Graphics.hpp>

namespace Global
{
	class Config
	{
	public:
		static const sf::String background_texture_path;
		static const sf::String duck_texture_path;

		static const sf::String bubble_bobble_font_path;
		static const sf::String DS_DIGIB_font_path;

		static const sf::String bullet_texture_path;
		static const sf::String player_health_texture_path;

		static const sf::String replay_button_texture_path;
	};
}