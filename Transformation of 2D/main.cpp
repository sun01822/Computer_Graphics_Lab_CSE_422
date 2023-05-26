/* MD. Shariar Hossain Sun
   ID: 201311057
*/

#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;

double p1,p2,p3,q1,q2,q3;


void initValue(){
    p1 = -0.6, p2 = -0.4, p3 = -0.2, q1 = 0.1, q2 = 0.5, q3 = 0.1;
}
void triangleFunction(double p1, double q1, double p2, double q2, double p3, double q3){
    glVertex2f(p1,q1);
    glVertex2f(p2,q2);
    glVertex2f(p2,q2);
    glVertex2f(p3,q3);
    glVertex2f(p3,q3);
    glVertex2f(p1,q1);
}
void translateFunction(double tx,double ty){
    p1+=tx;
    p2+=tx;
    p3+=tx;
    q1+=ty;
    q2+=ty;
    q3+=ty;
}
void scalarFunction(double sx, double sy){
    p1*=sx;
    p2*=sx;
    p3*=sx;
    q1*=sy;
    q2*=sy;
    q3*=sy;
}
void rotationFunction(double theta){
    double radian = theta * (3.1416/180);
    p1 = (p1*cos(radian)) - (q1*sin(radian));
    q1 = (q1*cos(radian)) + (p1*sin(radian));
    p2 = (p2*cos(radian)) - (q2*sin(radian));
    q2 = (q2*cos(radian)) + (p2*sin(radian));
    p3 = (p3*cos(radian)) - (q3*sin(radian));
    q3 = (q3*cos(radian)) + (p3*sin(radian));
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3d(0,0,0);
    glVertex2f(-1.0,0);
    glVertex2f(1.0,0);
    glVertex2f(0,-1.0);
    glVertex2f(0,1.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3d(1,0,0);
    initValue();
    triangleFunction(p1,q1,p2,q2,p3,q3);
    glEnd();
    glBegin(GL_LINES);
    translateFunction(0.2,-0.5);
    triangleFunction(p1,q1,p2,q2,p3,q3);
    glEnd();
    glBegin(GL_LINES);
    scalarFunction(2,2);
    triangleFunction(p1,q1,p2,q2,p3,q3);
    glEnd();
    glBegin(GL_LINES);
    initValue();
    rotationFunction(-180);
    triangleFunction(p1,q1,p2,q2,p3,q3);
    glEnd();
    glFlush();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutCreateWindow("Transformation");
    glClearColor(1,1,1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
