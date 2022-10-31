#include "Framework.h"


Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::OnEnter(int oldState)
{
}

void Menu::OnExecute()
{
}

void Menu::OnExit(int newState)
{
}

void Menu::OnUpdate()
{
    sf::RenderWindow window(sf::VideoMode(WINSIZE_X, WINSIZE_Y), "RoiDesNains");
    sf::Texture bg;
    bg.loadFromFile("../Images/bgtest.png");
    sf::Sprite bgtest(bg);
    bgtest.setScale(5.4, 3.7);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bgtest);
        window.display();
    }
    return 0;
}