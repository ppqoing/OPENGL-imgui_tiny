//#pragma region 头文件
//#include<glad/include/glad/glad.h>
//#include<glfw/include/GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <learnopengl/filesystem.h>
//#include <learnopengl/shader_m.h>
//#include <learnopengl/camera.h>
//#include <learnopengl/model.h>
//
//#include<vector>
//
//#include <iostream>
//#include<string>
//
//#include<imgui/imgui.h>
//#include<imgui/imgui_impl_glfw.h>
//#include<imgui/imgui_impl_opengl3.h>
//
//#include"light.hpp"
//#include"alpha.hpp"
////#include"framebuffer_my.hpp"
//#include"skybox.hpp"
//
//#if defined(IMGUI_IMPL_OPENGL_ES2)
//#include <GLES2/gl2.h>
//#endif
//#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
//#pragma comment(lib, "legacy_stdio_definitions")
//#endif
//#pragma endregion
//#pragma region 函数声明
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);
//void renderQuad();
//#pragma endregion
//#pragma region 变量
//unsigned int lightVAO;
//unsigned int VBO;
//
//bool firstMouse = true;
//
//// timing
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
//const unsigned int SCR_WIDTH = 1000;
//
//const unsigned int SCR_HEIGHT = 800;
//
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//float xoffset = 0;
//float yoffset = 0;
//
//bool window_open = false;
//bool* p_open = new bool(true);
//ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//GLFWwindow* window;
//
////imgui
//int counter = 0;
//float f = 0.0f;
//glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
//float light_position[3] = { 0.2f,0.0f,2.0f };
//glm::vec3 lightPos(light_position[0], light_position[1], light_position[2]);
//float env = 0;
// float mirror_p=0.5f;
//float mirror_s=0.5;
//
//int time_my = 0;
//int display_h = 1;
//int display_w = 1;
//bool show_bag = false;
//bool show_light_model = false;
//bool show_grass = false;
//bool show_mirror_bag = false;
//bool more_more_model = false;
//bool show_depthbuffer = false;
//
//#pragma endregion
//int main()
//{
//#pragma region 初始化
//    // glfw: initialize and configure
//      // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//    glfwWindowHint(GLFW_SAMPLES, 4);
//    // glfw window creation
//    // --------------------
//    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        exit;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSwapInterval(1);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // Setup Dear ImGui context
//    IMGUI_CHECKVERSION();
//    ImGui::CreateContext();
//    ImGuiIO& io = ImGui::GetIO();    (void)io;
//    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
//    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
//
//    // Setup Dear ImGui style
//    ImGui::StyleColorsDark();
//    // ImGui::StyleColorsLight();
//
//     // Setup Platform/Renderer backends
//    ImGui_ImplGlfw_InitForOpenGL(window, true);
//    ImGui_ImplOpenGL3_Init("#version 330");
//
//
//
//
//    ImGuiIO& imgui_io = ImGui::GetIO();
//    imgui_io.Fonts->AddFontFromFileTTF("STKAITI.TTF", 20, NULL, imgui_io.Fonts->GetGlyphRangesChineseFull());
//
//    ImGuiStyle* style = &ImGui::GetStyle();
//    style->Colors[ImGuiCol_Text] = ImColor(255, 255, 100);
//
//
//
//
//
//
//
//    // tell GLFW to capture our mouse
//    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwSetInputMode(window, GLFW_CURSOR_NORMAL, GLFW_CURSOR_DISABLED);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        exit;
//    }
//
//    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
//    stbi_set_flip_vertically_on_load(true);
//#pragma endregion
//
//
//
//
//#pragma region //加载，预设  
//
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_MULTISAMPLE);
//   // glEnable(GL_FRAMEBUFFER_SRGB);
//   // glEnable(GL_MULTISAMPLE);
//    //glEnable(GL_STENCIL_TEST);
//    //glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
//    //glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
//    Shader ourShader("1.model_loading.vs", "1.model_loading.fs");
//    Shader edgeColor("lightcube.vs", "lightcube.fs");
//    Shader mirror("../shader_defult/mirror.vs", "../shader_defult/mirror.fs");
//    Shader debug_quad("../shader_defult/debug_quad.vs", "../shader_defult/debug_quad.fs");
//    Shader light_depth_map("../shader_defult/shadow_mapping_depth.vs", "../shader_defult/shadow_mapping_depth.fs");
//    
//    
//    
//    
//    vector<std::string> faces
//    {
//       "../resource/skybox/right.jpg",
//       "../resource/skybox/left.jpg",       
//       "../resource/skybox/bottom.jpg",
//       "../resource/skybox/top.jpg",
//       "../resource/skybox/front.jpg",
//       "../resource/skybox/back.jpg"
//    };
//    skybox sbox = skybox(faces);
//
//    float grass_pos[3] = {0,0,0};
//    vec3 grass_p = vec3(grass_pos[0],grass_pos[1],grass_pos[2]);
//    string grass_path = "grass.png";
//    alpha_img grass(grass_path.c_str(), grass_p);
//    lightModle L_M(lightPos, lightColor, 0.2f);
//    L_M.bind_glad();
//    lightModle L_(vec3(1.0,1.0,2.0), lightColor, 0.2f);
//    L_.bind_glad();
//    Model  ourModel = Model("backpack\\backpack.obj");
//    direrctLight D_L_my;
//    D_L_my.color = vec3(1.0, 1.0, 1.0);
//
//   // f_buffer_scr scr_buff(SCR_WIDTH, SCR_HEIGHT);
//    
//    vec3 translate_m[60];
//    vec3 scale_m[60];
//    vec3 rotate_m[60];
//    for (size_t i = 0; i < 60; i++)
//    {
//        translate_m[i] = vec3(i);
//        scale_m[i] = vec3(1.0);
//        rotate_m[i] = vec3(6.0, 0, 0);
//    }
//    
//    const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
//    unsigned int depthMapFBO;
//    glGenFramebuffers(1, &depthMapFBO);
//    // create depth texture
//    unsigned int depthMap;
//    glGenTextures(1, &depthMap);
//    glBindTexture(GL_TEXTURE_2D, depthMap);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,SHADOW_WIDTH,SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // attach depth texture as FBO's depth buffer
//    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
//    glDrawBuffer(GL_NONE);
//    glReadBuffer(GL_NONE);
//    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//    debug_quad.use();
//    debug_quad.setInt("depthMap", 0);
//
//
//#pragma endregion 
//    while (!glfwWindowShouldClose(window))
//    {
//#pragma region 数据更新
//        
//        processInput(window);
//        grass_p = vec3(grass_pos[0], grass_pos[1], grass_pos[2]);
//        float currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//        lightColor = glm::vec3(clear_color.x, clear_color.y, clear_color.z);
//
//
//        glfwGetWindowSize(window, &display_w, &display_h);
//        lightPos = glm::vec3(light_position[0], light_position[1], light_position[2]);
//   //scr_buff.f_buffer_begin();
//
//
//  
//  // renderQuad();
//
//
//glViewport(0,0,SHADOW_WIDTH,SHADOW_HEIGHT);
//   glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//
//     glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
//     glActiveTexture(GL_TEXTURE0);
//
//
//#pragma endregion
//#pragma region model渲染
//        
//    
//        //view/projection transformations
//        display_h = (display_h == 0 ? 1 : display_h);
//        display_w = (display_w == 0 ? 1 : display_w);
//        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)display_w / (float)display_h, 0.1f, 200.0f);
//        glm::mat4 view = camera.GetViewMatrix();
//
//        glm::mat4 model = glm::mat4(1.0f);
//
//        glm::vec3 light_pos_MVP(projection* view* model* glm::vec4(1.0));
//
//
//       
//        model = glm::scale(model, glm::vec3(1.1f, 1.1f, 1.1f));// it's a bit too big for our scene, so scale it down
//        glm::qua<float> q = glm::qua<float>(glm::radians(vec3(0.0, 0.0, 90.0)));
//        model = glm::mat4_cast(q) * model;
//        
//        //model = glm::rotate(model,glm::radians(180.0f),glm::vec3(0.0,0.0,0.5));
//        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
//       
//        
//        edgeColor.use();
//        edgeColor.setMat4("model", model);
//        edgeColor.setMat4("projection", projection);
//        edgeColor.setMat4("view", view);
//        edgeColor.setVec3("lightColor", lightColor);
// glm::mat4 lightProjection, lightView;
//        glm::mat4 lightSpaceMatrix;
//
//
//
//        if (show_bag)
//        {
//            show_mirror_bag = false;
//            ourShader.use();
//        ourShader.setMat4("projection", projection);
//        ourShader.setMat4("view", view);
//        ourShader.setVec3("lightColor", lightColor);
//        ourShader.setVec3("lightPos", lightPos);
//        ourShader.setVec3("MVP", light_pos_MVP);
//        ourShader.setFloat("ambientStrength", f);
//        ourShader.setFloat("envirmentcolor", env);
//        ourShader.setFloat("mirror_p", mirror_p);
//        ourShader.setInt("morror_s", mirror_s);
//        ourShader.setVec3("viewpos", camera.Position);
//        ourShader.setVec3("d_l[0].direction", D_L_my.direction);
//        ourShader.setVec3("d_l[0].color", D_L_my.color);
//        ourShader.setFloat("d_l[0].diffuse", D_L_my.diffuse);
//        ourShader.setFloat("d_l[0].specular_space", D_L_my.specular_space);
//        ourShader.setFloat("d_l[0].specular_power", D_L_my.specular_power);
//
//        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
//        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
//        ourShader.setMat4("model", model);
//
//
//
//
//       
//        float near_plane = 1.0f, far_plane = 7.5f;
//        //lightProjection = glm::perspective(glm::radians(45.0f), (GLfloat)SHADOW_WIDTH / (GLfloat)SHADOW_HEIGHT, near_plane, far_plane); // note that if you use a perspective projection matrix you'll have to change the light position as the current light position isn't enough to reflect the whole scene
//        lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
//        lightView = glm::lookAt(lightPos, glm::vec3(.0f), glm::vec3(0.0, 1.0, 0.0));
//        lightSpaceMatrix = lightProjection * lightView;
//        // render scene from light's point of view
//        light_depth_map.use();
//        light_depth_map.setMat4("lightSpaceMatrix", lightSpaceMatrix);
//
//      ourModel.Draw(light_depth_map);
//        }
//
//
//
//        glBindFramebuffer(GL_FRAMEBUFFER, 0);
//        glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, depthMap);
//      ourShader.use();
//        ourShader.setInt("shadowMap", 1);
//        if (show_bag)
//        {
//      
//            ourShader.setMat4("lightSpaceMatrix", lightSpaceMatrix);
//            ourModel.Draw(ourShader);
//        }
//
//
//        if (more_more_model)
//        {
//            ourModel.DrawArray(ourShader, 60, translate_m, scale_m, rotate_m,model);
//
//        }
//
//
//       
//        
//
//       
//        if (show_mirror_bag)
//        {
//            show_bag = false;
//            mirror.use();
//            mirror.setMat4("model", model);
//            mirror.setMat4("projection", projection);
//            mirror.setMat4("view", view);
//            mirror.setInt("skybox",0);
//            mirror.setVec3("cameraPos", camera.Position);
//            ourModel.Draw(mirror);
//        }
//        
//        if (show_grass)
//        {
//grass.render(view, projection);
//         grass.set_position(grass_p);
//        }
//         
//        if (show_light_model)
//        {
//        L_M.render(projection, view, lightColor, lightPos);
//
//        }
//       
//        
//view = glm::mat4(glm::mat3(camera.GetViewMatrix()));
//        sbox.render(projection, view);
//       
//
//        
//
//
//
//#pragma endregion
//        
//
//        if (show_depthbuffer)
//        {    
//            glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//
//   // reset viewport
//   glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//   // render Depth map to quad for visual debugging
//   // ---------------------------------------------
//   debug_quad.use();
//   debug_quad.setFloat("near_plane", 1.0f);
//   debug_quad.setFloat("far_plane", 7.5f);
//   glActiveTexture(GL_TEXTURE0);
//   glBindTexture(GL_TEXTURE_2D, depthMap);
//   renderQuad();
//
//
//
//        }
//
//
//
//       // scr_buff.f_buffer_end();
//
//#pragma region imgui
//        ImGuiIO io_d = ImGui::GetIO();
//        io_d.DeltaTime = deltaTime;
//        ImGui_ImplOpenGL3_NewFrame();
//        ImGui_ImplGlfw_NewFrame();
//        ImGui::NewFrame();
//        if (time_my == 100)
//        {
//            float a = ImGui::GetIO().Framerate;
//            float b = 1000.0f / ImGui::GetIO().Framerate;
//            std::string title;
//            title += "Application average";
//            title += std::to_string(b).substr(0, std::to_string(b).find('.') + 3);
//            title += "ms/frame";
//            title += std::to_string(a).substr(0, std::to_string(a).find('.') + 3);
//            glfwSetWindowTitle(window, (char*)title.c_str());
//            time_my = 0;
//        }
//        else
//        {
//            time_my += 1;
//        }
//
//
//        ImGui::Begin(u8"123abc开关", p_open, ImGuiWindowFlags_NoBackground);
//        // Create a window called "Hello, world!" and append into it.
//        ImVec2 window_pos(0, 0);
//        ImGui::SetWindowPos(window_pos);
//
//        ImGui::Checkbox(u8"书包显示",&show_bag);
//        ImGui::SameLine();
//        ImGui::Checkbox(u8"灯光模型显示", &show_light_model);
//        ImGui::SameLine();
//        ImGui::Checkbox(u8"草显示", &show_grass);
//
//        ImGui::Checkbox(u8"镜面反射模型",&show_mirror_bag);
//        ImGui::SameLine();
//        ImGui::Checkbox(u8"多重影分身", &more_more_model);
//        ImGui::SameLine();
//        ImGui::Checkbox(u8"深度缓冲", &show_depthbuffer);
//
//        ImGui::SliderFloat(u8"漫反射率", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
//        ImGui::SliderFloat(u8"环境光", &env, 0.0f, 1.0f);
//        ImGui::SliderFloat(u8"镜面反射强度", &mirror_p, 0.0f, 1.0f);
//        ImGui::SliderFloat(u8"镜面反射反光度", &mirror_s, 0.0f, 1.0f);
//        ImGui::ColorEdit3(u8"光照颜色", (float*)&clear_color); // Edit 3 floats representing a color
//        ImGui::SliderFloat3(u8"光源位置", light_position, -5, 5);
//        ImGui::SliderFloat3("grass",grass_pos, -2, 2);
//        ImGui::End();
//
//        ImGui::Render();
//        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//        // glfw: terminate, clearing all previously allocated GLFW resources.
//        // ------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//#pragma endregion
//        
//
//    }
//    //git test
//    ImGui_ImplOpenGL3_Shutdown();
//    ImGui_ImplGlfw_Shutdown();
//    ImGui::DestroyContext();
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    return 0;
//    
//}
//#pragma region 回调函数
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.ProcessKeyboard(LEFT, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.ProcessKeyboard(RIGHT, deltaTime);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
//{
//    float xpos = static_cast<float>(xposIn);
//    float ypos = static_cast<float>(yposIn);
//
//
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
//    {
//
//        xoffset = xpos - lastX;
//        yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//        camera.ProcessMouseMovement(xoffset, yoffset);
//
//
//    }
//    lastX = xpos;
//    lastY = ypos;
//}
//
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//// ----------------------------------------------------------------------
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}
//#pragma endregion
//unsigned int quadVAO = 0;
//unsigned int quadVBO;
//void renderQuad()
//{
//    if (quadVAO == 0)
//    {
//        float quadVertices[] = {
//            // positions        // texture Coords
//            -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
//            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
//             1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
//             1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
//        };
//        // setup plane VAO
//        glGenVertexArrays(1, &quadVAO);
//        glGenBuffers(1, &quadVBO);
//        glBindVertexArray(quadVAO);
//        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//        glEnableVertexAttribArray(1);
//        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    }
//    glBindVertexArray(quadVAO);
//    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//    glBindVertexArray(0);
//}
#include"render.hpp"
int main ()
{
	
	
	render one;
	one.init();
	one.render_loop();
	return 0;
}