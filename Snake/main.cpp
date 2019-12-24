//
//  main.cpp
//  Snake
//
//  Created by Ritik Raina on 12/24/19.
//  Copyright © 2019 rraina. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <GLUT/GLUT.h>
#include "game.hpp"

// Dimensions for the grid
#define COLUMNS 50
#define ROWS 50

// Desired frame-per-secomd (fps)
#define FPS 10

void timerCallback(int);

void displayCallback();

void reshapeCallback(int, int);

void init() {
    // Setting the window color
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLUMNS, ROWS);
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    // Giving a default display color to the window
    glutInitDisplayMode(GLUT_RGBA |  GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    // Creating the window name
    glutCreateWindow("🐍");
    // Overlay is established
    glutDisplayFunc(displayCallback);
    // Reshaping the window based on (reshapeCallback)'s needs
    glutReshapeFunc(reshapeCallback);
    glutTimerFunc(0, timerCallback, 0);
    init();
    glutMainLoop();
    return 0;
}

int index = 0;
void displayCallback() {
    // Clearing the Color Buffer
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glRectd(index, 10, index+1, 11);
    index++;
    if (index > 50) {
        index = 0;
    }
    glutSwapBuffers();
}

void reshapeCallback(int a, int b) {
    glViewport(0, 0, (GLsizei)a, (GLsizei)b);
    // Allowing the view to be shown in matrix format
    glMatrixMode(GL_PROJECTION);
    // Make sure that there are no changes made to the matrix (default)
    glLoadIdentity();
    // Setting an orthographic projection (2D)
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    // Switching back to model view matrix
    glMatrixMode(GL_MODELVIEW);
}

void timerCallback(int) {
    // Gives an OpenGL an urge to call displayCallback()
    glutPostRedisplay();
    int millisecond = 1000/FPS;
    glutTimerFunc(millisecond, timerCallback, 0);
}
