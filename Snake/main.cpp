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

void display_callback();

void reshape_callback(int, int);

void init() {
    // Setting the window color
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    // Giving a default display color to the window
    glutInitDisplayMode(GLUT_RGBA |  GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    // Creating the window name
    glutCreateWindow("🐍");
    // Overlay is established
    glutDisplayFunc(display_callback);
    // Reshaping the window based on (reshape_callback)'s needs
    glutReshapeFunc(reshape_callback);
    init();
    glutMainLoop();
    return 0;
}

void display_callback() {
    // Clearing the Color Buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void reshape_callback(int a, int b) {
    glViewport(0, 0, (GLsizei)a, (GLsizei)b);
    // Allowing the view to be shown in matrix format
    glMatrixMode(GL_PROJECTION);
    // Make sure that there are no changes made to the matrix (default)
    glLoadIdentity();
    // Setting an orthographic projection (2D)
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    // Switching back to model view matrix
    glMatrixMode(GL_MODELVIEW);
}
