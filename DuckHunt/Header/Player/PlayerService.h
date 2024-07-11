#pragma once

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

        void reset();
    };
}