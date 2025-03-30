#pragma once
#include "Surface.h"
class Sphere : public Surface
{
public:
	Sphere(glm::vec3 center, float radius, glm::vec3 color, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float specularpower);
	bool intersect(Ray& ray, float& t) const override;
	glm::vec3 getColor() const override { return color; }
	glm::vec3 getNormal(glm::vec3& point) const override { return glm::normalize(point - center); }
	glm::vec3 getCenter() const { return center; }
	glm::vec3 Shading(Light light, Ray ray, glm::vec3 hitpoint, bool isShadow) const override;
private:
	glm::vec3 center;
	float radius;
	glm::vec3 color;
	glm::vec3 normal;
	glm::vec3 ka;
	glm::vec3 kd;
	glm::vec3 ks;
	float specularpower;
};

