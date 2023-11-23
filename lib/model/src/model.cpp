#include <model/model.h>
#include <iostream>

auto model::model::cleanup(void) -> void {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vao);
}

auto model::from_vertices(struct vertices& vertices) -> model {
    auto vao = GLuint{};
    glGenVertexArrays(1, &vao);

    auto vbo = GLuint{};
    glGenBuffers(1, &vbo);

    auto ebo = GLuint{};
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
        GL_ARRAY_BUFFER,
        vertices.positions.size() * sizeof(GLfloat),
        vertices.positions.data(),
        GL_STATIC_DRAW
    );

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        vertices.indices.size() * sizeof(GLuint),
        vertices.indices.data(),
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(0); 

    return {
        vao, vbo, ebo,
        static_cast<int>(vertices.positions.size()),
        static_cast<int>(vertices.indices.size())
    };
}

