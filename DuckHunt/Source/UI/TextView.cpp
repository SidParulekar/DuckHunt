#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\TextView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Config.h" 

namespace Text
{
	using namespace Global;

	sf::Font TextView::font_bubble_bobble;
	sf::Font TextView::font_DS_DIGIB;

	TextView::TextView()
	{
	}

	void TextView::initializeTextView()
	{
		loadFont();
	}

	void TextView::loadFont()
	{
		font_bubble_bobble.loadFromFile(Config::bubble_bobble_font_path);
		font_DS_DIGIB.loadFromFile(Config::DS_DIGIB_font_path);
	}

	void TextView::initialize(sf::String text_value, sf::Vector2f position, FontType font_type, int font_size, sf::Color color)
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		setText(text_value);
		setTextPosition(position);
		setFont(font_type);
		setFontSize(font_size);
		setTextColor(color);
	}

	void TextView::setFont(FontType font_type)
	{
		switch (font_type)
		{
		case FontType::BUBBLE_BOBBLE:
			text.setFont(font_bubble_bobble);
			break;
		case FontType::DS_DIGIB:
			text.setFont(font_DS_DIGIB);
			break;
		}
	}

	void TextView::setFontSize(int font_size)
	{
		text.setCharacterSize(font_size);
	}

	void TextView::setTextPosition(sf::Vector2f position)
	{
		text.setPosition(position);
	}

	void TextView::setTextColor(sf::Color color)
	{
		text.setFillColor(color);
	}

	void TextView::update()
	{
	}

	void TextView::render()
	{
		game_window->draw(text);
	}

	void TextView::setText(sf::String text_value)
	{
		text.setString(text_value);
	}

	void TextView::setTextCentreAligned()
	{
		float x_position = (game_window->getSize().x - text.getLocalBounds().width) / 2;
		float y_position = (game_window->getSize().y - text.getLocalBounds().height) / 2;

		text.setPosition(sf::Vector2f(x_position, y_position));
	}

	void TextView::setTextXCentreAligned(float y_position)
	{
		float x_position = (game_window->getSize().x - text.getLocalBounds().width) / 2;
		text.setPosition(sf::Vector2f(x_position, y_position)); 
	}

	TextView::~TextView()
	{
	}

}