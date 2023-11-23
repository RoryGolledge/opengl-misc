#include "lib/common/include/program_template.h"
#include <iostream>

#include <common/common.h>
#include <common/program_template.h>
#include <math.h>
#include <standard_program/standard_program.h>

#include <model/model.h>

namespace pt = program_template;

auto main(void) -> int {
    return run_program("Tinkering");
}

auto pt::do_setup_program(void) -> pt::program* {
    auto vertices = model::vertices{
        std::vector<GLfloat>{
            0.5f,  0.5f, 0.0f,  // top right
             0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
        },
        std::vector<GLuint>{  // note that we start from 0!
            0, 1, 3,   // first triangle
            1, 2, 3    // second triangle
        }
    };

    auto shader_program = shader::shader_program{};
    shader_program
        .load_vertex_shader("targets/tinkering/resources/shaders/standard.vert")
        .load_fragment_shader("targets/tinkering/resources/shaders/standard.frag")
        .create();

    auto program = pt::program{};
    program
        .add_model(model::from_vertices(vertices))
        .add_shader_program(std::move(shader_program));

    program.shader_program.use();

    program.shader_program.register_uniform("our_colour");

    return new struct program(std::move(program));
}

auto pt::do_shutdown_program(struct program& program) -> void {
    program.shader_program.cleanup();

    for (auto& model: program.models) {
        model.cleanup();
    }
}

auto pt::do_render(struct pt::program& program) -> void {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    auto timeValue = static_cast<float>(glfwGetTime());
    auto greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    program.shader_program.set_uniform("our_colour", glm::vec4{0.0f, greenValue, 0.0f, 1.0f});

    for (auto const& model: program.models) {
        glBindVertexArray(model.vao);
        glDrawElements(GL_TRIANGLES, model.n_indices, GL_UNSIGNED_INT, nullptr);
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

