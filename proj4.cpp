#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  srand (time(NULL));
  Game g;
  g.StartGame();
  return 0;
}
