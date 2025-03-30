#pragma once
#include <glm/glm.hpp>
class Light
{
public:
	Light(glm::vec3 positon, glm::vec3 color, float intensity);
	glm::vec3 getPosition() const { return position; }
	glm::vec3 getColor() const { return color; }
	float getIntensity() const { return intensity; }
private:
	glm::vec3 position;
	glm::vec3 color;
	float intensity;
};

