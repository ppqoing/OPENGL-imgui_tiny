//#pragma once
#include<glad/include/glad/glad.h>
#include<glfw/include/GLFW/glfw3.h>
#include <iostream>
#include<string>
#include<imgui/imgui.h>
#include<imgui/imgui_impl_glfw.h>
#include<imgui/imgui_impl_opengl3.h>

#include <learnopengl/camera.h>



#pragma region 变量
extern bool firstMouse ;

// timing
extern float deltaTime ;
extern float lastFrame;
extern Camera camera ;
extern unsigned int SCR_WIDTH ;

extern unsigned int SCR_HEIGHT;

extern float lastX;
extern float lastY;
extern float xoffset;
extern  float yoffset;

extern  bool window_open;
extern  bool* p_open;
extern  ImVec4 clear_color;
extern GLFWwindow* window;


extern int counter;
extern  float f;
extern  glm::vec3 lightColor;
extern  float light_position[3];
extern  glm::vec3 lightPos;
extern int display_w, display_h;
extern  int time_my;



#pragma endregion
#pragma region 函数 声明
void render_my_gui();
void load_window();
    void processInput(GLFWwindow* window);
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void update_loop();

void load_date_glenable();
void loop_model();
void loop_end();
