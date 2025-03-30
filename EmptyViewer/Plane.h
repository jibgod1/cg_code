#pragma once
#include "Surface.h"
class Plane : public Surface
{
public:
	Plane(glm::vec3 normal, glm::vec3 point, glm::vec3 color, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float specularpower);
	bool intersect(Ray& ray, float& t) const override;
	glm::vec3 getNormal(glm::vec3& point) const override { return normal; }
	glm::vec3 getColor() const override { return color; }
	glm::vec3 getPoint() const { return point; }
	glm::vec3 Shading(Light light, Ray ray, glm::vec3 hitpoint, bool isShadow) const override;
private:
	glm::vec3 normal;
	glm::vec3 point;
	glm::vec3 color;
	glm::vec3 ka;
	glm::vec3 kd;
	glm::vec3 ks;
	float specularpower;
};

