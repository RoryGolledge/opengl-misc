#ifndef COMMON_COMMON_H
#define COMMON_COMMON_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

/*
 * Runs glad/glfw/gl boilerplate to start up and render a window.
 */ 
auto run_program(const char *program_name) -> int;

#endif

