load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "tinkering",
    srcs = ["main.cpp"],
    copts = [
        "-Wall",
        "-Wextra",
        "-Werror",
        "-pedantic-errors",
        "-Wconversion",
        "-Wsign-conversion",
        "-Wdouble-promotion",
        "-Wcast-align",
        "-Wformat=2",
        "-Wuninitialized",
        "-Wnull-dereference",
        "-Wnon-virtual-dtor",
        "-Woverloaded-virtual",
        "-Wdeprecated-copy-dtor",
        "-Wold-style-cast",
        "-Wzero-as-null-pointer-constant",
        "-Wno-self-assign-overloaded",
        "-Wno-self-move",
        "-Wsuggest-override",
        "-fstack-protector-strong",
    ],
    linkopts = ["-ldl", "-lX11", "-lpthread"],
    deps = [
        "//lib/common",
        "//lib/model",
    ],
)

