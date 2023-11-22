#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include <type_traits>

#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>

namespace model {
    struct model {
    public:
        GLuint vbo;

        model(model &&) = default;

        auto from_vertices(float* vertices) -> model;
    private:
        model(GLuint vbo);
    };

    static_assert(
        !std::is_default_constructible<model>::value,
        "not default constructible"
    );
    static_assert(
        !std::is_copy_constructible<model>::value,
        "copyable"
    );
}

#endif

