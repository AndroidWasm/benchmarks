cmake_minimum_required(VERSION 3.18.1)

project("spec2000")

set(INT_BENCHMARKS_ROOT "benchspec/CINT2000")

set(SPEC_164_GZIP_PATH "${INT_BENCHMARKS_ROOT}/164.gzip/src")

add_compile_options(-Wno-implicit-function-declaration)
add_compile_options(-Wno-format-security)
add_compile_options(-Wno-implicit-int)
add_compile_options(-fvisibility=default)
add_compile_options(-O3)

# For wasm-ld only
if (ANDROID_WASM)
  add_link_options(-Wl,--export=__main_argc_argv)
  add_link_options(-Wl,--strip-debug)
  #  add_compile_options(-fno-unroll-loops)
endif()

add_executable(164.gzip
    ${SPEC_164_GZIP_PATH}/bits.c
    ${SPEC_164_GZIP_PATH}/deflate.c
    ${SPEC_164_GZIP_PATH}/gzip.c
    ${SPEC_164_GZIP_PATH}/getopt.c
    ${SPEC_164_GZIP_PATH}/inflate.c
    ${SPEC_164_GZIP_PATH}/lzw.c
    ${SPEC_164_GZIP_PATH}/spec.c
    ${SPEC_164_GZIP_PATH}/trees.c
    ${SPEC_164_GZIP_PATH}/unlzh.c
    ${SPEC_164_GZIP_PATH}/unlzw.c
    ${SPEC_164_GZIP_PATH}/unpack.c
    ${SPEC_164_GZIP_PATH}/unzip.c
    ${SPEC_164_GZIP_PATH}/util.c
    ${SPEC_164_GZIP_PATH}/zip.c)

if (ANDROID_WASM)
  target_sources(164.gzip PRIVATE
      ${WASM_LIBRARY_PATH}/open-proxy.c
      ${WASM_LIBRARY_PATH}/standalone-printf.c)
endif()
