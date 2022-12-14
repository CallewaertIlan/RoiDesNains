#include "Framework.h"
using namespace std;


Menu::Menu()
{
    valueMenu = 1;
    keyPress = chrono::steady_clock::now();
    m_menuState = Menu::MENU;
}

Menu::~Menu()
{
}

void Menu::OnEnter(int oldState)
{
}

void Menu::OnExecute()
{
    //std::chrono::steady_clock::time_point
}

void Menu::OnExit(int newState)
{
}

bool Menu::OnUpdate()
{
        sf::RenderWindow window(sf::VideoMode(WINSIZE_X, WINSIZE_Y), "RoiDesNains");

        sf::Texture bgMenu;
        bgMenu.loadFromFile("../Images/bgmenu.png");
        sf::Sprite bgSpriteMenu(bgMenu);
        bgSpriteMenu.setScale(5.4f, 3.7f);

        sf::Texture bgControls;
        bgControls.loadFromFile("../Images/bgcontrols.png");
        sf::Sprite bgSpriteControls(bgControls);

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

            if (m_menuState == Menu::MENU)
            {
                newKeyPress = chrono::steady_clock::now();
                auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(newKeyPress- keyPress).count();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&  elapsed_time > 300)
                {
                    addValue(-1);
                    keyPress = newKeyPress;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && elapsed_time > 300)
                {
                    addValue(1);
                    keyPress = newKeyPress;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    switch (valueMenu)
                    {
                    case 1:
                        window.close();
                        newGame();
                        break;
                    case 2:
                        m_menuState = Menu::CONTROLS;
                        break;
                    case 3:
                        window.close();
                        return false;
                        break;
                    default:
                        break;
                    }
                }

                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                        return false;
                    }
                }
                window.clear();
                window.draw(bgSpriteMenu);

                for (int i = 0; i < 4; i++)
                {
                    text.setString(listText[i]);
                    text.setPosition(sf::Vector2f(200.0f, 200.0f + 100.0f * i));
            
                    if (valueMenu == i) {
                        text.setFillColor(sf::Color::Red);
                    }
                    else
                    {
                        text.setFillColor(sf::Color::White);
                    }
                    window.draw(text);
                }
            }
            else if (m_menuState == Menu::CONTROLS)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
                    m_menuState = Menu::MENU;
                }
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                        return false;
                    }
                }
                window.clear();
                window.draw(bgSpriteControls);
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

void Menu::newGame()
{
    Game* m_Game = new Game;
    m_Game->Init();
}
