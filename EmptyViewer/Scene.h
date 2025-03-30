#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <limits>
#include "Surface.h"
#include "Light.h"


class Scene {
private:
    std::vector<Surface*> objects;
    std::vector<Light*> lights;
   
public:
    void addObject(Surface* object) {
        objects.push_back(object);
    }
    void addLight(Light* light) {
        lights.push_back(light);
    }
    glm::vec3 trace(Ray& ray) const;
    bool checkShadow(Light light, const Surface* object, glm::vec3 hitpoint) const;
    glm::vec3 gammaCorrection(glm::vec3 color, float gamma) const{
        return glm::pow(color, glm::vec3(1.0f / gamma));
    }
};