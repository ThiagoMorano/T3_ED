#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pilha.h"
#include "fila.h"

using std::cout;
using std::cin;
using namespace sf;

int main(){
	//Declaracao das estruturas
	Pilha p1;
	Fila f2;

	// Create the main window
    RenderWindow window(VideoMode(800, 600), "Mad Genius");
   
    // Variavel para eventos
	Event evento;

	// Variavel do loop principal
	bool estaRodando = true;
	
	// Cria um circulo com 200f de raio
	CircleShape circulo(300);
	// Define a posicao do Circulo
	circulo.setPosition(100,0);
	// Define a cor para vermelho
	circulo.setFillColor(Color(0,0,0));
	
	// Variavel para armazenar a fonte
    Font fonte;
    // Localizacao da fonte
    if(!fonte.loadFromFile("alger.ttf")) {
        // Erro ao carregar a fonte
        exit(EXIT_FAILURE);
    }
	// Variavel para armazenar o texto e manipular a fonte
    Text texto("Mad Genius", fonte, 24);
    // Define a posicao
	texto.setPosition(332,280);
    // Define a cor
    texto.setColor(Color::Red);
	// Define alguns estilos para a fonte
	texto.setStyle(Text::Underlined);
	
	//Cores "apagadas"
	//vermelho
	Texture red;
	if (!red.loadFromFile("red_off.png")){
		// Erro ao carregar a fonte
        exit(EXIT_FAILURE);
	}
	Sprite redoff;
	redoff.setTexture(red);
	redoff.setPosition(415,-120);
	redoff.setRotation(45);
	//amarelo
	Texture yellow;
	if (!yellow.loadFromFile("yellow_off.png")){
		// Erro ao carregar a fonte
        exit(EXIT_FAILURE);
	}
	Sprite yellowoff;
	yellowoff.setTexture(yellow);
	yellowoff.setPosition(630,510);
	yellowoff.setRotation(135);
	//azul
	Texture blue;
	if (!blue.loadFromFile("blue_off.png")){
		// Erro ao carregar a fonte
        exit(EXIT_FAILURE);
	}
	Sprite blueoff;
	blueoff.setTexture(blue);
	blueoff.setPosition(420,300);
	blueoff.setRotation(135);
	//verde
	Texture green;
	if (!green.loadFromFile("green_off.png")){
		// Erro ao carregar a fonte
        exit(EXIT_FAILURE);
	}
	Sprite greenoff;
	greenoff.setTexture(green);
	greenoff.setPosition(840,300);
	greenoff.setRotation(135);
	
	//Cores "acesas"
	//vermelho
	Texture redaceso;
	if (!redaceso.loadFromFile("red_on.png")){
		// Erro ao carregar a fonte
        exit(EXIT_FAILURE);
	}
	Sprite redon;
	redon.setTexture(redaceso);
	redon.setPosition(415,-120);
	redon.setRotation(45);
	//amarelo
	Texture yellowaceso;
	if (!yellowaceso.loadFromFile("yellow_on.png")){
		// Erro ao carregar a fonte
        exit(EXIT_FAILURE);
	}
	Sprite yellowon;
	yellowon.setTexture(yellowaceso);
	yellowon.setPosition(630,510);
	yellowon.setRotation(135);
	//azul
	Texture blueaceso;
	if (!blueaceso.loadFromFile("blue_on.png")){
		// Erro ao carregar a fonte
        exit(EXIT_FAILURE);
	}
	Sprite blueon;
	blueon.setTexture(blueaceso);
	blueon.setPosition(420,300);
	blueon.setRotation(135);
	//verde
	Texture greenaceso;
	if (!greenaceso.loadFromFile("green_on.png")){
		// Erro ao carregar a fonte
        exit(EXIT_FAILURE);
	}
	Sprite greenon;
	greenon.setTexture(greenaceso);
	greenon.setPosition(840,300);
	greenon.setRotation(135);
	
	while(estaRodando){
		// Enquanto existir eventos coloque na variavel "evento"
		while(window.pollEvent(evento)){
			
			//para gerar números aleatórios de 1 a 4
			srand((unsigned)time(0)); 
      		int aleatorio = 1 + (rand()%4);
			
			//Empilhando o numero aleatorio que foi gerado
			bool ok;
			p1.Empilha(aleatorio, ok);
			if(ok == false)
				estaRodando = false;
			else{
				switch(aleatorio){
					case 1:
						window.draw(redon);
						break;
					case 2:
						window.draw(yellowon);
						break;
					case 3:
						window.draw(blueon);
						break;
					case 4:
						window.draw(greenon);
						break;
				}
			}
			// Comandos para jogar
			if (Keyboard::isKeyPressed(Keyboard::Up))
				f2.Insere(1, ok);
				if(ok == true)
					//vermelho
					
					// Desenha o sprite redon
					window.draw(redon);

			if (Keyboard::isKeyPressed(Keyboard::Down))
				f2.Insere(2, ok);
				if(ok == true)
					// Desenha o sprite yellowon
					//window.draw(yellowon);

			if (Keyboard::isKeyPressed(Keyboard::Left))
				f2.Insere(3, ok);
				if(ok == true)
					// Desenha o sprite blueon
					//window.draw(blueon);

			if (Keyboard::isKeyPressed(Keyboard::Right))
				f2.Insere(4, ok);
				if(ok == true)
					// Desenha o sprite greenon
					//window.draw(greenon);
				
			// Caso foi clicado no 'X' da janela para fechar
			if (evento.type ==  Event::Closed)
				estaRodando = false;
			// Caso foi pressionada a tecla Esc
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				estaRodando = false;
			
		}
		// "Limpa a tela" de branco
		window.clear(Color(255,255,255));
		// Desenha o Circulo na Janela
		window.draw(circulo);
		// Desenha a fonte
		window.draw(texto);
		// Desenha o sprite red
		window.draw(redoff);
		// Desenha o sprite yellow
		window.draw(yellowoff);
		// Desenha o sprite blue
		window.draw(blueoff);
		// Desenha o sprite green
		window.draw(greenoff);
		// Mostra a janela
		window.display();
		window.draw(redon);

	}

	// Fecha a janela
	window.close();

	// Ocorreu tudo bem
	return EXIT_SUCCESS;
}

	/* Old main
	int x;
	bool ok;
	int valor;
	int num = 2;
	Pilha p1;
	Fila f2;
	
	for(int i=0; i<5; i++){
		cin >> x;
		p1.Empilha(x, ok);
		if(ok == true)
			cout << "Empilho\n";
		else
			cout << "Nao Empilho\n";
	}
	
	for(int i=0; i<5; i++){
		cin >> x;
		f2.Insere(x, ok);
		if(ok == true)
			cout << "Inseriu\n";
		else
			cout << "Nao Inseriu\n";
	}
	
	if(p1.PilhasIguais(f2))
		cout << "Pilhas Iguais\n";
	else
		cout << "Pilhas nao iguais\n";
	
	return 0;
	*/
