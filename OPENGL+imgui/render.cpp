#include"render.hpp"
#include"stb_image.h"
unsigned int quadVAO = 0;
unsigned int quadVBO;
render::render()
{
    extern Camera camera;
    my_gui.init();
    my_gui.initWindow();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

    grass_path = "grass.png";
    auto grass_ph = grass_path.c_str();
    grass_p = vec3(my_gui.grass_pos[0], my_gui.grass_pos[1], my_gui.grass_pos[2]);

    stbi_set_flip_vertically_on_load(true);
    alpha_img grass(grass_path.c_str(), grass_p);

    D_L_my.color = vec3(1.0, 1.0, 1.0);


    for (size_t i = 0; i < 60; i++)
    {
        translate_m[i] = vec3(i);
        scale_m[i] = vec3(1.0);
        rotate_m[i] = vec3(6.0, 0, 0);
    }

    lightPos = vec3(my_gui.light_position[0], my_gui.light_position[1], my_gui.light_position[2]);
    faces = std::vector<std::string>{
       "../resource/skybox/right.jpg",
       "../resource/skybox/left.jpg",
       "../resource/skybox/bottom.jpg",
       "../resource/skybox/top.jpg",
       "../resource/skybox/front.jpg",
       "../resource/skybox/back.jpg"
    };
    sbox = skybox(faces);
    std::vector<Shader> render_task;
    lightColor = { 1.0f, 1.0f, 1.0f };
    ourModel = Model("backpack\\backpack.obj");

    lastFrame = 0.0f;
    lightPos;

    ourShader = Shader("1.model_loading.vs", "1.model_loading.fs");
    edgeColor = Shader("lightcube.vs", "lightcube.fs");
    mirror = Shader("../shader_defult/mirror.vs", "../shader_defult/mirror.fs");




    light_depth_map = Shader("../shader_defult/shadow_mapping_depth.vs", "../shader_defult/shadow_mapping_depth.fs");
    
    
    
    skyboxShader = Shader("../shader_defult/skybox.vs", "../shader_defult/skybox.fs");
   
    
    D_L_my;
    grass_path = "grass.png";
     grass_ph = grass_path.c_str();
    grass_p = vec3(my_gui.grass_pos[0], my_gui.grass_pos[1], my_gui.grass_pos[2]);

    ourModel = Model("backpack\\backpack.obj");
   // grass =alpha_img(grass_ph, grass_p);
    L_M = lightModle(lightPos, lightColor, 0.2f);
    L_M.init();
}

