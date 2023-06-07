#include"gui_my.hpp"
#pragma region 变量
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;
Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
unsigned int SCR_WIDTH = 800;

unsigned int SCR_HEIGHT = 600;

float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
float xoffset = 0;
float yoffset = 0;

bool window_open = false;
bool* p_open = new bool(true);
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
GLFWwindow* window;


 int counter = 0;
 float f = 0.0f;
glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
float light_position[3] = { 1.2f,1.0f,2.0f };
glm::vec3 lightPos(light_position[0], light_position[1], light_position[2]);

int time_my = 0;
int display_h = 1;
int display_w = 1;
#pragma endregion
void load_window()
{
#pragma region   //初始化
    
        // glfw: initialize and configure
          // ------------------------------
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


        // glfw window creation
        // --------------------
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            exit;
        }
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        glfwSetCursorPosCallback(window, mouse_callback);
        glfwSetScrollCallback(window, scroll_callback);

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();    (void)io;
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
       // ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");




        ImGuiIO& imgui_io = ImGui::GetIO();
        imgui_io.Fonts->AddFontFromFileTTF("STKAITI.TTF",20,NULL,imgui_io.Fonts->GetGlyphRangesChineseFull());
        
        ImGuiStyle* style = &ImGui::GetStyle();
        style->Colors[ImGuiCol_Text] = ImColor(255, 255, 100);
        
        
        
        
        
        
        
        // tell GLFW to capture our mouse
        //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetInputMode(window, GLFW_CURSOR_NORMAL, GLFW_CURSOR_DISABLED);

        // glad: load all OpenGL function pointers
        // ---------------------------------------
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            exit;
        }
#pragma endregion
        
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);


    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {

        xoffset = xpos - lastX;
        yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
        camera.ProcessMouseMovement(xoffset, yoffset);


    }
    lastX = xpos;
    lastY = ypos;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

void processInput(GLFWwindow* window)
{


    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);


    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

void render_my_gui()
{


    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
            if (time_my==100)
            {
                float a= ImGui::GetIO().Framerate;
            float b= 1000.0f / ImGui::GetIO().Framerate;
            std::string title;
            title += "Application average";
            title += std::to_string(b).substr(0,std::to_string(b).find('.')+3);
            title += "ms/frame";
            title += std::to_string(a).substr(0, std::to_string(a).find('.') + 3);
            glfwSetWindowTitle(window,(char*)title.c_str() );
            time_my = 0;
            }
            else
            {
                time_my += 1;
            }


            ImGui::Begin(u8"123abc开关",p_open,ImGuiWindowFlags_NoBackground); 
            // Create a window called "Hello, world!" and append into it.
            ImVec2 window_pos(0, 0);
            ImGui::SetWindowPos(window_pos);
            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

            ImGui::Checkbox("new window", &window_open);

            ImGui::SliderFloat(u8"漫反射率", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3(u8"光照颜色", (float*)&clear_color); // Edit 3 floats representing a color
            ImGui::SliderFloat3(u8"光源位置", light_position, 0, 10);
            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();

            ImGui::Render();
           render_my_gui();
           ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());




}
void update_loop()
{

        processInput(window);
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        lightColor = glm::vec3(clear_color.x,clear_color.y,clear_color.z);

        
        glfwGetWindowSize(window, &display_w, &display_h);
        lightPos = glm::vec3(light_position[0], light_position[1], light_position[2]);
}