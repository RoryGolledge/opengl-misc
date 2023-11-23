#include <model/model.h>
#include <iostream>

auto model::model::cleanup(void) -> void {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vao);
}

auto model::from_vertices(float* vertices, int count) -> model {
    auto vao = GLuint{};
    glGenVertexArrays(1, &vao);

    auto vbo = GLuint{};
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 3 * count * sizeof(*vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return { vao, vbo, count };
}

