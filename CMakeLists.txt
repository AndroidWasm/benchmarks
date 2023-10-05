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

set(SPEC_176_GCC_PATH "${INT_BENCHMARKS_ROOT}/176.gcc/src")

add_executable(176.gcc
    ${SPEC_176_GCC_PATH}/c-parse.c
    ${SPEC_176_GCC_PATH}/c-lang.c
    ${SPEC_176_GCC_PATH}/c-lex.c
    ${SPEC_176_GCC_PATH}/c-pragma.c
    ${SPEC_176_GCC_PATH}/c-decl.c
    ${SPEC_176_GCC_PATH}/c-typeck.c
    ${SPEC_176_GCC_PATH}/c-convert.c
    ${SPEC_176_GCC_PATH}/c-aux-info.c
    ${SPEC_176_GCC_PATH}/c-common.c
    ${SPEC_176_GCC_PATH}/c-iterate.c
    ${SPEC_176_GCC_PATH}/toplev.c
    ${SPEC_176_GCC_PATH}/version.c
    ${SPEC_176_GCC_PATH}/tree.c
    ${SPEC_176_GCC_PATH}/print-tree.c
    ${SPEC_176_GCC_PATH}/stor-layout.c
    ${SPEC_176_GCC_PATH}/fold-const.c
    ${SPEC_176_GCC_PATH}/function.c
    ${SPEC_176_GCC_PATH}/stmt.c
    ${SPEC_176_GCC_PATH}/expr.c
    ${SPEC_176_GCC_PATH}/calls.c
    ${SPEC_176_GCC_PATH}/expmed.c
    ${SPEC_176_GCC_PATH}/explow.c
    ${SPEC_176_GCC_PATH}/optabs.c
    ${SPEC_176_GCC_PATH}/varasm.c
    ${SPEC_176_GCC_PATH}/rtl.c
    ${SPEC_176_GCC_PATH}/print-rtl.c
    ${SPEC_176_GCC_PATH}/rtlanal.c
    ${SPEC_176_GCC_PATH}/emit-rtl.c
    ${SPEC_176_GCC_PATH}/real.c
    ${SPEC_176_GCC_PATH}/dbxout.c
    ${SPEC_176_GCC_PATH}/sdbout.c
    ${SPEC_176_GCC_PATH}/dwarfout.c
    ${SPEC_176_GCC_PATH}/xcoffout.c
    ${SPEC_176_GCC_PATH}/integrate.c
    ${SPEC_176_GCC_PATH}/jump.c
    ${SPEC_176_GCC_PATH}/cse.c
    ${SPEC_176_GCC_PATH}/loop.c
    ${SPEC_176_GCC_PATH}/unroll.c
    ${SPEC_176_GCC_PATH}/flow.c
    ${SPEC_176_GCC_PATH}/stupid.c
    ${SPEC_176_GCC_PATH}/combine.c
    ${SPEC_176_GCC_PATH}/regclass.c
    ${SPEC_176_GCC_PATH}/local-alloc.c
    ${SPEC_176_GCC_PATH}/global.c
    ${SPEC_176_GCC_PATH}/reload.c
    ${SPEC_176_GCC_PATH}/reload1.c
    ${SPEC_176_GCC_PATH}/caller-save.c
    ${SPEC_176_GCC_PATH}/insn-peep.c
    ${SPEC_176_GCC_PATH}/reorg.c
    ${SPEC_176_GCC_PATH}/sched.c
    ${SPEC_176_GCC_PATH}/final.c
    ${SPEC_176_GCC_PATH}/recog.c
    ${SPEC_176_GCC_PATH}/reg-stack.c
    ${SPEC_176_GCC_PATH}/insn-opinit.c
    ${SPEC_176_GCC_PATH}/insn-recog.c
    ${SPEC_176_GCC_PATH}/insn-extract.c
    ${SPEC_176_GCC_PATH}/insn-output.c
    ${SPEC_176_GCC_PATH}/insn-emit.c
    ${SPEC_176_GCC_PATH}/insn-attrtab.c
    ${SPEC_176_GCC_PATH}/m88k.c
    ${SPEC_176_GCC_PATH}/getpwd.c
    ${SPEC_176_GCC_PATH}/convert.c
    ${SPEC_176_GCC_PATH}/bc-emit.c
    ${SPEC_176_GCC_PATH}/bc-optab.c
    ${SPEC_176_GCC_PATH}/obstack.c)

if (ANDROID_WASM)
  target_sources(176.gcc PRIVATE
      ${WASM_LIBRARY_PATH}/open-proxy.c
      ${WASM_LIBRARY_PATH}/standalone-printf.c)
endif()
