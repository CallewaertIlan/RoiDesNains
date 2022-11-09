#include "Framework.h"

Game::Game()
{
	m_player = NULL;
    m_listEntities;
    m_gameState = Game::GAME;
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

    // Charger la map
    LoadRessources();

    while (m_window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        switch (m_gameState)
        {
        case Game::GAME:
            OnUpdate(deltaTime);
            OnRender(bgGame);
            break;
        case Game::MENU:
            Menu();
            break;
        case Game::DEAD:
            Death();
            break;
        }
    }
}

void Game::LoadRessources()
{
    rockTexture.loadFromFile("../Images/rock.png");
    doorTexture.loadFromFile("../Images/door.png");
    picTexture.loadFromFile("../Images/pic.png");
    
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
                Entity rock;
                rock.initialisation(32.0f, 18.0f, i * 32.0f, count * 18.0f, Entity::ROCK, &rockTexture);
                m_listEntities.push_back(rock);
            }
            else if (tp[i] == '2') {
                Entity pic;
                pic.initialisation(32.0f, 18.0f, i * 32.0f, count * 18.0f, Entity::PIC, &picTexture);
                m_listEntities.push_back(pic);
            }else if (tp[i] == '3') {
                Entity door;
                door.initialisation(32.0f, 54.0f, i * 32.0f, (count - 2) * 18.0f, Entity::DOOR, &doorTexture);
                m_listEntities.push_back(door);
            }
        }
        count++;
    }
    inFile.close();
}

void Game::OnUpdate(float deltaTime) { 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_gameState = Game::MENU;
    }
    // Entity
    for (int i = 0; i < m_listEntities.size(); i++)
    {
        m_listEntities[i].OnUpdate(deltaTime);
    }

    // Player
    m_window.setView(m_player->getView());
    m_player->OnUpdate(m_listEntities, 0, deltaTime);
}

void Game::OnRender(sf::Sprite bgGame) {
    // Effacer tout sur la fenetre
    m_window.clear();

    // Dessiner le fond
    m_window.draw(bgGame);

    // Entity
    for (int i = 0; i < m_listEntities.size(); i++)
    {
        m_window.draw(m_listEntities[i].GetRect());
    }

    // Dessiner le personnage
    m_window.draw(m_player->getSprite());

    // Afficher les mises à jour de la fenetre
    m_window.display();
}

void Game::Menu() {
    sf::Texture bgTexture;
    bgTexture.loadFromFile("../Images/bgPause.png");
    sf::Sprite bgPause(bgTexture);
    m_window.setView(m_window.getDefaultView());
    m_window.draw(bgPause);
    m_window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        m_gameState = Game::GAME;
        bgTexture.~Texture();
    }
}

void Game::Death() {
    sf::Texture bgTexture;
    bgTexture.loadFromFile("../Images/bgDeath.png");
    sf::Sprite bgPause(bgTexture);
    m_window.setView(m_window.getDefaultView());
    m_window.draw(bgPause);
    m_window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        m_window.close();
    }
}