#include "lib/shader/include/shader.h"
#include <standard_program/standard_program.h>
#include <shader/shader.h>

using namespace program_template;

auto program::add_model(model::model& m) -> program& {
    models.emplace_back(m);
    return *this;
}

auto program::add_model(model::model&& m) -> program& {
    models.emplace_back(m);
    return *this;
}

auto program::add_shader_program(shader::shader_program shader_program) -> program& {
    this->shader_program = shader_program;
    return *this;
}

