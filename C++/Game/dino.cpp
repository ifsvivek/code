
#include <GL/glut.h>
#include <unistd.h>


// Redraw your frame here...
int state = 1; // 1 for running, 0 for jumping
float jumpHeight = 0; // Height of the jump
int jumping = 0; // 1 if the dinosaur is jumping
int jumpDirection = 1; // 1 if the dinosaur is going up, -1 if going down

int dino1[23][20] = { {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
                  {1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
                  {1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
                  {1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
                  {1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0},
                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
                  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
                  {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                  {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                  {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
                  {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
int dino2[23][20] = { {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
                  {1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
                  {1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
                  {1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
                  {1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0},
                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
                  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
                  {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                  {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                  {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
                  {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
// int dino3[23][20]={{0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
//                   {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
//                   {0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1},
//                   {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
//                   {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
//                   {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
//                   {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
//                   {1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
//                   {1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
//                   {1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
//                   {1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
//                   {1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0},
//                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
//                   {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
//                   {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
//                   {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
//                   {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
//                   {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
//                   {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
//                   {0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
//                   {0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0},
//                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//                   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//                   };
//random array of 0 and 1s
int layer1[] = { 0,1,0,1,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0, };
int layer2[] = { 1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1, };


int k = 0;
// Function to initialize the window
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100.0, 0, 100.0);
}
void drawGround() {
    glPointSize(2.0);
    glBegin(GL_POINTS);

    // Draw the ground line
    for (int i = 0; i <= 1000; i++) {
        glVertex2f(i - (k % 100), 8);
    }

    // Draw the first layer of ground details
    // for (int i = 0; i < 1000; i++) {
    //     if (layer1[i] == 1) {
    //         glVertex2f(i * 5 - (k % 500), 2);
    //     }
    // }

    // // Draw the second layer of ground details
    // for (int i = 0; i < 1000; i++) {
    //     if (layer2[i] == 1) {
    //         glVertex2f(i * 2 - (k % 200), 5);
    //     }
    // }

    glEnd();
    // glBegin(GL_QUADS);
    // for (int i = 0; i < 100; i++) {
    //     if (i % 2 == 0) {
    //         float x = i * 1.5 - (k % 150);
    //         glVertex2f(x, 8);
    //         glVertex2f(x + 1, 8);
    //         glVertex2f(x + 1, 9);
    //         glVertex2f(x, 9);
    //     }
    // }
    // glEnd();
    k += 1;
    if (k >= 500) {
        k = 0;
    }
}

int frameCount = 0; // Frame counter for slowing down the leg movement

void drawDino() {
    glPointSize(6.9);
    glBegin(GL_POINTS);

    int(*dino)[20];
    if (frameCount % 60 == 0) { // Change sprite every 30 frames
        if (state == 1) {
            dino = dino1; // Running sprite 1
            state = 2;
        } else {
            dino = dino2; // Running sprite 2
            state = 1;
        }
    } else {
        if (state == 1) {
            dino = dino1; // Running sprite 1
        } else {
            dino = dino2; // Running sprite 2
        }
    }

    frameCount++; // Increment frame counter

    for (int i = 21; i >= 0; i--) {
        for (int j = 19; j >= 0; j--) {
            if (dino[i][j] == 1) {
                glVertex2f(j + 10, 26 - i + jumpHeight);
            }
        }
    }
    glEnd();

    // Manage the jump
    if (jumping) {
        jumpHeight += 3.45 * jumpDirection;
        if (jumpHeight >= 40) {
            jumpDirection = -1; // Start going down
        }
        usleep(20000); // Sleep for 0.02 seconds
        if (jumpHeight <= 0) {
            jumpHeight = 0;
            jumping = 0;
            jumpDirection = 1; // Reset for the next jump
        }
    }

    glutPostRedisplay();
}


// Function to handle keyboard input for jump
void keyboard(unsigned char key, int x, int y) {
    if (key == ' ' && !jumping) {
        jumping = 1;
        jumpHeight = 0;
    }
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Adjust the orthographic projection based on the aspect ratio
    if (aspect > 1.0f) {
        // Wide window
        gluOrtho2D(0.0, 100.0 * aspect, 0.0, 100.0);
    } else {
        // Tall window
        gluOrtho2D(0.0, 100.0, 0.0, 100.0 / aspect);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void timer(int value) {
    glutPostRedisplay(); // Request a redraw
    // usleep(16000); // Sleep for 0.016 seconds
    glutTimerFunc(16, timer, 0); // Set up the next timer for roughly 60fps
}
// Function to draw the dinosaur sprite
void draw() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the window

    drawGround(); // Draw the ground
    drawDino(); // Draw the dinosaur

    glutSwapBuffers(); // Swap the buffers

    glFlush(); // Flush the OpenGL buffers to the window
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(800, 600);
    glutCreateWindow("Dino Game");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 20, 0, 23, -1, 1);

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);  // Set the reshape callback
    glutKeyboardFunc(keyboard);
    glutTimerFunc(100, timer, 0);

    glutMainLoop();

    return 0;
}
