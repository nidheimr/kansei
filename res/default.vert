#version 330 core

layout (location = 0) in vec3 aloc;
layout (location = 1) in vec3 acol;

out vec3 fcol;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aloc, 1.0f);
    fcol = acol;
}
