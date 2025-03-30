#include "Plane.h"

Plane::Plane(glm::vec3 normal, glm::vec3 point, glm::vec3 color, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float specularpower)
	: normal(normal), point(point), color(color), ka(ka), kd(kd), ks(ks), specularpower(specularpower)
{
}

bool Plane::intersect(Ray& ray, float& t) const
{
    float denom = glm::dot(normal, ray.getDirection());
    if (glm::abs(denom) > 1e-6) { // denom이 0이 아니면
        t = glm::dot(point - ray.getOrigin(), normal) / denom;
        return (t >= 0);
    }
    return false; // 평면과 광선이 평행함
}

glm::vec3 Plane::Shading(Light light, Ray ray, glm::vec3 hitpoint, bool isShadow) const
{
    // 광원 방향 계산
    glm::vec3 lightDir = glm::normalize(light.getPosition() - hitpoint);

    // 확산 반사(Diffuse)
    glm::vec3 diffuse = kd * light.getIntensity() * std::max(0.0f, glm::dot(normal, lightDir)) * light.getColor();

    // 반사광(Specular)
    glm::vec3 h = glm::normalize(lightDir + glm::normalize(ray.getDirection()));
    glm::vec3 specular = ks * light.getIntensity() * pow(std::max(0.0f, glm::dot(normal, h)), specularpower) * light.getColor();

    // 주변광(Ambient)
    glm::vec3 ambient = ka * light.getIntensity() * light.getColor();

    // 그림자 처리: 그림자에 있으면 diffuse와 specular를 0으로
    if (isShadow) {
        diffuse = glm::vec3(0.0f, 0.0f, 0.0f);
        specular = glm::vec3(0.0f, 0.0f, 0.0f);
    }


    // 최종 색상 계산
    glm::vec3 color = this->color * (ambient + diffuse + specular);

    return color;
}
