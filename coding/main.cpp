//TODO: mirar a ver si se puede hacer el sound.play() dentro del while ventana abierta

//mingw32-make -f -MakeFile
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "sound.h"

#define F_KEY 70

int main(){
  int key;
  sf::RenderWindow window(sf::VideoMode(600, 600), "sonido");
  sf::SoundBuffer buffer;
  std::vector<sf::Int16> samples;
  for(int i = 0; i < 44100; i++){
    samples.push_back(sound::Sinewave(i, 440, 0.9));
  }
  buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);

  sf::Sound sound;
  sound.setBuffer(buffer);
  //sound.play();

  while (window.isOpen()){
    key = getch();
    if(key == 'f'){
      sound.play();
    }
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close();
    }
    window.clear();
    window.display();
  }
}