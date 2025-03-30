#include "Sphere.h"

Sphere::Sphere(glm::vec3 center, float radius, glm::vec3 color, glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float specularpower)
	: center(center), radius(radius), color(color), ka(ka), kd(kd), ks(ks), specularpower(specularpower)
{
}

bool Sphere::intersect(Ray& ray, float& t) const
{
    glm::vec3 oc = ray.getOrigin() - center;
    float a = glm::dot(ray.getDirection(), ray.getDirection());
    float b = 2.0f * glm::dot(oc, ray.getDirection());
    float c = glm::dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    else {
        float sqrt_discriminant = std::sqrt(discriminant);
        float t1 = (-b - sqrt_discriminant) / (2.0f * a);
        float t2 = (-b + sqrt_discriminant) / (2.0f * a);

        // t1�� t2 �� �� ���� ���� ���� ����
        if (t1 > 0 && t1 <= t2) {
            t = t1;
        }
        else {
            t = t2;
        }

        return true;
    }
}

glm::vec3 Sphere::Shading(Light light, Ray ray, glm::vec3 hitpoint, bool isShadow) const
{
    // ���� ���� ���
    glm::vec3 normal = getNormal(hitpoint);

    // ���� ���� ���
    glm::vec3 lightDir = glm::normalize(light.getPosition() - hitpoint);

    // Ȯ�� �ݻ�(Diffuse)
    glm::vec3 diffuse =  kd * light.getIntensity() * std::max(0.0f, glm::dot(normal, lightDir)) * light.getColor();

    // �ݻ籤(Specular)
    glm::vec3 h = glm::normalize(lightDir + glm::normalize(ray.getDirection()-hitpoint));
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


