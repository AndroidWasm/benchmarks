# How to build spec2000

1. Get spec2000 sources from somewhere
1. create a symlink in this repository root

    ```
    ln -s <path-to-downloaded-spec2000-dir>/benchspec
    ```

1. build benchmarks using --toolchain from [wasm_ndk repo](https://github.com/AndroidWasm/wasm_ndk)

    ```
    mkdir build_wasm
    cd build_wasm
    cmake --toolchain $(wasm_ndk_root)/cmake/toolchain/android_wasm.toolchain.cmake ..
    cmake --build .
    ```

1. build benchmarks for native platform using android toolchain from NDK

    ```
    mkdir build_native
    cd build_native
    cmake --toolchain $ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a ..
    cmake --build .
    ```
