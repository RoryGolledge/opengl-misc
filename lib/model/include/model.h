#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include <vector>

#include <glad/glad.h>
#include <glm/vec3.hpp>

namespace model {
    struct model {
        GLuint vao;
        GLuint vbo;
        GLuint ebo;

        int n_vertices;
        int n_indices;

        model() = default;
        model(GLuint vao, GLuint vbo, GLuint ebo, int n_vertices, int n_indices):
            vao(vao), vbo(vbo), ebo(ebo),
            n_vertices(n_vertices), n_indices(n_indices) {}

        auto cleanup(void) -> void;
    };

    struct vertex {
        glm::vec3 position;
        glm::vec3 colour;
    };

    auto from_vertices(std::vector<vertex>& vertices, std::vector<GLuint>& indices) -> model;
}

#endif