void render::init()
{
    extern Camera camera;
    lightPos = vec3(my_gui.light_position[0], my_gui.light_position[1], my_gui.light_position[2]);
    faces = std::vector<std::string>{
       "../resource/skybox/right.jpg",
       "../resource/skybox/left.jpg",
       "../resource/skybox/bottom.jpg",
       "../resource/skybox/top.jpg",
       "../resource/skybox/front.jpg",
       "../resource/skybox/back.jpg"
    };

    sbox = skybox(faces);
    sbox.init();
    std::vector<Shader> render_task;
    lightColor = { 1.0f, 1.0f, 1.0f };
    ourModel = Model("backpack\\backpack.obj");

    lastFrame = 0.0f;
    lightPos;

    ourShader = Shader("1.model_loading.vs", "1.model_loading.fs");
    edgeColor = Shader("lightcube.vs", "lightcube.fs");
    mirror = Shader("../shader_defult/mirror.vs", "../shader_defult/mirror.fs");
    


    light_depth_map = Shader("../shader_defult/shadow_mapping_depth.vs", "../shader_defult/shadow_mapping_depth.fs");
    D_L_my;
    grass_path = "grass.png";
    auto grass_ph = grass_path.c_str();
    grass_p = vec3(my_gui.grass_pos[0], my_gui.grass_pos[1], my_gui.grass_pos[2]);

    ourModel = Model("backpack\\backpack.obj");
    grass = alpha_img(grass_ph, grass_p);
    grass.init();
    L_M = lightModle(lightPos, lightColor, 0.2f);
    L_M.init();
    camera.Position.z = 5;
}
void render::render_loop()
{
    while (!glfwWindowShouldClose(my_gui.window))
    {
#pragma region 数据更新


        my_gui.processInput(my_gui.window);
        grass_p = vec3(my_gui.grass_pos[0], my_gui.grass_pos[1], my_gui.grass_pos[2]);
        float currentFrame = static_cast<float>(glfwGetTime());
        my_gui.deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        lightColor = glm::vec3(my_gui.clear_color.x, my_gui.clear_color.y, my_gui.clear_color.z);


        glfwGetWindowSize(my_gui.window, &my_gui.display_w, &my_gui.display_h);
        lightPos = glm::vec3(my_gui.light_position[0], my_gui.light_position[1], my_gui.light_position[2]);



        glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        glActiveTexture(GL_TEXTURE0);


#pragma endregion
#pragma region model渲染

        //view/projection transformations
        my_gui.display_h = (my_gui.display_h == 0 ? 1 : my_gui.display_h);
        my_gui.display_w = (my_gui.display_w == 0 ? 1 : my_gui.display_w);
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)my_gui.display_w / (float)my_gui.display_h, 0.1f, 200.0f);
        glm::mat4 view = camera.GetViewMatrix();
        
        glm::mat4 model = glm::mat4(1.0f);

        glm::vec3 light_pos_MVP(projection * view * model * glm::vec4(1.0));



        model = glm::scale(model, glm::vec3(1.1f, 1.1f, 1.1f));// it's a bit too big for our scene, so scale it down
        glm::qua<float> q = glm::qua<float>(glm::radians(vec3(0.0, 0.0, 0.0)));
        model = glm::mat4_cast(q) * model;

        //model = glm::rotate(model,glm::radians(180.0f),glm::vec3(0.0,0.0,0.5));
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene


        edgeColor.use();
        edgeColor.setMat4("model", model);
        edgeColor.setMat4("projection", projection);
        edgeColor.setMat4("view", view);
        edgeColor.setVec3("lightColor", lightColor);
        glm::mat4 lightProjection, lightView;
        glm::mat4 lightSpaceMatrix;



        if (my_gui.show_bag)
        {
            my_gui.show_mirror_bag = false;
            ourShader.use();
            ourShader.setMat4("projection", projection);
            ourShader.setMat4("view", view);
            ourShader.setVec3("lightColor", lightColor);
            ourShader.setVec3("lightPos", lightPos);
            ourShader.setVec3("MVP", light_pos_MVP);
            ourShader.setFloat("ambientStrength", my_gui.f);
            ourShader.setFloat("envirmentcolor", my_gui.env);
            ourShader.setFloat("mirror_p", my_gui.mirror_p);
            ourShader.setInt("morror_s", my_gui.mirror_s);
            ourShader.setVec3("viewpos", camera.Position);
            ourShader.setVec3("d_l[0].direction", D_L_my.direction);
            ourShader.setVec3("d_l[0].color", D_L_my.color);
            ourShader.setFloat("d_l[0].diffuse", D_L_my.diffuse);
            ourShader.setFloat("d_l[0].specular_space", D_L_my.specular_space);
            ourShader.setFloat("d_l[0].specular_power", D_L_my.specular_power);

            model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
            model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
            ourShader.setMat4("model", model);




            float near_plane = 1.0f, far_plane = 7.5f;
            //lightProjection = glm::perspective(glm::radians(45.0f), (GLfloat)SHADOW_WIDTH / (GLfloat)SHADOW_HEIGHT, near_plane, far_plane); // note that if you use a perspective projection matrix you'll have to change the light position as the current light position isn't enough to reflect the whole scene
            lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
            lightView = glm::lookAt(lightPos, glm::vec3(.0f), glm::vec3(0.0, 1.0, 0.0));
            lightSpaceMatrix = lightProjection * lightView;
            // render scene from light's point of view
            light_depth_map.use();
            light_depth_map.setMat4("lightSpaceMatrix", lightSpaceMatrix);

            ourModel.Draw(light_depth_map);
        }

        ourShader.use();
        ourShader.setInt("shadowMap", 1);
        if (my_gui.show_bag)
        {

            ourShader.setMat4("lightSpaceMatrix", lightSpaceMatrix);
            ourModel.Draw(ourShader);
        }
        if (my_gui.show_mirror_bag)
        {
            my_gui.show_bag = false;
            mirror.use();
            mirror.setMat4("model", model);
            mirror.setMat4("projection", projection);
            mirror.setMat4("view", view);
            mirror.setInt("skybox", 0);
            mirror.setVec3("cameraPos", camera.Position);
            ourModel.Draw(mirror);
        }


        if (my_gui.show_grass)
        {
            grass.set_position(grass_p);
            grass.render(view, projection);
            
        }

        if (my_gui.show_light_model)
        {
            L_M.render(projection, view, lightColor, lightPos);
        }

        view = glm::mat4(glm::mat3(camera.GetViewMatrix()));
        sbox.render(projection, view);


#pragma endregion
        my_gui.UI_loop();




        // scr_buff.f_buffer_end();



    }
    //git test
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(my_gui.window);
    glfwTerminate();
}
