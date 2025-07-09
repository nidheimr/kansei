#version 330 core

out vec4 FragColor;
in vec3 fcol;

void main()
{
    FragColor = vec4(fcol, 1.0f);
} 
