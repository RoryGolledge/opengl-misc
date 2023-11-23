#ifndef SHADER_SHADER_H
#define SHADER_SHADER_H

#include <unordered_map>
#include <string>

#include <glad/glad.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace shader {
    auto load_shader(const char* path, GLenum shader_type) -> GLuint;

    struct shader_program {
        GLuint program;
        GLuint vertex_shader = 0;
        GLuint fragment_shader = 0;

        std::unordered_map<std::string, GLint> uniforms;

        shader_program() = default;
        shader_program(shader_program const&) = default;
        shader_program(shader_program&&) = default;

        auto operator=(shader_program&&) -> shader_program& = default;

        auto load_vertex_shader(const char* path) -> shader_program&;
        auto load_fragment_shader(const char* path) -> shader_program&;

        auto create(void) -> void;
        auto use(void) -> void;

        auto register_uniform(const std::string& name) -> void;

        auto set_uniform(const std::string& name, int value) -> void;
        auto set_uniform(const std::string& name, float value) -> void;
        auto set_uniform(const std::string& name, glm::vec3 value) -> void;
        auto set_uniform(const std::string& name, glm::vec4 value) -> void;

        auto cleanup(void) -> void;
    };
}

#endif

