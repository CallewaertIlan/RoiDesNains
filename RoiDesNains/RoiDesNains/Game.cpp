#include "Framework.h"

Game::Game()
{
	m_player = NULL;
}

Game::~Game()
{
}

void Game::Init() {
    m_window.create(sf::VideoMode(WINSIZE_X, WINSIZE_Y), "RoiDesNains");
	m_player = new Player;
	Loop();
}

void Game::Loop()
{
    sf::Texture bg;
    bg.loadFromFile("../Images/bg_game.png");
    sf::Sprite bgtest(bg);
    bgtest.setScale(5.4, 3.7);
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.clear();
        m_window.draw(bgtest);
        LoadRessources();
        m_player->OnUpdate();
        m_window.draw(m_player->getSprite());
        m_window.display();
    }
}

void Game::LoadRessources()
{
    ifstream inFile;
    inFile.open("../Level/Test1.txt", ios::in);
    if (!inFile) {
        cout << "Unable to open file";
        return;
    }
    int count = 0;
    string tp;
    sf::Texture rock;
    rock.loadFromFile("../Images/rock.png");
    sf::Texture pic;
    pic.loadFromFile("../Images/pic.png");
    while (getline(inFile, tp)) {
        for (int i = 0; i < tp.size(); i++)
        {
            if (tp[i] == '1') {
                sf::RectangleShape rectangle(sf::Vector2f(32.0f, 18.0f));
                rectangle.setTexture(&rock);
                rectangle.setPosition(i * 32, count * 18);
                m_window.draw(rectangle);
            }
            else if (tp[i] == '2') {
                sf::RectangleShape triangle(sf::Vector2f(32.0f, 18.0f));
                triangle.setTexture(&pic);
                triangle.setPosition(i * 32, count * 18);
                m_window.draw(triangle);
            }
        }
        count++;
    }
    inFile.close();
}
