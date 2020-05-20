#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Game
{
public:
	Game();
	void run();
private:
	void processEvents();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time deltaTime);
	void render();
private:
	sf::RenderWindow m_Window;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::RectangleShape m_Player;
};