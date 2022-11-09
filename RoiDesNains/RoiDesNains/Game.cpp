#include "Framework.h"
#include <cmath>

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
    float deltaTime = 0.0f;
    sf::Clock clock;
    while (m_window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
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

        // Entity
        for (int i = 0; i < m_listEntities.size(); i++)
        {
            //m_listEntities[i].OnUpdate();
        }

        // Player
        m_window.setView(m_player->getView());
        m_player->OnUpdate(m_listEntities, 0, deltaTime);
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
    while (getline(inFile, tp)) {
        for (int i = 0; i < tp.size(); i++)
        {
            if (tp[i] == '1') {
                Entity* rock = new Entity;
                rock->initialisation(32.0f, 18.0f, Entity::ROCK);
                rock->GetRect().setPosition(i * 32.0f, count * 18.0f);
                m_listEntities.push_back(rock);
                m_window.draw(rock->GetRect());
            }
            else if (tp[i] == '2') {
                Entity* pic = new Entity;
                pic->initialisation(32.0f, 18.0f, Entity::ROCK);
                pic->GetRect().setPosition(i * 32.0f, count * 18.0f);
                m_listEntities.push_back(pic);
                m_window.draw(pic->GetRect());
            }else if (tp[i] == '3') {
                Entity* door = new Entity;
                door->initialisation(32.0f, 18.0f, Entity::ROCK);
                door->GetRect().setPosition(i * 32.0f, count * 18.0f);
                m_listEntities.push_back(door);
                m_window.draw(door->GetRect());
            }
        }
        count++;
    }
    inFile.close();
}
