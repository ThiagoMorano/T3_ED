#include <SFML\Graphics.hpp>
#include <Windows.h>

#ifndef GENIUSRENDER_H
#define GENIUSRENDER_H

extern sf::Font font;

class geniusRender {

private:
	sf::CircleShape* greenCircle;
	sf::CircleShape* magentaCircle;
	sf::CircleShape* redCircle;
	sf::CircleShape* blueCircle;
	sf::RenderWindow* window;
	sf::Text text3, text4, text5, text6;

public:
	geniusRender(sf::RenderWindow* w) {
		greenCircle = new sf::CircleShape(40.0f);
 		magentaCircle = new sf::CircleShape(40.0f);
		redCircle = new sf::CircleShape(40.0f);
		blueCircle = new sf::CircleShape(40.0f);
		window = w;

		greenCircle->setFillColor(sf::Color::Green);
		magentaCircle->setFillColor(sf::Color::Magenta);
		redCircle->setFillColor(sf::Color::Red);
		blueCircle->setFillColor(sf::Color::Blue);
		greenCircle->setPosition(200, 300);
		magentaCircle->setPosition(400, 300);
		redCircle->setPosition(300, 300);
		blueCircle->setPosition(500, 300);

		text3.setFont(font); text3.setColor(sf::Color::Black); text3.setString("1"); text3.setPosition(230, 320);
		text4.setFont(font); text4.setColor(sf::Color::Black); text4.setString("3"); text4.setPosition(430, 320);
		text5.setFont(font); text5.setColor(sf::Color::Black); text5.setString("2"); text5.setPosition(330, 320);
		text6.setFont(font); text6.setColor(sf::Color::Black); text6.setString("4"); text6.setPosition(530, 320);

	}

	void draw() {
		window->draw(*greenCircle);
		window->draw(*magentaCircle);
		window->draw(*redCircle);
		window->draw(*blueCircle);
		window->draw(text3); window->draw(text4); window->draw(text5); window->draw(text6);
		window->display();
	}

	void blinkCircle(int cor) {
		switch (cor) {
		case 1:
			//Sleep(100);
			greenCircle->setFillColor(sf::Color::White);
			this->draw();
			Sleep(500);
			greenCircle->setFillColor(sf::Color::Green);
			this->draw();
			//Sleep(1000);
			break;
		case 2:
			//Sleep(100);
			redCircle->setFillColor(sf::Color::White);
			this->draw();
			Sleep(500);
			redCircle->setFillColor(sf::Color::Red);
			this->draw();
			//Sleep(1000);
			break;
		case 3:
			//Sleep(100);
			magentaCircle->setFillColor(sf::Color::White);
			this->draw();
			Sleep(500);
			magentaCircle->setFillColor(sf::Color::Magenta);
			this->draw();
			//Sleep(1000);
			break;
		case 4:
			//Sleep(100);
			blueCircle->setFillColor(sf::Color::White);
			this->draw();
			Sleep(500);
			blueCircle->setFillColor(sf::Color::Blue);
			this->draw();
			//Sleep(1000);
			break;
		default:
			break;
		}
	}

	void blinkGreenCircle() {
		greenCircle->setFillColor(sf::Color::White);
		this->draw();
		Sleep(300);
		greenCircle->setFillColor(sf::Color::Green);
		this->draw();
	}
	void blinkRedCircle() {
		redCircle->setFillColor(sf::Color::White);
		this->draw();
		Sleep(300);
		redCircle->setFillColor(sf::Color::Red);
		this->draw();
	}
	void blinkMagentaCircle() {
		magentaCircle->setFillColor(sf::Color::White);
		this->draw();
		Sleep(300);
		magentaCircle->setFillColor(sf::Color::Magenta);
		this->draw();
	}
	void blinkBlueCircle() {
		blueCircle->setFillColor(sf::Color::White);
		this->draw();
		Sleep(300);
		blueCircle->setFillColor(sf::Color::Blue);
		this->draw();
	}

};

#endif
