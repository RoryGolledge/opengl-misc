#include "lib/common/include/hooks.h"
#include <common/common.h>
#include <common/hooks.h>

auto main(void) -> int {
    return run_program("Tinkering");
}

auto do_render(void) -> void {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

auto do_process_input(GLFWwindow *window) -> void {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

auto framebuffer_size_callback(
    GLFWwindow* window, int width, int height
) -> void {
    (void)window;
    (void)width;
    (void)height;
}

