#version 330 core
out vec4 FragColor;


in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
} fs_in;

struct Dirlight
{
vec3 direction;
vec3 color;
float diffuse;
float specular_power;
float specular_space;
};
struct Pointlight
{
vec3 position;
vec3 color;
float diffuse;
float specular_power;
float specular_space;
float k1;
float k2;
};


uniform Dirlight d_l[5];
uniform Pointlight p_l[5];
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform sampler2D texture_diffuse1;
uniform float ambientStrength;
uniform float envirmentcolor;
uniform float mirror_p;
uniform float mirror_s;
uniform vec3 viewpos;
uniform sampler2D shadowMap;

vec4 directColor(Dirlight D);
vec4 pointLight(Pointlight P);


float ShadowCalculation(vec4 FragPosLightSpace)
{
    // perform perspective divide
    vec3 projCoords = FragPosLightSpace.xyz / FragPosLightSpace.w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range FragPosLight as coords)
    float closestDepth = texture(shadowMap, projCoords.xy).r; 
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // calculate bias (based on depth map resolution and slope)
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);
    // check whether current frag pos is in shadow
    // float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
    // PCF
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }
    shadow /= 9.0;
    
    // keep the shadow at 0.0 when outside the far_plane region of the light's frustum.
    if(projCoords.z > 1.0)
        shadow = 0.0;
        
    return shadow;
}




void main()
{    
    vec3 ambient = ambientStrength * lightColor;
    // 漫反射
    vec3 norm = normalize(fs_in.Normal);
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    vec4 diffcol =vec4( (ambient + diffuse),1.0) * texture(texture_diffuse1, fs_in.TexCoords);
    //环境光
    vec4 encol=envirmentcolor* texture(texture_diffuse1, fs_in.TexCoords);  
    //镜面光
    vec3 viewdir=normalize(viewpos-fs_in.FragPos);
    vec3 arr=(lightDir+viewdir)*0.5;
    float spec=dot(arr,fs_in.Normal);
    //float spec=pow(max(dot(arr,Normal),0),mirror_s);
    float spec_s=spec*step(mirror_s,spec);
    vec4 specular=mirror_p*spec_s*texture(texture_diffuse1, fs_in.TexCoords);

     float shadow = ShadowCalculation(fs_in.FragPosLightSpace); 

   // FragColor =directColor(d_l[0]);
  
  FragColor =encol+shadow*(diffcol+specular);
}
vec4 directColor(Dirlight D)
{
   float diff=max(dot(normalize(fs_in.Normal),normalize(D.direction)),0);
   vec4 diffcol=vec4(diff*D.color,1.0)*texture(texture_diffuse1, fs_in.TexCoords);
   return diffcol;
}