#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <math.h>
#include <iostream>

using namespace std;

glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);

//perspective true, ortho false.
bool perspective = true;

void controls(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if(action == GLFW_PRESS){
		if(key == GLFW_KEY_ESCAPE){
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		//Press P to change perspective
		else if(key == GLFW_KEY_P){
			if(perspective) perspective = false;
			else 			perspective = true; 
		}
	}
}

void display( GLFWwindow* window ) {
	while(!glfwWindowShouldClose(window)) {

		GLint windowWidth, windowHeight;
		glfwGetWindowSize(window, &windowWidth, &windowHeight);
		glViewport(0, 0, windowWidth, windowHeight);

		glClearColor(0.0, 0.8, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		if(perspective)
		{
			gluPerspective(60, (double)windowWidth / (double)windowHeight, 0.1, 100 );
			gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 
			cameraPos[0] + cameraFront[0], cameraPos[1] + cameraFront[1], cameraPos[2] + cameraFront[2], 
			cameraUp[0], cameraUp[1], cameraUp[2]);
		} 
		else 
		{
			double dist = sqrt(1 / 3.0);
			gluLookAt(dist, dist, dist, 0.0,  0.0,  0.0, 0.0,  1.0,  0.0);
		}

		glMatrixMode(GL_MODELVIEW);

		glBegin(GL_LINES);

		glColor3d(0.0, 1.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(1.0, 0.0, 0.0);

		glColor3d(0.0, 1.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 1.0, 0.0);

		glColor3d(0.0, 1.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, 1.0);

		glColor3d(0.0, 1.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(1.0, 0.0, 0.0);

		glEnd();
		 
		glFlush();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

int main(int argc, char** argv) {

	GLFWwindow* window = glfwCreateWindow(800, 600, "Projection", NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, controls);


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