#include "Framework.h"

Game::Game()
{
	m_player = NULL;
    m_listEntities;
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
    sf::Sprite bgGame(bg);
    bgGame.setScale(5.4f, 3.7f);
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        // Effacer tout sur la fenetre
        m_window.clear();

        // Dessiner le fond
        m_window.draw(bgGame);

        // Charger la map
        LoadRessources();

        // Player
        m_player->OnUpdate(m_listEntities);
        m_window.draw(m_player->getSprite());
        
        // Afficher les mises à jour de la fenetre
        m_window.display();
    }
}

void Game::LoadRessources()
{
    m_listEntities.clear();
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
                rectangle.setPosition(i * 32.0f, count * 18.0f);
                m_listEntities.push_back(rectangle);
                m_window.draw(rectangle);
            }
            else if (tp[i] == '2') {
                sf::RectangleShape triangle(sf::Vector2f(32.0f, 18.0f));
                triangle.setTexture(&pic);
                triangle.setPosition(i * 32.0f, count * 18.0f);
                m_listEntities.push_back(triangle);
                m_window.draw(triangle);
            }
        }
        count++;
    }
    inFile.close();
}
