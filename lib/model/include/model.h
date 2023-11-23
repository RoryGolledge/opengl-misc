#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include <vector>

#include <glad/glad.h>

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

    struct vertices {
        std::vector<GLfloat> positions;
        std::vector<GLuint> indices;
    };

    auto from_vertices(struct vertices& vertices) -> model;
}

#endif

