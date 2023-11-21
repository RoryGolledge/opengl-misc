## Clangd

To let clangd understand how this project is built, a `compile_commands.json`
can be generated with:

```sh 
$ bazel run @hedron_compile_commands//:refresh_all
```

## Building

Build with:

```sh 
$ bazel build //src:project
```

This will create an executable located at `bazel-bin/src/project`

