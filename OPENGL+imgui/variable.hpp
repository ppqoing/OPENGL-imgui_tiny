#include<glad/include/glad/glad.h>
#include<glfw/include/GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <learnopengl/camera.h>
#include<imgui/imgui.h>
#include<imgui/imgui_impl_glfw.h>
#include<imgui/imgui_impl_opengl3.h>

#include <iostream>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
namespace ui_my
{

    extern GLFWwindow* window;

    extern  unsigned int SCR_WIDTH ;

    extern  unsigned int SCR_HEIGHT ;

    extern float lastX ;

    extern float lastY;

    extern float xoffset ;

    extern float yoffset ;


    extern bool firstMouse ;

    // timing

    extern Camera camera;

    extern float deltaTime;

    extern float lastFrame;
    void chushihua();
}
void chushihua()
{
    ui_my::SCR_HEIGHT = 600;
    ui_my::SCR_WIDTH = 800;
    ui_my::lastX = ui_my::SCR_WIDTH / 2.0f;
    ui_my::lastY = ui_my::SCR_HEIGHT / 2.0f;
    ui_my::xoffset = 0;
    ui_my::yoffset = 0;
    ui_my::firstMouse = true;
    ui_my::camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
    ui_my::deltaTime = 0.0f;
    ui_my::lastFrame = 0.0f;
}