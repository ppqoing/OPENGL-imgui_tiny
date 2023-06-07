#include"UI.hpp"

Camera camera;
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
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
		yoffset = lastY - ypos; 
		camera.ProcessMouseMovement(xoffset, yoffset);

	}
	lastX = xpos;
	lastY = ypos;
 
 }
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	 camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
void UI_imgui::processInput(GLFWwindow* window)
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




UI_imgui::UI_imgui()
{
	display_h = 1;
	display_w = 1;
	show_bag = false;
	show_mirror_bag = false;
	counter = 0;
	f = 0.0f;
	light_position[0] = 0.2f;
	light_position[1] = 0.0f;
	light_position[2] = 2.0f;
	env = 0;
	mirror_p = 0.5f;
	mirror_s = 0.5;
	time_my = 0;
	display_h;
	display_w;
	show_bag;
	show_light_model = false;
	show_grass = false;
	show_mirror_bag;
	more_more_model = false;
	show_depthbuffer = false;
	deltaTime = 0.0f;
	grass_pos[0] = grass_pos[1] = 0;
	grass_pos[2] = 1.5;
	clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	p_open = new bool(true);
}
void UI_imgui::init()
{
	//camera = Camera(glm::vec3(0.0f, 0.0f, 5.0f));
	display_h = 1;
	display_w = 1;
	show_bag = false;
	show_mirror_bag = false;
	counter = 0;
	 f = 0.0f;
	 light_position[0] = 0.2f;
	 light_position[1] = 0.0f;
	 light_position[2] = 2.0f;
	env = 0;
	 mirror_p = 0.5f;
	 mirror_s = 0.5;
	  time_my = 0;
	 display_h;
	 display_w;
	 show_bag;
	 show_light_model = false;
	 show_grass = false;
	show_mirror_bag;
	 more_more_model = false;
	 show_depthbuffer = false;
	 deltaTime = 0.0f;
	 grass_pos[0] = grass_pos[1] = 0;
	 grass_pos[2] = 1.5;
	 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	 p_open = new bool(true);
	 xoffset = 0;
	 yoffset = 0;
	 firstMouse = true;
	 lastX = SCR_WIDTH / 2.0f;
	 lastY = SCR_HEIGHT / 2.0f;
}
void UI_imgui::initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);
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
	imgui_io.Fonts->AddFontFromFileTTF("STKAITI.TTF", 20, NULL, imgui_io.Fonts->GetGlyphRangesChineseFull());

	ImGuiStyle* style = &ImGui::GetStyle();
	style->Colors[ImGuiCol_Text] = ImColor(0, 255, 0);
	glfwSetInputMode(window, GLFW_CURSOR_NORMAL, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit;
	}

}
void UI_imgui::UI_loop()
{

	ImGuiIO io_d = ImGui::GetIO();
	io_d.DeltaTime = deltaTime;
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	if (time_my == 100)
	{
		float a = ImGui::GetIO().Framerate;
		float b = 1000.0f / ImGui::GetIO().Framerate;
		std::string title;
		title += "Application average";
		title += std::to_string(b).substr(0, std::to_string(b).find('.') + 3);
		title += "ms/frame";
		title += std::to_string(a).substr(0, std::to_string(a).find('.') + 3);
		glfwSetWindowTitle(window, (char*)title.c_str());
		time_my = 0;
	}
	else
	{
		time_my += 1;
	}


	ImGui::Begin(u8"选项", p_open, ImGuiWindowFlags_NoBackground);
	// Create a window called "Hello, world!" and append into it.
	ImVec2 window_pos(0, 0);
	ImGui::SetWindowPos(window_pos);

	ImGui::Checkbox(u8"书包显示", &show_bag);
	ImGui::SameLine();
	ImGui::Checkbox(u8"灯光模型显示", &show_light_model);


	ImGui::Checkbox(u8"镜面反射模型", &show_mirror_bag);
	ImGui::SameLine();
	ImGui::Checkbox(u8"草显示", &show_grass);

	ImGui::SliderFloat(u8"漫反射率", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
	ImGui::SliderFloat(u8"环境光", &env, 0.0f, 1.0f);
	ImGui::SliderFloat(u8"镜面反射强度", &mirror_p, 0.0f, 1.0f);
	ImGui::SliderFloat(u8"镜面反射反光度", &mirror_s, 0.0f, 1.0f);
	ImGui::ColorEdit3(u8"光照颜色", (float*)&clear_color); // Edit 3 floats representing a color
	ImGui::SliderFloat3(u8"光源位置", light_position, -5, 5);
	ImGui::SliderFloat3("grass", grass_pos, -2, 2);
	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwSwapBuffers(window);
	glfwPollEvents();


}