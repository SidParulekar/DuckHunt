#pragma once
#include <SFML/Audio.hpp>
namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		NORMAL_BULLET,
		RADIAL_BULLET,
		ROUND_WON,
		ROUND_LOST,
		ROUND_START
	};

	class SoundService
	{
	private:
		
		sf::Sound sound_effect;
		sf::SoundBuffer buffer_button_click;
		sf::SoundBuffer buffer_normal_bullet;
		sf::SoundBuffer buffer_radial_bullet;
		sf::SoundBuffer buffer_round_won;
		sf::SoundBuffer buffer_round_lost;
		sf::SoundBuffer buffer_round_start;

		void loadSoundFromFile();
	public:
		void initialize();

		void playSound(SoundType);
	};

}
