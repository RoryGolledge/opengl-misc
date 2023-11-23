#include <iostream>

#include <common/common.h>
#include <common/program_template.h>
#include <standard_program/standard_program.h>

#include <model/model.h>

namespace pt = program_template;

auto main(void) -> int {
    return run_program("Tinkering");
}

auto pt::do_setup_program(void) -> pt::program* {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    auto shader_program = shader::shader_program{};
    shader_program
        .load_vertex_shader("targets/tinkering/resources/shaders/standard.vert")
        .load_fragment_shader("targets/tinkering/resources/shaders/standard.frag")
        .create();

    auto program = pt::program{};
    program
        .add_model(model::from_vertices(vertices, 3))
        .add_shader_program(shader_program);

    program.shader_program.use();

    return new struct program(program);
}

auto pt::do_render(struct pt::program& program) -> void {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.shader_program.use();
    for (auto const& model: program.models) {
        glBindVertexArray(model.vao);
        glDrawArrays(GL_TRIANGLES, 0, model.n_vertices);
    }
}

auto pt::do_process_input(GLFWwindow *window) -> void {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

auto pt::framebuffer_size_callback(
    GLFWwindow* window, int width, int height
) -> void {
    (void)window;
    (void)width;
    (void)height;
}

