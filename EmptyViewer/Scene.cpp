#include "Scene.h"  
glm::vec3 Scene::trace(Ray& ray) const  
{  
   float closest_t = std::numeric_limits<float>::max();  
   const Surface* closest_object = nullptr;  
   Light light = *lights[0];  
   glm::vec3 hitpoint;  
   bool isShadow = false;
 
   // ��� ��ü���� ���� �˻�  
   for (const auto& object : objects) {  
       float t;  
       if (object->intersect(ray, t) && t < closest_t) {  
           closest_t = t;  
           closest_object = object;  
           hitpoint = ray.getOrigin() + ray.getDirection() * t;  
       }  
   }  

   isShadow = checkShadow(light, closest_object, hitpoint);
   // ���� ����� ��ü�� ������ �ش� ��ü�� ������ ��ȯ  
   if (closest_object) {  
       return gammaCorrection(closest_object->Shading(light, ray, hitpoint, isShadow), 2.2f);
   }  
 
   // �����ϴ� ��ü�� ������ ����(��: ������)�� ��ȯ  
   return glm::vec3(0.0f, 0.0f, 0.0f);  
}  
 
bool Scene::checkShadow(Light light, const Surface* object, glm::vec3 hitpoint) const  
{  
   glm::vec3 lightDir = glm::normalize(light.getPosition() - hitpoint);// ������ ��ġ���� ������(hitpoint)������ ������ ���  
   glm::vec3 shadowRayOrigin = hitpoint + lightDir * 0.001f;// �׸��� ���� �������� ������(hitpoint) ��ó�� ���� (�������� ���� ���������� ������ �����ϱ� ���� �ణ�� ������ �߰�)  
   Ray shadowRay(shadowRayOrigin, lightDir);// �׸��� ���� ����  
 
   for (const auto& obj : objects) {  
       float t;  
       if (obj == object) continue;  
       if (obj->intersect(shadowRay, t)) {  
           if(t < 0)
			   continue;//���� �������� �����ϴ� ���� ����
           return true;  
       }  
   }  
   return false;
}
