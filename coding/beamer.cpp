//TODO: Q EL USER ELIJA EL NUM POLYPHONY

//mingw32-make -f MakeFile
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "sound.h"

#define F4_FREQ 349.228
#define FSHRP4_FREQ 369.994

void SqrSound_pluck(double freq, double amp, double length, sf::Sound &snd, sf::SoundBuffer& bffr){
  std::vector<sf::Int16> samples;
  for(int i = 0; i < length; i++){
    if(sound_external::Sinewave(i, freq, amp) > amp / 2) samples.push_back((double) (-amp * i / length + amp) * 32767);
    else samples.push_back(0);
  }
  bffr.loadFromSamples(&samples[0], samples.size(), 1, 44100);
  snd.setBuffer(bffr);
  snd.play();
}

int main(){
  std::vector<sf::Sound> sndvec;
  std::vector<sf::SoundBuffer> bffrvec;
  int polyphony{4};

  int notepos{0};
  for(int i = 0; i < polyphony; i++){
    sndvec.push_back(sf::Sound());
  }
  for(int i = 0; i < polyphony; i++){
    bffrvec.push_back(sf::SoundBuffer());
  }
  sf::RenderWindow window(sf::VideoMode(600, 600), "sonido");
  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      switch(event.type){
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::MouseButtonPressed:
          std::cout << "mouse button pressed" << std::endl;
          break;
        //QUE SE VAYAN ALTERNANDO ENTRE VEC[0] Y VEC[1] A MEDIDA Q SE VAN TOCANDO NOTAS
        case sf::Event::KeyPressed:
          switch(event.key.code){
            case sf::Keyboard::F:
              std::cout << "F key pressed" << std::endl;
              SqrSound_pluck(F4_FREQ, 0.7, 40000, sndvec[notepos], bffrvec[notepos]);
              std::cout << "antes: " << notepos << std::endl;
              notepos = (notepos == polyphony - 1) ? 0 : notepos + 1;
              std::cout << "despues: " << notepos << std::endl;
              break;
            case sf::Keyboard::T:
              std::cout << "T key pressed" << std::endl;
              SqrSound_pluck(FSHRP4_FREQ, 0.7, 40000, sndvec[notepos], bffrvec[notepos]);
              notepos = (notepos == polyphony - 1) ? 0 : notepos + 1;
              break;
          }
      }
    }
    window.clear();
    window.display();
  }
}