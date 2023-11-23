load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "shader",
    srcs = ["src/shader.cpp"],
    hdrs = ["include/shader.h"],
    include_prefix = "shader",
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
    deps = [
        "//third_party/glad",
    ]
)

