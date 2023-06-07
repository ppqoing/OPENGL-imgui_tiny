#pragma once
#include<glm/glm.hpp>
#include<learnopengl/shader.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;
class direrctLight
{
public:
    int ID;
    vec3 direction;
    vec3 color;
   // float ambient;  //环境光
    float diffuse;  //漫反射
    float specular_power;
    float specular_space;//镜面
	direrctLight();
};
class pointLight  //Fatt=1.0/(k0+k1*d+k2*d2)
{
public:
    int ID;
    vec3 position;
    vec3 color;
    float diffuse;  //漫反射
    float specular_power;
    float specular_space;//镜面
    float k1;
    float k2;

	pointLight();

private:
    float k0;

};
class spotLight
{
public:
	spotLight();
    int ID;
    vec3 direction;
    vec3 color;
    vec3 position;
    float directDot;
};
class lightModle
{
public:
    unsigned int lightVAO;
    unsigned int VBO;
    vec3 position;
    vec3 color;
    float size;
    Shader lightCube;
    lightModle();
    void init();
    lightModle(vec3 pos, vec3 col, float s);
    void bind_glad();
    void render(mat4 projection, mat4 view, vec3 color,vec3 pos);
    lightModle& operator=(lightModle l)
    {
        lightVAO = l.lightVAO;
        VBO = l.VBO;
        position = l.position;
        color = l.color;
        size = l.size;
        lightCube = l.lightCube;
        return *this;
         
    }
private:
    float vertices[128] = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    };

   


};

