#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Sounds\SoundService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Config.h"

namespace Sound
{
	using namespace Global;

	void SoundService::initialize()
	{
		loadSoundFromFile();
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(Config::button_click_sound_path))
			printf("Error loading button click sound file");

		if (!buffer_normal_bullet.loadFromFile(Config::normal_bullet_sound_path))
			printf("Error loading normal bullet sound file");

		if (!buffer_radial_bullet.loadFromFile(Config::radial_bullet_sound_path))
			printf("Error loading radial bullet sound file");

		if (!buffer_round_won.loadFromFile(Config::round_won_sound_path))
			printf("Error loading round won sound file");

		if (!buffer_round_lost.loadFromFile(Config::round_lost_sound_path))
			printf("Error loading round lost sound file");

		if (!buffer_round_start.loadFromFile(Config::round_start_sound_path))
			printf("Error loading round start sound file");
	}
	
	void SoundService::playSound(SoundType sound_type)
	{
		switch (sound_type)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			break;

		case SoundType::NORMAL_BULLET:
			sound_effect.setBuffer(buffer_normal_bullet);
			break;

		case SoundType::RADIAL_BULLET:
			sound_effect.setBuffer(buffer_radial_bullet);
			break;

		case SoundType::ROUND_WON:
			sound_effect.setBuffer(buffer_round_won);
			break;

		case SoundType::ROUND_LOST:
			sound_effect.setBuffer(buffer_round_lost);
			break;

		case SoundType::ROUND_START:
			sound_effect.setBuffer(buffer_round_start);
			break;

		default:
			printf("Invalid sound type");
			return;
		}

		sound_effect.play(); 
	}
}