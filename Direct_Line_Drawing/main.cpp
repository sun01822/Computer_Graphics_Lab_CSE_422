#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>

using namespace std;

double p1, p2, q1, q2;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);
    glBegin(GL_LINES);
    glColor3d(0,0,0);
    glVertex2f(-1.0,0);
    glVertex2f(1.0,0);
    glVertex2f(0,1.0);
    glVertex2f(0,-1.0);
    glEnd();
    glBegin(GL_POINTS);
    glColor3d(1,0,0);
    if(p1 > p2){
        swap(p1,p2);
        swap(q1,q2);
    }
    double m = (q2-q1) / (p2-p1);
    double b = q1 - (m*p1);
    while(p1<=p2){
        glVertex2f(p1/100,q1/100);
        p1+=1;
        q1 = (m*p1) + b;
    }
    glEnd();
    glFlush();
}

int main(int argc, char * argv[]){
    cout << "Enter (p1,q1): ";
    cin >> p1 >> q1;
    cout << "Enter (p2,q2): ";
    cin >> p2 >> q2;
    glutInit(&argc, argv);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutCreateWindow("Direct Line Drawing");
    glClearColor(1,1,1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
