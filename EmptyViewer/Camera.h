#pragma once
#include "Ray.h"
class Camera
{
public:
	Camera(glm::vec3 e);
	~Camera();
	Ray getRay(float i, float j);
private:
	glm::vec3 e;
	glm::vec3 u;
	glm::vec3 v;
	glm::vec3 w;
	glm::vec3 up;
	float l;
	float r;
	float b;
	float t;
	float d;
	int nx;
	int ny;
	glm::vec3 getEye();
	glm::vec3 getU();
	glm::vec3 getV();
	glm::vec3 getW();
	glm::vec3 getUp();
};
