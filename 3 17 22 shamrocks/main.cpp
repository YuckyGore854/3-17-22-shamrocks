#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Circles");
	sf::CircleShape circle;
	window.setFramerateLimit(240);
	int xpos = 150;
	int ypos = 150;
	int size = 3;
	int a = 10;
	int k = 4;
	float angle = 0;
	int keyDelay = 0;

	circle.setRadius(size);
	circle.setFillColor((sf::Color(100, 0, 200, 50)));

	while (window.isOpen())//GAME LOOP--------------------------------
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && keyDelay % 10 == 0) {
			a++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && keyDelay % 10 == 0) {
			a--;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && keyDelay % 10 == 0) {
			k--;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && keyDelay % 10 == 0) {
			k++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && keyDelay % 10 == 0) {
			angle += 3.14159265358979323 / 100;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && keyDelay % 10 == 0) {
			angle -= 3.14159265358979323 / 100;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			window.clear();
		}
		//modify these arguments so each is a different slot of the vectors above
		cout <<"a "<< a << " k " << k << " angle " << angle << endl;
		circle.setPosition(a * cos(k * angle) * cos(angle)+300, a * cos(k * angle) * sin(angle)+300);
		window.draw(circle);
		angle -= 3.14159265358979323 / 1000;
		window.display();
		keyDelay++;
	}//end game loop-------------------------------------------------

	return 0;
} //end main