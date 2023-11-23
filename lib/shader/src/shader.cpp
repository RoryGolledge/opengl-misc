#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

#include <shader/shader.h>

shader::shader_program::~shader_program() {
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    glDeleteProgram(program);
}

auto shader::load_shader(const char* path, GLenum shader_type) -> GLuint {
    if (!std::filesystem::exists(path)) {
        std::cout << "ERROR: '" << path << "' does not exist\n";
    }

    auto shader = glCreateShader(shader_type);

    auto file_stream = std::ifstream{path};
    auto stream = std::stringstream{};
    stream << file_stream.rdbuf();
    auto contents = stream.str();
    auto c_contents = contents.c_str();

    glShaderSource(shader, 1, &c_contents, NULL);
    glCompileShader(shader);

    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        std::cout << "ERROR: SHADER '" << path << "' " << "COMPILATION FAILED\n" << info_log << std::endl;
    } else {
        std::cout << "INFO: SHADER '" << path << "' " << "COMPILATION SUCCESSFUL\n";
    }

    return shader;
}

auto shader::shader_program::load_vertex_shader(
    const char* path
) -> shader_program& {
    glDeleteShader(vertex_shader);
    vertex_shader = shader::load_shader(path, GL_VERTEX_SHADER);
    return *this;
}

auto shader::shader_program::load_fragment_shader(
    const char* path
) -> shader_program& {
    glDeleteShader(fragment_shader);
    fragment_shader = shader::load_shader(path, GL_FRAGMENT_SHADER);
    return *this;
}

auto shader::shader_program::create(void) -> void {
    program = glCreateProgram();

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER LINKING FAILURE\n" << infoLog << std::endl;
    } else {
        std::cout << "INFO: SHADER LINKING SUCCESSFUL\n";
    }
}

auto shader::shader_program::use(void) -> void {
    glUseProgram(program);
}

auto shader::shader_program::create_uniform(const std::string& name) -> void {
    auto loc = glGetUniformLocation(program, name.c_str());
    if (loc == -1) {
        std::cout << "WARN: '" << name <<
            "' is not an existing uniform in the current shader program\n";
    } else {
        std::cout << "INFO: Uniform '" << name << "' set\n";
    }

    uniforms[name] = loc;
}

auto shader::shader_program::set_int_uniform(
    const std::string& name, int value
) -> void {
    glUniform1i(uniforms.at(name), value);
}

auto shader::shader_program::set_float_uniform(
    const std::string& name, float value
) -> void {
    glUniform1i(uniforms.at(name), value);
}

