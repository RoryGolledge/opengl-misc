load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "model",
    srcs = ["src/model.cpp"],
    hdrs = ["include/model.h"],
    include_prefix = "model",
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
    deps = [
        "//third_party/glad",
        "//third_party/glm",
    ]
)

