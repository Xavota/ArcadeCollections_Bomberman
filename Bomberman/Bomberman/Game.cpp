#include "Game.h"

Game::Game()
{
	m_Window.create(sf::VideoMode(640, 480), "SFML Works!");
	m_Player.setSize(sf::Vector2f{ 100.f, 100.f });
	m_Player.setOrigin(m_Player.getSize().x / 2, m_Player.getSize().y / 2);
	m_Player.setPosition(m_Window.getSize().x / 2, m_Window.getSize().y / 2);
	m_Player.setFillColor(sf::Color::Green);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_Window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			m_Window.close();
			break;
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
}

void Game::update(sf::Time deltaTime)
{
}

void Game::render()
{
	m_Window.clear();
	m_Window.draw(m_Player);
	m_Window.display();
}