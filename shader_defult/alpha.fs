#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
uniform sampler2D texture1;

void main()
{
vec4 TexColor=texture(texture1,TexCoord);


    if(TexColor.a==0)
        discard;
    else
        FragColor=TexColor;
}