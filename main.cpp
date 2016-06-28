#include <SFML\Graphics.hpp>
#include "pilha.h"
#include "geniusRender.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <sstream>
#define DIFICULDADE 25

sf::Font font;

int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Mad Genius");
	sf::Text text, text2, text3, text4, text5, text6, text7, text8;
	font.loadFromFile("ALGER.ttf");
	text8.setFont(font); text8.setColor(sf::Color::White); text8.setString("Press Space to Start"); text8.setPosition(230, 100);
	text.setFont(font);
	text2.setFont(font);
	text2.setPosition(600, 600);
	text2.setString("Level");
	bool rodando = true;
	srand(time(0));
	int corGenius, corGeniusAux = 0;
	int AuxInsere = 5;
	int turno = 1, nivel = 1;
	int i;
	bool flag = true, flag2 = true;

	Pilha p1;
	Fila f1;
	Pilha pAux;
	int auxDesempilha;

	geniusRender* gR = new geniusRender(window);

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
			else {
				i = 0;
				while (rodando && (turno < DIFICULDADE)) {
					window->clear(sf::Color::Black);
					gR->draw();
					while (i < turno) {
						corGenius = rand() % 4 + 1;
						while (corGenius == corGeniusAux) {
							corGenius = rand() % 4 + 1;
						}
						corGeniusAux = corGenius;

						printf("%d", corGenius);
						p1.Empilha(corGenius, rodando);

						if (turno > 1) {
							while (!p1.Vazia()) {
								p1.Desempilha(auxDesempilha, rodando);
								pAux.Empilha(auxDesempilha, rodando);
							}

							while (!pAux.Vazia()) {
								pAux.Desempilha(auxDesempilha, rodando);
								gR->blinkCircle(auxDesempilha);
								p1.Empilha(auxDesempilha, rodando);
							}
						}
						gR->blinkCircle(corGenius);
						Sleep(100);
						i++;
					}

					for (int i = 0; i < turno && turno < DIFICULDADE; i++) {
						while (AuxInsere == 5) {
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
								gR->blinkGreenCircle();
								AuxInsere = 1;
							}
							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
								gR->blinkRedCircle();
								AuxInsere = 2;
							}
							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
								gR->blinkMagentaCircle();
								AuxInsere = 3;
							}
							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
								gR->blinkBlueCircle();
								AuxInsere = 4;
							}
						}

						f1.Insere(AuxInsere, rodando);
						AuxInsere = 5;
					}
					if (turno < DIFICULDADE - 14) {
						window->clear(sf::Color::Black);

						if (p1.PilhasIguais(f1)) {
							std::stringstream ss;
							ss << turno;
							text.setString("Nice! Nivel: ");
							text.setPosition(0, 0);
							text2.setString(ss.str());
							text2.setPosition(250, 0);
							window->draw(text);
							window->draw(text2);
							window->display();
							Sleep(1000);
							turno++;
							while (!f1.Vazia()) {
								f1.Retira(corGenius, rodando);
							}
							gR->draw();
						}
						else {
							window->clear();
							text.setString("Wrong Answer, game over!");
							text.setPosition(200, 200);
							window->draw(text);
							window->display();
							Sleep(1000);

							/*Sleep used to show another message. Decide if it continues or not */

							window->clear(sf::Color::Black);
							text.setString("Again? 'Y' for yes, 'N' for no");
							text.setPosition(200, 200);
							window->draw(text);
							window->display();
							Sleep(1000);
							while (flag == true) {
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
									return 0;
								}
								else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
									window->clear();
									window->display();
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
					}
					else {
						window->clear();
						text.setString("Parabéns, você zerou o jogo!");
						text.setPosition(400, 300);
						window->draw(text);
						turno = 1;
						i = 0;
					}
				}
			}
		}
	}

    return 0;
}
