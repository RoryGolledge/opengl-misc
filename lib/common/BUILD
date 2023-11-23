load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "common",
    srcs = ["src/common.cpp"],
    hdrs = glob(["include/*.h"]),
    include_prefix = "common",
    strip_include_prefix = "include",
    deps = [
        "//third_party/glad",
        "//third_party/glfw",
    ],
    visibility = ["//visibility:public"],
)

