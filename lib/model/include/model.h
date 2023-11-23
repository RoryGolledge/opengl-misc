#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include <glad/glad.h>

namespace model {
    struct model {
        GLuint vao;
        GLuint vbo;
        int n_vertices;

        model() = default;
        model(GLuint vao, GLuint vbo, int n_vertices):
            vao(vao), vbo(vbo), n_vertices(n_vertices) {}

        auto cleanup(void) -> void;
    };

    auto from_vertices(float* vertices, int count) -> model;

}

#endif

