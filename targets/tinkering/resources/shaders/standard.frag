#version 330 core

out vec4 frag_colour;

uniform vec4 our_colour;

void main() {
    frag_colour = our_colour;
} 

