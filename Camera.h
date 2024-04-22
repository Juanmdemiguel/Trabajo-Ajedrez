#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/gtc/type_ptr.hpp>
#include"shaderClass.h"

class Camera
{
public:

	// Tamaño de la ventana
	int width;
	int height;

	// Posición de la cámara en un vector
	glm::vec3 Position;
	//Donde mira la cámara
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	//Define ejes. En este caso el vertical es el y
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	void Matrix(Shader& shader, const char* uniform);

	// Declaración del constructor
	Camera(int width, int height, glm::vec3 position);
};
#endif