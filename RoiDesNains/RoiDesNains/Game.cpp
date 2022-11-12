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
    keyTexture.loadFromFile("../Images/key.png");
    
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
            }
            else if (tp[i] == 'D') {
                Entity door;
                door.initialisation(32.0f, 54.0f, i * 32.0f, (count - 2) * 18.0f, Entity::DOOR, &doorTexture);
                m_listEntities.push_back(door);
            }
            else if (tp[i] == 'K') {
                Entity key;
                key.initialisation(18.0f, 33.0f, i * 32.0f, count * 18.0f, Entity::KEY, &keyTexture);
                m_listEntities.push_back(key);
            }
            else if (tp[i] == 'P') {
                m_player = new Player;
                m_player->initialisation(i * 32.0f, count * 18.0f);
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

    // Dessiner les coeurs
    DisplayHUD();

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
    {
        m_gameState = Game::DEAD;
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

void Game::DisplayHUD() {

    m_window.setView(m_window.getDefaultView());

    // Afficher les coeurs du personnage
    sf::Texture heart;
    heart.loadFromFile("../Images/heart.png");

    for (int i = 0; i < m_player->getLife(); i++)
    {
        sf::Sprite spriteHeart(heart);
        spriteHeart.setPosition(50 + 50 * i, 50);
        m_window.draw(spriteHeart);
    }

    // Afficher le nombre de clef
    sf::Texture key;
    key.loadFromFile("../Images/key.png");

    sf::Sprite keySprite(key);
    keySprite.setPosition(WINSIZE_X - 50, 50);
    
    if (m_player->getKeys() < 1) {
        keySprite.setColor(sf::Color::Color(sf::Uint8(80), sf::Uint8(80), sf::Uint8(80)));
    }

    m_window.draw(keySprite);
}