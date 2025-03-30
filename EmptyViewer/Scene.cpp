#include "Scene.h"  
glm::vec3 Scene::trace(Ray& ray) const  
{  
   float closest_t = std::numeric_limits<float>::max();  
   const Surface* closest_object = nullptr;  
   Light light = *lights[0];  
   glm::vec3 hitpoint;  
   bool isShadow = false;
 
   // 모든 객체와의 교차 검사  
   for (const auto& object : objects) {  
       float t;  
       if (object->intersect(ray, t) && t < closest_t) {  
           closest_t = t;  
           closest_object = object;  
           hitpoint = ray.getOrigin() + ray.getDirection() * t;  
       }  
   }  

   isShadow = checkShadow(light, closest_object, hitpoint);
   // 가장 가까운 객체가 있으면 해당 객체의 색상을 반환  
   if (closest_object) {  
       return gammaCorrection(closest_object->Shading(light, ray, hitpoint, isShadow), 2.2f);
   }  
 
   // 교차하는 객체가 없으면 배경색(예: 검정색)을 반환  
   return glm::vec3(0.0f, 0.0f, 0.0f);  
}  
 
bool Scene::checkShadow(Light light, const Surface* object, glm::vec3 hitpoint) const  
{  
   glm::vec3 lightDir = glm::normalize(light.getPosition() - hitpoint);// 광원의 위치에서 교차점(hitpoint)까지의 방향을 계산  
   glm::vec3 shadowRayOrigin = hitpoint + lightDir * 0.001f;// 그림자 레이 시작점은 교차점(hitpoint) 근처로 설정 (교차점과 같은 지점에서의 교차를 방지하기 위해 약간의 오프셋 추가)  
   Ray shadowRay(shadowRayOrigin, lightDir);// 그림자 레이 생성  
 
   for (const auto& obj : objects) {  
       float t;  
       if (obj == object) continue;  
       if (obj->intersect(shadowRay, t)) {  
           if(t < 0)
			   continue;//이전 교차점에 교차하는 경우는 무시
           return true;  
       }  
   }  
   return false;
}
