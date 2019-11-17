#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

using namespace std;

double oldMouseX, oldMouseY;
double newMouseX, newMouseY;
double moveX=0,	  moveY=0;
bool buttonPressed = false;

void controls(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if(action == GLFW_PRESS)
		if(key == GLFW_KEY_ESCAPE) 
			glfwSetWindowShouldClose(window, GL_TRUE);
}

//Press and release right button to move camera
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		buttonPressed = true;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE){
		buttonPressed = false;
	}
}

void drawCube()
{
    GLfloat vertices[] =
    {
        -1, -1, -1,   -1, -1,  1,   -1,  1,  1,   -1,  1, -1,
        1, -1, -1,    1, -1,  1,    1,  1,  1,    1,  1, -1,
        -1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1,
        -1,  1, -1,   -1,  1,  1,    1,  1,  1,    1,  1, -1,
        -1, -1, -1,   -1,  1, -1,    1,  1, -1,    1, -1, -1,
        -1, -1,  1,   -1,  1,  1,    1,  1,  1,    1, -1,  1
    };

    GLfloat colors[] =
    {
        0, 0, 0,   0, 0, 1,   0, 1, 1,   0, 1, 0,
        1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,
        0, 1, 0,   0, 1, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 1, 0,   1, 1, 0,   1, 0, 0,
        0, 0, 1,   0, 1, 1,   1, 1, 1,   1, 0, 1
    };

    static float alpha = 0;
    //attempt to rotate cube
    glRotatef(alpha, 0, 1, 0);

    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    /* Send data : 24 vertices */
    glDrawArrays(GL_QUADS, 0, 24);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    alpha += 1;
}

void display( GLFWwindow* window ) {
	int i = 0;
	while(!glfwWindowShouldClose(window)) {

		// Scale to window size
        GLint windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

		// Draw stuff
        glClearColor(0.0, 0.8, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();
		
		gluPerspective( 60, (double)windowWidth / (double)windowHeight, 0.1, 100 );

		//If button pressed, get the new mouse position
		//to change lookAt
		if(buttonPressed){
			glfwGetCursorPos(window, &newMouseX, &newMouseY);
			double x = oldMouseX-newMouseX;
			double y = oldMouseY-newMouseY;
			double lenVector = sqrt(pow(x, 2)+pow(y,2));
			if(lenVector != 0){
				//how much to move lookat
				moveX -= (x/lenVector)*0.2;
				moveY -= (y/lenVector)*0.2;
			}
			//move lookat
			gluLookAt(0, 0, -5, moveX, moveY, 0, 0, 1, 0);
			glfwGetCursorPos(window, &oldMouseX, &oldMouseY);
		}
		else{
			glfwGetCursorPos(window, &oldMouseX, &oldMouseY);
			gluLookAt(0, 0, -5, moveX, moveY, 0, 0, 1, 0);
		}

		drawCube();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

int main(int argc, char** argv) {
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "Mouse move camera", NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, controls);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	if( window != NULL ) {
		display( window );
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}