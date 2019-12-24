//
//  main.cpp
//  Snake
//
//  Created by Ritik Raina on 12/24/19.
//  Copyright © 2019 rraina. All rights reserved.
//
#include <OpenGL/gl3.h>
#include <GLUT/GLUT.h>

void display_callback();

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB |  GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("🐍");
    glutDisplayFunc(display_callback);
    glutMainLoop();
    return 0;
}

void display_callback() {
    glutSwapBuffers();
}
