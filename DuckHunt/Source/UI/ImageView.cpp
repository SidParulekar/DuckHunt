#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ImageView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Image
{
    using namespace Global;

    ImageView::ImageView()
    {
        game_window = nullptr;
    }

    void ImageView::initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position)
    {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        setTexture(texture_path);
        setScale(image_width, image_height);
        setPosition(position);
    }

    void ImageView::setTexture(sf::String texture_path)
    {
        if (image_texture.loadFromFile(texture_path))
        {
            image_sprite.setTexture(image_texture);
        }
    }

    void ImageView::setTextureRect(sf::IntRect texture_rect)
    {
        image_sprite.setTextureRect(texture_rect);
    }

    void ImageView::setScale(float width, float height)
    {
        float scale_x = width / image_sprite.getTexture()->getSize().x;
        float scale_y = height / image_sprite.getTexture()->getSize().y;

        image_sprite.setScale(scale_x, scale_y);
    }

    void ImageView::setScale(float width, float height, float tile_width, float tile_height)
    {
        float scale_x = width / tile_width;
        float scale_y = height / tile_height;

        image_sprite.setScale(scale_x, scale_y);
    }

    void ImageView::setPosition(sf::Vector2f position)
    {
        image_sprite.setPosition(position);
    }

    void ImageView::setRotation(float rotation_angle)
    {
        image_sprite.setRotation(rotation_angle);
    }

    void ImageView::setOriginAtCentre()
    {
        image_sprite.setOrigin(image_sprite.getLocalBounds().width / 2, image_sprite.getLocalBounds().height / 2);
    }

    void ImageView::setImageAlpha(float alpha)
    {
        sf::Color color = image_sprite.getColor();
        color.a = alpha;
        image_sprite.setColor(color);
    }

    void ImageView::setCentreAlinged()
    {
        float x_position = (game_window->getSize().x / 2) - (image_sprite.getGlobalBounds().width / 2);
        float y_position = image_sprite.getGlobalBounds().getPosition().y;

        image_sprite.setPosition(x_position, y_position);
    }

    void ImageView::update()
    {
       
    }

    void ImageView::render()
    {     
        
        game_window->draw(image_sprite);
        
    }

    const sf::Sprite& ImageView::getImageSprite()
    {
        return image_sprite;
    }


    ImageView::~ImageView() = default;
}