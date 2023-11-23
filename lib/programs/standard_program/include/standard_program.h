#ifndef PROGRAMS_STANDARD_PROGRAM_STANDARD_PROGRAM_H
#define PROGRAMS_STANDARD_PROGRAM_STANDARD_PROGRAM_H

#include <vector>

#include <common/program_template.h>

#include <model/model.h>
#include <shader/shader.h>

namespace program_template {
    struct program {
        std::vector<model::model> models;
        shader::shader_program shader_program;
        
        program() = default;
        program(program&&) = default;

        auto add_model(model::model&) -> program&;
        auto add_model(model::model&&) -> program&;

        auto add_shader_program(shader::shader_program) -> program&;
    };
}

#endif

