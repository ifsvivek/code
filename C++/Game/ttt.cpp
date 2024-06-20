#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<GLUT/glut.h>

int matrix[3][3]; //this matrix stores the x and o and blank box of the game, a value of 0 is blank, 1 is x and 2 is o
int playerturn; //playerturn if it is 1 then 1st players turn else if it is 2 then its second players turn
int result; //result of the game if it is 0 then draw if it is 1 then player 1 wins if it is 2 then player 2 wins
bool gameover; //gameover if it is 0 then its not game over else if it is 1 then its game over

//initialize the game
void initgame() {
	playerturn = 1; //x starts first

	//clear the matrix
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			matrix[i][j] = 0;
		}
	}
}

//this function is called when keyboard button is pressed 
void KeyPress(unsigned char key, int x, int y) {
	switch (key) {
	case 'y':
		if (gameover == true) {
			gameover = false;
			initgame();
		}
		break;
	case 'n':
		if (gameover == true)
			exit(0);
		break;
	case 27:
		exit(0);

	}
}

//This function is called when the mouse button is pressed and this function puts the x or o on the blank box 
void click(int button, int state, int x, int y) {
	if (gameover == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (playerturn == 1) {
			if (matrix[(y - 50) / 100][x / 100] == 0) {
				matrix[(y - 50) / 100][x / 100] = 1;
				playerturn = 2;
			}
		} else {
			if (matrix[(y - 50) / 100][x / 100] == 0) {
				matrix[(y - 50) / 100][x / 100] = 2;
				playerturn = 1;
			}
		}
	}
}

//Used to write text in the opengl window
void drawString(void* font, char* s, float x, float y) {
	unsigned int i;
	glRasterPos2f(x, y);
	for (i = 0; i < strlen(s); i++)
		glutBitmapCharacter(font, s[i]);
}

//This function is used to draw the 4 lines 2 vertical and 2 horizontal
void drawlines() {
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	//2 vertical lines
	glVertex2f(100, 50);
	glVertex2f(100, 340);
	glVertex2f(200, 340);
	glVertex2f(200, 50);
	//2 horizontal lines
	glVertex2f(0, 150);
	glVertex2f(300, 150);
	glVertex2f(0, 250);
	glVertex2f(300, 250);
	glEnd();
}

//This Function Draw the x and o's
void drawxo() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (matrix[i][j] == 1) //if it is 1 then draw x 
			{
				glBegin(GL_LINES);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
				glEnd();
			} else if (matrix[i][j] == 2) //if it is 2 then draw o
			{
				glBegin(GL_LINE_LOOP);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
				glEnd();
			}
		}
	}
}

//This function checks if there is any winner
bool checkifwin() {
	int i, j;

	//check if there are horizontal win i.e if there is any row that has same value
	for (i = 0; i <= 2; i++) {
		for (j = 1; j <= 2; j++) {
			if (matrix[i][0] != 0 && matrix[i][0] == matrix[i][j]) {
				if (j == 2)
					return true;
			} else
				break;
		}
	}

	//check if there are vertical win i.e if there is any column that has same value
	for (i = 0; i <= 2; i++) {
		for (j = 1; j <= 2; j++) {
			if (matrix[0][i] != 0 && matrix[0][i] == matrix[j][i]) {
				if (j == 2)
					return true;
			} else
				break;
		}
	}

	//check if there is any diagonal win i.e. if there is any diagonals that has same value
	for (i = 1; i <= 2; i++) {
		if (matrix[0][0] != 0 && matrix[0][0] == matrix[i][i]) {
			if (i == 2)
				return true;
		} else
			break;
	}
	for (i = 1; i <= 2; i++) {
		if (matrix[2][0] != 0 && matrix[2][0] == matrix[2 - i][i]) {
			if (i == 2)
				return true;
		} else
			break;
	}
}

//This function checks if the match is a draw i.e it returns false if there is atleast one empty box else returns true 
bool checkifdraw() {
	int i, j;
	bool draw;

	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= 2; j++) {
			if (matrix[i][j] == 0)
				return false;
		}
	}
	return true;
}

//This is the idle call back function
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);
	if (playerturn == 1)
		drawString(GLUT_BITMAP_HELVETICA_18, "Player1's turn", 100, 30);
	else
		drawString(GLUT_BITMAP_HELVETICA_18, "Player2's turn", 100, 30);

	drawlines();
	drawxo();

	if (checkifwin() == true) {
		//the player who made the previous move is the winner
		if (playerturn == 1) {
			gameover = true;
			result = 2; //player2 wins
		} else {
			gameover = true;
			result = 1; //player1 wins
		}
	} else if (checkifdraw() == true) {
		gameover = true;
		result = 0;
	}

	if (gameover == true) {
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 100, 160);

		if (result == 0)
			drawString(GLUT_BITMAP_HELVETICA_18, "Its a draw", 110, 185);

		if (result == 1)
			drawString(GLUT_BITMAP_HELVETICA_18, "Player1 wins", 95, 185);

		if (result == 2)
			drawString(GLUT_BITMAP_HELVETICA_18, "Player2 wins", 95, 185);

		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to continue (y/n)", 40, 210);
	}

	glutSwapBuffers();
}

//This function is called on windows resize
void reshape(int x, int y) {
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

//main function of the program
int main(int argc, char** argv) {
	initgame();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 350);
	glutCreateWindow("Tic Tac Toe");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(KeyPress);
	glutMouseFunc(click);
	glutIdleFunc(display);
	glutMainLoop();
}