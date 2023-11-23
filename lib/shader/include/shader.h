#ifndef SHADER_SHADER_H
#define SHADER_SHADER_H

#include <unordered_map>
#include <string>

#include <glad/glad.h>

namespace shader {
    auto load_shader(const char* path, GLenum shader_type) -> GLuint;

    struct shader_program {
        GLuint program;
        GLuint vertex_shader = 0;
        GLuint fragment_shader = 0;

        std::unordered_map<std::string, GLint> uniforms;

        shader_program() = default;
        shader_program(shader_program&) = default;

        auto load_vertex_shader(const char* path) -> shader_program&;
        auto load_fragment_shader(const char* path) -> shader_program&;

        auto create(void) -> void;
        auto use(void) -> void;

        auto create_uniform(const std::string& name) -> void;

        auto set_int_uniform(const std::string& name, int value) -> void;
        auto set_float_uniform(const std::string& name, float value) -> void;

        auto cleanup(void) -> void;
    };
}

#endif

