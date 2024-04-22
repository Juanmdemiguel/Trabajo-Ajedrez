#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/gtc/type_ptr.hpp>
#include"shaderClass.h"

class Camera
{
public:

	// Tama�o de la ventana
	int width;
	int height;

	// Posici�n de la c�mara en un vector
	glm::vec3 Position;
	//Donde mira la c�mara
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	//Define ejes. En este caso el vertical es el y
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	void Matrix(Shader& shader, const char* uniform);

	// Declaraci�n del constructor
	Camera(int width, int height, glm::vec3 position);
};
#endif