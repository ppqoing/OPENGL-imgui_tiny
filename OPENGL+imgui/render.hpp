#pragma once
#include"UI.hpp"
#include<vector>
#include"skybox.hpp"
#include <learnopengl/model.h>
#include<learnopengl/shader.h>
#include"alpha.hpp"
#include"light.hpp"

class render
{
    friend class Shader;
    friend class UI_imgui;
public:
    render() ;

    void render_loop();
    void init();

private:
    std::vector<std::string> faces
    {
       "../resource/skybox/right.jpg",
       "../resource/skybox/left.jpg",
       "../resource/skybox/bottom.jpg",
       "../resource/skybox/top.jpg",
       "../resource/skybox/front.jpg",
       "../resource/skybox/back.jpg"
    };
    skybox sbox ;
   static std::vector<Shader> render_task;   
   vec3 grass_p ;    
   glm::vec3 lightColor;   
   float lastFrame;
   glm::vec3 lightPos ;   
   const unsigned int SHADOW_WIDTH=1024;
   const unsigned int	SHADOW_HEIGHT = 1024;
   Shader ourShader;
   Shader edgeColor ;
   Shader mirror ;
   Shader light_depth_map ;
   Shader skyboxShader;
   direrctLight D_L_my;
   Model  ourModel;
   vec3 translate_m[60];
   vec3 scale_m[60];
   vec3 rotate_m[60];
   alpha_img grass ;
   lightModle L_M;
   string grass_path ;




   UI_imgui my_gui;

};
