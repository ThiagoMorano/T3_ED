#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
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

int game() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Mad Genius");
	sf::SoundBuffer buffer;
	buffer.loadFromFile("switch.wav");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sf::Text text, text2;
	font.loadFromFile("ALGER.ttf"); text.setFont(font); text2.setFont(font);
	text.setColor(sf::Color::Yellow); text2.setColor(sf::Color::Yellow);

	//main variables
	bool rodando = true, flag = true;
	int  i, corGenius, corGeniusAux = 0, AuxInsere = 5, turno = 1;

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
						srand(time(0));
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
								sound.play();
								p1.Empilha(auxDesempilha, rodando);
							}
						}
						gR->blinkCircle(corGenius);
						sound.play();
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
							text2.setPosition(200, 0);
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
						text.setString("Parab�ns, voc� zerou o jogo!");
						text.setPosition(400, 300);
						window->draw(text);
						turno = 1;
						i = 0;
					}
				}
			}
		}
	}
}
