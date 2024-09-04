#include <iostream>
#include <windows.h>
#include <conio.h>

#define F_KEY 70

using namespace std;

int main(){
  char key{' '};
  while(key != 'x'){
    key = getch();
    if(key == 'f'){
      cout << "Key Pressed" << endl;
    }
  }
}