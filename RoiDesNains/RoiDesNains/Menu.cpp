#include "Framework.h"


Menu::Menu()
{
    valueMenu = 1;
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

    sf::Font font;
    font.loadFromFile("../Font/arial.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Menu :");
    text.setCharacterSize(120);
    text.setFillColor(sf::Color::White);

    std::vector<std::string> listText;
    listText.push_back("Menu :");
    listText.push_back("1.Play");
    listText.push_back("2.Controls");
    listText.push_back("3.Exit");



    while (window.isOpen())
    {
        if (GetControler().menuUp()) {
            addValue(-1);
        }
        else if (GetControler().menuDown()) {
            addValue(1);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bgtest);

        for (int i = 0; i < 4; i++)
        {
            text.setString(listText[i]);
            text.setPosition(sf::Vector2f(200, 200 + 100 * i));
            
            if (valueMenu == i) {
                text.setFillColor(sf::Color::Red);
            }
            else {
                text.setFillColor(sf::Color::White);
            }
            window.draw(text);
        }
        window.display();
    }
}

void Menu::addValue(int add)
{
    if (add > 0) {
        if (valueMenu + add > 3)
            valueMenu = 1;
        else
            valueMenu += 1;
    }
    else {
        if (valueMenu + add < 1)
            valueMenu = 3;
        else
            valueMenu -= 1;
    }
}