#include <cstddef>

#include <model/model.h>
#include <iostream>

auto model::model::cleanup(void) -> void {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vao);
}

auto model::from_vertices(
    std::vector<vertex>& vertices, std::vector<GLuint>& indices
) -> model {
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
        vertices.size() * sizeof(vertex),
        vertices.data(),
        GL_STATIC_DRAW
    );

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        indices.size() * sizeof(GLuint),
        indices.data(),
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, position));
    glEnableVertexAttribArray(0); 

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, colour));
    glEnableVertexAttribArray(1); 

    return {
        vao, vbo, ebo,
        static_cast<int>(vertices.size()),
        static_cast<int>(vertices.size())
    };
}

