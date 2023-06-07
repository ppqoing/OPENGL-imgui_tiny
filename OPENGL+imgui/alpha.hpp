#pragma once
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<iostream>
//#include<stb_image/stb_image.h>
#include<learnopengl/shader.h>
using namespace glm;

class alpha_img
{
public:
    alpha_img();
    void init();
	alpha_img(char const * path,vec3 pos);
    unsigned int transparentVAO;
    unsigned int transparentVBO;
    vec3 position;
    float size;
    unsigned int textureID;
    void load();
    void set_size(float s);
    void set_position(vec3 p);
    void render(mat4 v,mat4 p);
    alpha_img &operator=(alpha_img a)
    {
        transparentVAO = a.transparentVAO;
        transparentVBO = a.transparentVBO;
        position = a.position;
        size = a.size;
        textureID = a.textureID;
        return *this;
    }
private:
    Shader shader ;
    float transparentVertices[30] = {
        // positions         // texture Coords (swapped y coordinates because texture is flipped upside down)
        0.0f,  0.5f,  0.0f,  0.0f,  1.0f,
        0.0f, -0.5f,  0.0f,  0.0f,  0.0f,
        1.0f, -0.5f,  0.0f,  1.0f,  0.0f,

        0.0f,  0.5f,  0.0f,  0.0f,  1.0f,
        1.0f, -0.5f,  0.0f,  1.0f,  0.0f,
        1.0f,  0.5f,  0.0f,  1.0f,  1.0f
    };
};

