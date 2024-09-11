//mingw32-make -f MakeFile
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "sound.h"

#define C4_FREQ 261.63
#define CSHRP4_FREQ 277.18
#define D4_FREQ 293.66
#define DSHRP4_FREQ 311.13
#define E4_FREQ 329.63
#define F4_FREQ 349.228
#define FSHRP4_FREQ 369.994
#define G4_FREQ 392
#define GSHRP4_FREQ 415.30
#define A4_FREQ 440
#define ASHRP4_FREQ 466.16
#define B4_FREQ 493.88
#define C5_FREQ 523.3

sf::SoundBuffer buffer;
sf::Sound sound;

/*void SetOscSound(double freq, double amp, double length){
  std::vector<sf::Int16> samples;
  for(int i = 0; i < length; i++){
    samples.push_back(sound_external::Sinewave(i, freq, amp));
  }
  buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);
  sound.setBuffer(buffer);
}*/

void SetOscSound_pluck(double freq, double amp, double length){
  std::vector<sf::Int16> samples;
  for(int i = 0; i < length; i++){
    samples.push_back(sound_external::Sinewave(i, freq, (double) -amp * i / length + amp));
  }
  buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);
  sound.setBuffer(buffer);
}

void SetSqrSound(double freq, double amp, double length){
  std::vector<sf::Int16> samples;
  for(int i = 0; i < length; i++){
    if(sound_external::Sinewave(i, freq, amp) > amp / 2) samples.push_back(amp * 32767);
    else samples.push_back(0);
  }
  buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);
  sound.setBuffer(buffer);
}

void SetSqrSound_pluck(double freq, double amp, double length){
  std::vector<sf::Int16> samples;
  for(int i = 0; i < length; i++){
    if(sound_external::Sinewave(i, freq, amp) > amp / 2) samples.push_back((double) (-amp * i / length + amp) * 32767);
    else samples.push_back(0);
  }
  buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);
  sound.setBuffer(buffer);
}

int main(){
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
        case sf::Event::KeyPressed:
          switch(event.key.code){
            case sf::Keyboard::W:
              std::cout << "W key pressed" << std::endl;
              SetSqrSound_pluck(C4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::S:
              std::cout << "S key pressed" << std::endl;
              SetSqrSound_pluck(CSHRP4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::E:
              std::cout << "E key pressed" << std::endl;
              SetSqrSound_pluck(D4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::D:
              std::cout << "D key pressed" << std::endl;
              SetSqrSound_pluck(DSHRP4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::R:
              std::cout << "R key pressed" << std::endl;
              SetSqrSound_pluck(E4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::F:
              std::cout << "F key pressed" << std::endl;
              SetSqrSound_pluck(F4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::T:
              std::cout << "T key pressed" << std::endl;
              SetSqrSound_pluck(FSHRP4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::G:
              std::cout << "G key pressed" << std::endl;
              SetSqrSound_pluck(G4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::Y:
              std::cout << "Y key pressed" << std::endl;
              SetSqrSound_pluck(GSHRP4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::H:
              std::cout << "H key pressed" << std::endl;
              SetSqrSound_pluck(A4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::U:
              std::cout << "U key pressed" << std::endl;
              SetSqrSound_pluck(ASHRP4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::J:
              std::cout << "J key pressed" << std::endl;
              SetSqrSound_pluck(B4_FREQ, 1, 40000);
              sound.play();
              break;
            case sf::Keyboard::I:
              std::cout << "I key pressed" << std::endl;
              SetSqrSound_pluck(C5_FREQ, 1, 40000);
              sound.play();
              break;
          }
      }
    }
    window.clear();
    window.display();
  }
}