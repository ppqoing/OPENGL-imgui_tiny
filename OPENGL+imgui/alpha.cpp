#include"alpha.hpp"
#include"stb_image.h"




glm::vec3 translations[1000];
alpha_img::alpha_img()
{
    transparentVAO = -1;
    transparentVBO = -1;
    textureID = 2;
    size = 1.0f;
    position = vec3(0, 0, 0);

}
void alpha_img::init()
{
    shader = Shader("../shader_defult/alpha.vs", "../shader_defult/alpha.fs");


    int index = 0;

    for (int y = 10; y > 0; y --)
    {
        for (int x = 10; x >0; x --)
        {
            for (int z = 10; z >0; z--)
            {
            glm::vec3 translation;
            translation.x = (float)x / 10.0f;
            translation.y = (float)y / 10.0f;
            translation.z = (float)z / 10.0f;
            translations[index++] = translation;
            }
           
        }
    }

}
alpha_img::alpha_img(const char * path,vec3 pos)
{
    transparentVAO = 0;
    transparentVBO = 0;
    textureID = 2;
    glGenTextures(2, &textureID);
    
    position = pos;
    size = 1.0f;
    
    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        stbi_image_free(data);
    }

    load();

}

void alpha_img::load()
{
    glGenVertexArrays(2, &transparentVAO);
    glGenBuffers(2, &transparentVBO);
    glBindVertexArray(transparentVAO);
    glBindBuffer(GL_ARRAY_BUFFER, transparentVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(transparentVertices), transparentVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));


    glBindVertexArray(0);




}
void alpha_img::set_size(float s)
{
    size = s;
}
void alpha_img::set_position(vec3 p)
{
    position = p;
}
void alpha_img::render(mat4 v,mat4 p)
{
    shader.use();
    shader.setInt("texture1", 0);
    shader.setMat4("projection", p);
    shader.setMat4("view", v);
    mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::scale(model, glm::vec3(size)); // a smaller cube
    shader.setMat4("model", model);





    glBindVertexArray(transparentVAO);
    glBindTexture(GL_TEXTURE_2D, textureID);
   
    glDrawArrays(GL_TRIANGLES, 0, 6);

}





