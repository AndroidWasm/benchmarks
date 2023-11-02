cmake_minimum_required(VERSION 3.18.1)

project("alon")

set(BENCHES_SRC_PATH ".")

add_compile_options(-Wno-implicit-function-declaration)
add_compile_options(-fvisibility=default)
add_compile_options(-O3)
add_compile_options(-fno-unroll-loops)

# For wasm-ld only
if (ANDROID_WASM)
  add_link_options(-Wl,--export=__main_argc_argv)
  add_link_options(-Wl,--strip-debug)
endif()

add_executable(memops.wasm
    ${BENCHES_SRC_PATH}/memops.c
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(primes.wasm
    ${BENCHES_SRC_PATH}/primes.c
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(fannkuch.wasm
    ${BENCHES_SRC_PATH}/fannkuch.c
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(conditionals.wasm
    ${BENCHES_SRC_PATH}/conditionals.c
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(copy.wasm
    ${BENCHES_SRC_PATH}/copy.cpp
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(corrections.wasm
    ${BENCHES_SRC_PATH}/corrections.c
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(corrections64.wasm
    ${BENCHES_SRC_PATH}/corrections64.c
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(fasta.wasm
    ${BENCHES_SRC_PATH}/fasta.cpp
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(ifs.wasm
    ${BENCHES_SRC_PATH}/ifs.c
    ${WASM_LIBRARY_PATH}/standalone-printf.c)

add_executable(skinning.wasm
    ${BENCHES_SRC_PATH}/skinning.cpp
    ${WASM_LIBRARY_PATH}/standalone-printf.c)
