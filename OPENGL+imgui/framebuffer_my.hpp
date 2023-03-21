#pragma once
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include <learnopengl/shader.h>
#include<iostream>
using namespace std;
class f_buffer_scr
{
public:
	f_buffer_scr(unsigned int SCR_WIDTH,unsigned int SCR_HEIGHT);
	void f_buffer_begin();
    void f_buffer_end();
unsigned int framebuffer;
    unsigned int quadVAO, quadVBO;
unsigned int textureColorbuffer;
    unsigned int rbo;

private:
float quadVertices[24] = { 
 
    -1.0f,  1.0f,  0.0f, 1.0f,
    -1.0f, -1.0f,  0.0f, 0.0f,
     1.0f, -1.0f,  1.0f, 0.0f,

    -1.0f,  1.0f,  0.0f, 1.0f,
     1.0f, -1.0f,  1.0f, 0.0f,
     1.0f,  1.0f,  1.0f, 1.0f
};
Shader screenShader=Shader("../shader_defult/5.1.framebuffers_screen.vs", "../shader_defult/5.1.framebuffers_screen.fs");


};
