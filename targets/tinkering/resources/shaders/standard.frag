#version 330 core

out vec4 frag_colour;

in vec3 our_colour;

void main() {
    frag_colour = vec4(our_colour, 1.0);
} 

