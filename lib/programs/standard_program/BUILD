load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "standard_program",
    srcs = ["src/standard_program.cpp"],
    hdrs = ["include/standard_program.h"],
    include_prefix = "standard_program",
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],

    deps = [
        "//lib/common",
        "//lib/model",
        "//lib/shader",
    ],
)

