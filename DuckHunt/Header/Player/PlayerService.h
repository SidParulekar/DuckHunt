#pragma once
#include <SFML/Graphics.hpp>
namespace Player
{
    class PlayerController;

    class PlayerService
    {

    private:

        PlayerController* player_controller;

    public:

        PlayerService();
        ~PlayerService();

        void initialize();
        void update();

        void increaseScore(int val);

        int getPlayerScore();

        void addTotalScore();

        int getTotalScore();

        void setBulletType(sf::String type); 
        sf::String getBulletType(); 

        bool inPlayableArea();

        sf::FloatRect& getRadialDamageArea();

        bool deployedRadialBullet();

        int normalBulletsLeft();

        void reset();
    };
}