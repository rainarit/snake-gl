//
//  game.hpp
//  Snake
//
//  Created by Ritik Raina on 12/24/19.
//  Copyright © 2019 rraina. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#define DOWN -1
#define UP 1
#define LEFT -2
#define RIGHT 2

#include <stdio.h>

void initGrid(int, int);
void drawGrid();
void drawSnake();
void drawFood();
void random(int, int);
#endif /* game_hpp */
