#ifndef COMMON_HOOKS_H
#define COMMON_HOOKS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

/**
 * To be called once per frame, to actually render said frame.
 */
auto do_render(void) -> void;

/**
 * To be called once per frame, before rendering is performed.
 */
auto do_process_input(GLFWwindow *window) -> void;

/*
 * To be called upon user resizing the window.
 *
 * Handling of framebuffer resizing on window resizing is already done.
 */
auto framebuffer_size_callback(
    GLFWwindow* window, int width, int height
) -> void;

#endif

