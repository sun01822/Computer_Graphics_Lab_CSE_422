/*  MD. Shariar Hossain Sun
    ID: 201311057
*/

#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>

using namespace std;

double r;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);
    glBegin(GL_LINES);
    glColor3d(0,0,0);
    glVertex2f(-1.0,0);
    glVertex2f(1.0,0);
    glVertex2f(0,-1.0);
    glVertex2f(0,1.0);
    glEnd();
    glBegin(GL_POINTS);
    glColor3d(1,0,0);
    double p0 = 1 - r;
    double x=0, y=r;
    while(y>x){
        if(p0 < 0){
            p0 = p0 + (2*x) + 3;
        }
        else{
            p0 = p0 + (2*x) - (2*y) + 5;
            y--;
        }
        x++;
        glVertex2f(x/100, y/100);
        glVertex2f(y/100, x/100);
        glVertex2f(y/100, -x/100);
        glVertex2f(x/100, -y/100);
        glVertex2f(-x/100, -y/100);
        glVertex2f(-y/100, -x/100);
        glVertex2f(-y/100, x/100);
        glVertex2f(-x/100, y/100);
    }
    glEnd();
    glFlush();
}

int main(int argc, char * argv[]){
    cout << "Enter radius of the circle: ";
    cin >> r;
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutCreateWindow("Circle Drawing");
    glClearColor(1,1,1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
