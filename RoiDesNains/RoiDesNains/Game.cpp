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
    m_font.loadFromFile("../Font/arial.ttf");
    rockTexture.loadFromFile("../Images/rock.png");
    doorTexture.loadFromFile("../Images/door.png");
    picTexture.loadFromFile("../Images/pic.png");

    keyTexture.loadFromFile("../Images/key.png");
    keySprite.setTexture(keyTexture);

    bgMainTexture.loadFromFile("../Images/bg_game.png");
    bgMainSprite.setTexture(bgMainTexture);
    bgMainSprite.setScale(5.4f, 3.7f);

    bgPauseTexture.loadFromFile("../Images/bgPause.png");
    bgPauseSprite.setTexture(bgPauseTexture);

    bgDeathTexture.loadFromFile("../Images/bgDeath.png");
    bgDeathSprite.setTexture(bgDeathTexture);

    heartTexture.loadFromFile("../Images/heart.png");

    m_text.setFont(m_font);
    m_text.setCharacterSize(50);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(500, 50);

    m_window.create(sf::VideoMode(WINSIZE_X, WINSIZE_Y), "RoiDesNains");
	Loop();
}

void Game::Loop()
{

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
            OnRender();
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

void Game::OnRender() {
    // Effacer tout sur la fenetre
    m_window.clear();

    // Dessiner le fond
    m_window.draw(bgMainSprite);

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
    m_window.setView(m_window.getDefaultView());
    m_window.draw(bgPauseSprite);
    m_window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        m_gameState = Game::GAME;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
    {
        m_gameState = Game::DEAD;
    }
}

void Game::Death() {
    m_window.setView(m_window.getDefaultView());
    m_window.draw(bgDeathSprite);
    m_window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        m_window.close();
    }
}

void Game::DisplayHUD() {

    m_window.setView(m_window.getDefaultView());

    // Afficher les coeurs du personnage

    for (int i = 0; i < m_player->getLife(); i++)
    {
        sf::Sprite spriteHeart(heartTexture);
        spriteHeart.setPosition(50 + 50 * i, 50);
        m_window.draw(spriteHeart);
    }

    // Afficher le nombre de clef
    keySprite.setPosition(WINSIZE_X - 50, 50);
    
    if (m_player->getKeys() >= 1) {
        m_window.draw(keySprite);
    }

    // Afficher ce que le player dit

    if (m_player->getListDisplay().size() > 0) {
        if (!m_isSpeaking) {
            m_timeLastDisplay = timeGetTime();
            m_isSpeaking = true;
        }
        m_text.setString(m_player->getListDisplay()[0]);
        m_window.draw(m_text);
        if (m_timeLastDisplay + 2000.0f < timeGetTime()) {
            m_player->refreshListDisplay();
            m_isSpeaking = false;
        }
    }
}