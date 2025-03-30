#pragma once
#include <glm/glm.hpp>
#include <limits>
#include <vector>
#include "Ray.h"
#include "Light.h"
class Surface
{
public:
    virtual bool intersect(Ray& ray, float& t) const = 0;
    virtual glm::vec3 getColor() const = 0;
    virtual glm::vec3 getNormal(glm::vec3& point) const = 0;
    virtual glm::vec3 Shading(Light light, Ray ray, glm::vec3 hitpoint, bool isShadow) const = 0;
    virtual ~Surface() = default;
};

