#include"light.hpp"
lightModle::lightModle()
{
	lightVAO = 0;
	VBO = 0;
	position = vec3(0,0,0);
	color = vec3(0,0,0);
	size = 1.0f;
}
direrctLight::direrctLight()
{
   
	ID = -1;
	direction = vec3(1.0);
	color = vec3(1.0);
	diffuse = 0.5f;
	specular_power = 0.5f;
	specular_space = 0.5f;

}
pointLight::pointLight()
{
  
	ID = -1;
	k0 = 1.0f;
	k1 = 0.09f;
	k2 = 0.032f;
	color = vec3(1.0);
	diffuse = 0.5f;
	position = vec3(0.0);
	specular_power = 0.5f;
	specular_space = 0.5f;
}
spotLight::spotLight()
{
	ID = -1;
	direction = vec3(1.0);
	color = vec3(1.0);
	position = vec3(0.0);
	directDot = 0.5f;

}
lightModle::lightModle(vec3 pos, vec3 col, float s)
{
    lightVAO = 0;
    VBO = 0;
	position = pos;
	color = col;
	size = s;

}
void lightModle::init()
{
	bind_glad();
	lightCube = Shader("lightcube.vs", "lightcube.fs");
}
void lightModle::bind_glad()
{
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);

    // we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
void lightModle::render(mat4 projection,mat4 view,vec3 col,vec3 pos)
{
    color = col;
    position = pos;
    lightCube.use();
    lightCube.setMat4("projection", projection);
    lightCube.setMat4("view", view);
    mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::scale(model, glm::vec3(size)); // a smaller cube
    lightCube.setMat4("model", model);
    lightCube.setVec3("lightColor", color);

    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}