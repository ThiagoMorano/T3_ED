#include <SFML\Graphics.hpp>
#include "pilha.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <sstream>
#define DIFICULDADE 10

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mad Genius");
	//setting text and font
	sf::Text text, text2, text3, text4, text5, text6, text7;
	sf::Font font;
	font.loadFromFile("ALGER.ttf");
	text.setFont(font);
	text2.setFont(font);
	text3.setFont(font); text3.setColor(sf::Color::Black); text3.setString("1"); text3.setPosition(230, 320);
	text4.setFont(font); text4.setColor(sf::Color::Black); text4.setString("3"); text4.setPosition(430, 320);
	text5.setFont(font); text5.setColor(sf::Color::Black); text5.setString("2"); text5.setPosition(330, 320);
	text6.setFont(font); text6.setColor(sf::Color::Black); text6.setString("4"); text6.setPosition(530, 320);
	text7.setFont(font); text7.setColor(sf::Color::Black); text7.setString("Mad-Genius"); text7.setPosition(400, 300);
	text2.setPosition(600, 600);
	text2.setString("Level");
	//setting circle settings
	sf::CircleShape greenCircle(40.0f);
	sf::CircleShape magentaCircle(40.0f);
	sf::CircleShape redCircle(40.0f);
	sf::CircleShape blueCircle(40.0f);
	greenCircle.setFillColor(sf::Color::Green);
	magentaCircle.setFillColor(sf::Color::Magenta);
	redCircle.setFillColor(sf::Color::Red);
	blueCircle.setFillColor(sf::Color::Blue);
	greenCircle.setPosition(200, 300);
	magentaCircle.setPosition(400, 300);
	redCircle.setPosition(300, 300);
	blueCircle.setPosition(500, 300);
	//green, red, magenta, blue
	//game functioning variables
	bool rodando = true;
	srand(time(NULL));
	int corGenius;
	int AuxInsere = 5;
	int turno = 1, nivel = 1;
	int i;
	bool flag = true;

	Pilha p1;
	Fila f1;
	Pilha pAux;
	int auxDesempilha;

	while (window.isOpen()) {
		/* creating the event */

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			/*probably the game is going on under here*/
			i = 0;
			while (rodando && (turno < DIFICULDADE)) {
				window.clear(sf::Color::Black);
				window.draw(greenCircle);
				window.draw(magentaCircle);
				window.draw(redCircle);
				window.draw(blueCircle);
				window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
				window.display();
				
				while (i < turno) {
					corGenius = rand() % 4 + 1;
					p1.Empilha(corGenius, rodando);
					
					if (turno > 1) {
						while (!p1.Vazia()) {
							p1.Desempilha(auxDesempilha, rodando);
							pAux.Empilha(auxDesempilha, rodando);
						}

						while (!pAux.Vazia()) {
							pAux.Desempilha(auxDesempilha, rodando);
							switch (auxDesempilha) {
							case 1:
								greenCircle.setFillColor(sf::Color::White);
								window.draw(greenCircle);
								window.draw(magentaCircle);
								window.draw(redCircle);
								window.draw(blueCircle);
								window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
								window.display();
								Sleep(1000);
								greenCircle.setFillColor(sf::Color::Green);
								window.draw(greenCircle);
								window.draw(magentaCircle);
								window.draw(redCircle);
								window.draw(blueCircle);
								window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
								window.display();
								break;
							case 2:
								redCircle.setFillColor(sf::Color::White);
								window.draw(greenCircle);
								window.draw(magentaCircle);
								window.draw(redCircle);
								window.draw(blueCircle);
								window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
								window.display();
								Sleep(1000);
								redCircle.setFillColor(sf::Color::Red);
								window.draw(greenCircle);
								window.draw(magentaCircle);
								window.draw(redCircle);
								window.draw(blueCircle);
								window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
								window.display();
								break;
							case 3:
								magentaCircle.setFillColor(sf::Color::White);
								window.draw(greenCircle);
								window.draw(magentaCircle);
								window.draw(redCircle);
								window.draw(blueCircle);
								window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
								window.display();
								Sleep(1000);
								magentaCircle.setFillColor(sf::Color::Magenta);
								window.draw(greenCircle);
								window.draw(magentaCircle);
								window.draw(redCircle);
								window.draw(blueCircle);
								window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
								window.display();
								break;
							case 4:
								blueCircle.setFillColor(sf::Color::White);
								window.draw(greenCircle);
								window.draw(magentaCircle);
								window.draw(redCircle);
								window.draw(blueCircle);
								window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
								window.display();
								Sleep(1000);
								blueCircle.setFillColor(sf::Color::Blue);
								window.draw(greenCircle);
								window.draw(magentaCircle);
								window.draw(redCircle);
								window.draw(blueCircle);
								window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
								window.display();
								break;
							default:
								break;
							}
							p1.Empilha(auxDesempilha, rodando);
						}
					}
					/* we'll set the circles with white, showing that they are part of the sequence
					and the Sleep() function was added after every p1.Empilha() to TRY(?) to make it slow-mode */
					switch (corGenius) {

					case 1:
						greenCircle.setFillColor(sf::Color::White);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
						Sleep(1000);
						greenCircle.setFillColor(sf::Color::Green);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
						break;
					case 2:
						redCircle.setFillColor(sf::Color::White);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
						Sleep(1000);
						redCircle.setFillColor(sf::Color::Red);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
						break;
					case 3:
						magentaCircle.setFillColor(sf::Color::White);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
						Sleep(1000);
						magentaCircle.setFillColor(sf::Color::Magenta);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
						break;
					case 4:
						blueCircle.setFillColor(sf::Color::White);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
						Sleep(1000);
						blueCircle.setFillColor(sf::Color::Blue);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
						break;
					default:
						break;
					}
					Sleep(1000);
					i++;
				}

				for (int i = 0; i < turno && turno < DIFICULDADE; i++) {
					
					/* im not printing the "pilha" as we did with numbers before
					and the AuxInsere variable was created to compare with the corGenius
					
					we'll determine the AuxInsere variable according to the keypressed variable
					as it should be A, S, D or F 
					
					the same approach with the white values was used */
					while (AuxInsere == 5) {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
							greenCircle.setFillColor(sf::Color::White);
							window.draw(greenCircle);
							window.draw(magentaCircle);
							window.draw(redCircle);
							window.draw(blueCircle);
							window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
							window.display();
							Sleep(1000);
							greenCircle.setFillColor(sf::Color::Green);
							window.draw(greenCircle);
							window.draw(magentaCircle);
							window.draw(redCircle);
							window.draw(blueCircle);
							window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
							window.display();
							AuxInsere = 1;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
							redCircle.setFillColor(sf::Color::White);
							window.draw(greenCircle);
							window.draw(magentaCircle);
							window.draw(redCircle);
							window.draw(blueCircle);
							window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
							window.display();
							Sleep(1000);
							redCircle.setFillColor(sf::Color::Red);
							window.draw(greenCircle);
							window.draw(magentaCircle);
							window.draw(redCircle);
							window.draw(blueCircle);
							window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
							window.display();
							AuxInsere = 2;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
							magentaCircle.setFillColor(sf::Color::White);
							window.draw(greenCircle);
							window.draw(magentaCircle);
							window.draw(redCircle);
							window.draw(blueCircle);
							window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
							window.display();
							Sleep(1000);
							magentaCircle.setFillColor(sf::Color::Magenta);
							window.draw(greenCircle);
							window.draw(magentaCircle);
							window.draw(redCircle);
							window.draw(blueCircle);
							window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
							window.display();
							AuxInsere = 3;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
							blueCircle.setFillColor(sf::Color::White);
							window.draw(greenCircle);
							window.draw(magentaCircle);
							window.draw(redCircle);
							window.draw(blueCircle);
							window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
							window.display();
							Sleep(1000);
							blueCircle.setFillColor(sf::Color::Blue);
							window.draw(greenCircle);
							window.draw(magentaCircle);
							window.draw(redCircle);
							window.draw(blueCircle);
							window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
							window.display();
							AuxInsere = 4;
						}
					}

					f1.Insere(AuxInsere, rodando);
					AuxInsere = 5;
				}
				if (turno < DIFICULDADE) {
					/* Trying to clear the window and show a text */
					window.clear(sf::Color::Black);
					text.setString("Checking Answer!");
					window.draw(text);
					window.display();
					Sleep(500);
				
					/* Clearing it again, to show if it was right or wrong
					that's why the Sleep() was used again: trying to not show the messages too fast */
				
					window.clear(sf::Color::Black);
				
					if (p1.PilhasIguais(f1)) {
						std::stringstream ss;
						ss << turno;
						text.setString("Nice Bro! Nivel: ");
						text2.setString(ss.str());
						text2.setPosition(250, 0);
						window.draw(text);
						window.draw(text2);
						window.display();
						Sleep(2000);
						turno++;
						while (!f1.Vazia()) {
							f1.Retira(corGenius, rodando);
						}
						window.clear(sf::Color::Black);
						window.draw(greenCircle);
						window.draw(magentaCircle);
						window.draw(redCircle);
						window.draw(blueCircle);
						window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
						window.display();
					}
					else {
						window.clear();
						text.setString("Wrong Answer, game over!");
						window.draw(text);
						window.display();
						Sleep(1000);

						/*Sleep used to show another message. Decide if it continues or not */

						window.clear(sf::Color::Black);
						text.setString("Wanna play again? hit 'Y' if yes, and 'N' if don't");
						window.draw(text);
						window.display();
						Sleep(1000);
						while (flag == true) {
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
								window.close();
							}
							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
								window.clear();
								window.display();
								while (!p1.Vazia()) {
									p1.Desempilha(corGenius, rodando);
								}
								while (!f1.Vazia()) {
									f1.Retira(corGenius, rodando);
								}
								turno = 1;
								i = 0;
								flag = false;
							}
						}
						flag = true;
					}
				} else {
					window.clear();
					text.setString("Parabéns, você zerou o jogo!");
					text.setPosition(400, 300);
					window.draw(text);
					turno = 1;
					i = 0;
				}
			}
		}
	}

    return 0;
}