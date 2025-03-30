#include "Plane.h"

Plane::Plane(glm::vec3 normal, glm::vec3 point, glm::vec3 color, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float specularpower)
	: normal(normal), point(point), color(color), ka(ka), kd(kd), ks(ks), specularpower(specularpower)
{
}

bool Plane::intersect(Ray& ray, float& t) const
{
    float denom = glm::dot(normal, ray.getDirection());
    if (glm::abs(denom) > 1e-6) { // denom�� 0�� �ƴϸ�
        t = glm::dot(point - ray.getOrigin(), normal) / denom;
        return (t >= 0);
    }
    return false; // ���� ������ ������
}

glm::vec3 Plane::Shading(Light light, Ray ray, glm::vec3 hitpoint, bool isShadow) const
{
    // ���� ���� ���
    glm::vec3 lightDir = glm::normalize(light.getPosition() - hitpoint);

    // Ȯ�� �ݻ�(Diffuse)
    glm::vec3 diffuse = kd * light.getIntensity() * std::max(0.0f, glm::dot(normal, lightDir)) * light.getColor();

    // �ݻ籤(Specular)
    glm::vec3 h = glm::normalize(lightDir + glm::normalize(ray.getDirection()));
    glm::vec3 specular = ks * light.getIntensity() * pow(std::max(0.0f, glm::dot(normal, h)), specularpower) * light.getColor();

    // �ֺ���(Ambient)
    glm::vec3 ambient = ka * light.getIntensity() * light.getColor();

    // �׸��� ó��: �׸��ڿ� ������ diffuse�� specular�� 0����
    if (isShadow) {
        diffuse = glm::vec3(0.0f, 0.0f, 0.0f);
        specular = glm::vec3(0.0f, 0.0f, 0.0f);
    }


    // ���� ���� ���
    glm::vec3 color = this->color * (ambient + diffuse + specular);

    return color;
}
