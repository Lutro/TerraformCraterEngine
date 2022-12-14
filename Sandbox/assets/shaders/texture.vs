#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 ourColor;
out vec2 TexCoord;

void main()
{
   ourColor = aColor;
   TexCoord = vec2(aTexCoord.x, aTexCoord.y);
   gl_Position = u_ViewProjection * u_Transform * vec4(aPos, 1.0);
}