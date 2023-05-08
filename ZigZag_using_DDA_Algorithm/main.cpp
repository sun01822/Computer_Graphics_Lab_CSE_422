#include<windows.h>
#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

void DDA(double p1, double q1, double p2, double q2);

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);
    glColor3d(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(-1.0,0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0,-1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_POINTS);
    glColor3d(0,1,0);
    DDA(-80,10,-50,90);
    DDA(-50,90,-10,10);
    DDA(-10,10,20,90);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutCreateWindow("ZigZap");
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}

void DDA(double p1, double q1, double p2, double q2){
    double m = (q2-q1)/(p2-p1);
    if(m<1){
        if(p1 > p2){
            swap(p1,p2);
            swap(q1,q2);
        }
        while(p1<=p2){
            glVertex2f(p1/100, q1/100);
            p1+=1;
            q1+=m;
        }
    }
    else if(m>1){
        if(q1>q2){
            swap(p1,p2);
            swap(q1,q2);
        }
        while(q1<=q2){
            glVertex2f(p1/100, q1/100);
            p1+=(1/m);
            q1+=1;
        }
    }

}

