#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<iostream>
#include<string>
#include <learnopengl/camera.h>
#include<imgui/imgui.h>
#include<imgui/imgui_impl_glfw.h>
#include<imgui/imgui_impl_opengl3.h>
#pragma once

static  float xoffset=0;
static  float yoffset=0;
static bool firstMouse=true;
const unsigned int SCR_WIDTH = 1000;

const unsigned int SCR_HEIGHT = 800;
static float lastX=SCR_WIDTH / 2.0f;
static  float lastY = SCR_HEIGHT / 2.0f;
 extern Camera    camera ;
 void framebuffer_size_callback(GLFWwindow* window, int width, int height);
 void mouse_callback(GLFWwindow* window, double xpos, double ypos);
 void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


class UI_imgui
{
	friend class render;
	friend void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	friend void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
public:
	UI_imgui();

	void processInput(GLFWwindow* window);


	void initWindow();
	void UI_loop();
	void init();
private:


	GLFWwindow* window;

	int counter ;
	float f ;
	float light_position[3] ;
	 float env ;
	float mirror_p ;
	float mirror_s ;

	int time_my = 0;
	int display_h;
	int display_w ;
	bool show_bag ;
	bool show_light_model ;
	 bool show_grass ;
	bool show_mirror_bag ;
	bool more_more_model ;
	 bool show_depthbuffer;
	 
	 float deltaTime ;
	 float grass_pos[3] ;
	ImVec4 clear_color ;
	bool* p_open ;


};

