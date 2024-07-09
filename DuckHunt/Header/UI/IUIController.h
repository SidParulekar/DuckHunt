#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ImageView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\TextView.h"
#include <SFML/Graphics.hpp>

namespace UI
{
    class IUIController
    {
    public:
        virtual void initialize() = 0;
        virtual void update() = 0;
        virtual void render() = 0;

        virtual void createUIElements() = 0;

        virtual ~IUIController() { }
    };
    
}