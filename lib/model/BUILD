load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "model",
    srcs = glob(["src/*.c"]),
    hdrs = glob(["include/*.h"]),
    include_prefix = "model",
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

