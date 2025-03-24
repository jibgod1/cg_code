#include "Camera.h"
#include "Camera.h"

Camera::Camera(glm::vec3 e)
	: e(e), u(glm::vec3(1.0f, 0.0f, 0.0f)), v(glm::vec3(0.0f, 1.0f, 0.0f)), w(glm::vec3(0.0f, 0.0f, 1.0f)), up(glm::vec3(0.0f, 1.0f, 0.0f)),
	l(-1.0f), r(1.0f), b(-1.0f), t(1.0f), d(0.1f), nx(512), ny(512)
{ 

}

Camera::~Camera()
{
    // Destructor implementation
}

Ray Camera::getRay(float i, float j)
{
    glm::vec3 direction = glm::normalize(u * ((i + 0.5f) * (r - l) / nx + l) + 
        v * ((j + 0.5f) * (t - b) / ny + b) - w * d);
    return Ray(e, direction);
}

glm::vec3 Camera::getEye() { return e; }
glm::vec3 Camera::getU() { return u; }
glm::vec3 Camera::getV() { return v; }
glm::vec3 Camera::getW() { return w; }
glm::vec3 Camera::getUp() { return up; }
