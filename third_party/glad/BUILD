load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "glad",
    srcs = ["src/glad.c"],
    hdrs = ["include/glad.h"],
    include_prefix = "glad",
    strip_include_prefix = "include",
    deps = [
        "//third_party/KHR",
    ],
    visibility = ["//visibility:public"],
)

