cmake_minimum_required(VERSION 3.18.1)

project("spec2000")

set(INT_BENCHMARKS_ROOT "benchspec/CINT2000")

set(SPEC_164_GZIP_PATH "${INT_BENCHMARKS_ROOT}/164.gzip/src")

set(SPEC_175_VPR_PATH "${INT_BENCHMARKS_ROOT}/175.vpr/src")

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

add_executable(175.vpr
    ${SPEC_175_VPR_PATH}/check_route.c
    ${SPEC_175_VPR_PATH}/check_rr_graph.c
    ${SPEC_175_VPR_PATH}/draw.c
    ${SPEC_175_VPR_PATH}/graphics.c
    ${SPEC_175_VPR_PATH}/hash.c
    ${SPEC_175_VPR_PATH}/main.c
    ${SPEC_175_VPR_PATH}/place.c
    ${SPEC_175_VPR_PATH}/read_arch.c
    ${SPEC_175_VPR_PATH}/read_netlist.c
    ${SPEC_175_VPR_PATH}/read_place.c
    ${SPEC_175_VPR_PATH}/route.c
    ${SPEC_175_VPR_PATH}/rr_graph2.c
    ${SPEC_175_VPR_PATH}/rr_graph_area.c
    ${SPEC_175_VPR_PATH}/rr_graph.c
    ${SPEC_175_VPR_PATH}/rr_graph_sbox.c
    ${SPEC_175_VPR_PATH}/rr_graph_timing_params.c
    ${SPEC_175_VPR_PATH}/rr_graph_util.c
    ${SPEC_175_VPR_PATH}/segment_stats.c
    ${SPEC_175_VPR_PATH}/stats.c
    ${SPEC_175_VPR_PATH}/util.c)

target_compile_options(175.vpr PRIVATE
    -DSPEC_CPU2000)

target_link_libraries(175.vpr PRIVATE
   m)
