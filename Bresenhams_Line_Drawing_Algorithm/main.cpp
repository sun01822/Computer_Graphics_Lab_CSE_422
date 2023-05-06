#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>

using namespace std;

double p1,p2,q1,q2;


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);
    glColor3d(0,0,0);
    glBegin(GL_LINES);
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
    double del_x = p2 - p1;
    double del_y = q2 - q1;
    double del_x2 = 2 * del_x;
    double del_y2 = 2 * del_y;
    if(m < 1){
        double p0 = del_y2 - del_x;
        while(p1 <= p2){
            glVertex2f(p1/100,q1/100);
            if(p0 < 1){
                p1+=1;
                p0+=del_y2;
            }
            else{
                p1+=1;
                q1+=1;
                p0+=(del_y2 - del_x2);
            }
        }
    }
    else if(m > 1){
        double p0 = del_x2 - del_y;
        while(q1<=q2){
            glVertex2f(p1/100,q1/100);
            if(p0 < 0){
                q1+=1;
                p0+=del_x2;
            }
            else{
                p1+=1;
                q1+=1;
                p0+=(del_x2-del_y2);
            }
        }
    }
    glEnd();
    glFlush();
}


int main(int argc, char * argv[]){
    cout << "Enter (p1,q1): ";
    cin >> p1 >> q1;
    cout << "Enter (p2,q2): ";
    cin >> p2 >> q2;
    glutInit(&argc,argv);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutCreateWindow("Bresenhams Line Drawing Algorithm");
    glClearColor(1,1,1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
