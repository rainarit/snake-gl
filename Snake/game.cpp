//
//  game.cpp
//  Snake
//
//  Created by Ritik Raina on 12/24/19.
//  Copyright © 2019 rraina. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <GLUT/GLUT.h>
#include "game.hpp"

int gridX;
int gridY;

// Creating a grid
void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}

// Draw a simple square based on drawGrid()
void unit(int x, int y) {
    if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
        // Setting the color /thickness of the line
        glLineWidth(2.0);
        glColor3f(1.0, 0.0, 0.0);
    }
    else {
        glLineWidth(1.0);
        glColor3f(0.5, 1.0, 0.5);
    }
    
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+1);
        glVertex2f(x, y+1);
    glEnd();
}

void drawGrid() {
    for (int i = 0; i < gridX; i++) {
        for (int j = 0; j < gridY; j++) {
            unit(i, j);
        }
    }
}
