#pragma once
#include <SFML/Graphics.hpp>

namespace Global
{
	class Config
	{
	public:
		static const sf::String background_texture_path;
		static const sf::String duck_texture_path;
		static const sf::String bonus_duck_texture_path;
		static const sf::String shot_duck_texture_path;

		static const sf::String bubble_bobble_font_path;
		static const sf::String DS_DIGIB_font_path;

		static const sf::String bullet_texture_path;
		static const sf::String radial_bullet_texture_path;
		static const sf::String player_health_texture_path;

		static const sf::String replay_button_texture_path;

		static const sf::String normal_bullet_sound_path;
		static const sf::String radial_bullet_sound_path;
		static const sf::String button_click_sound_path;
		static const sf::String round_won_sound_path;
		static const sf::String round_lost_sound_path;
		static const sf::String round_start_sound_path;
	};
}