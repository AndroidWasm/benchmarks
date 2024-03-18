cmake_minimum_required(VERSION 3.18.1)

project("spec2000")

set(INT_BENCHMARKS_ROOT "benchspec/CINT2000")

# Unable to compile to WASM: 176.gcc (prototypes, va_list), 186.crafty (prototypes), 253.perlbmk (va_list), 254.gap (prototypes), 300.twolf (prototypes)

set(SPEC_164_GZIP_PATH "${INT_BENCHMARKS_ROOT}/164.gzip/src")
set(SPEC_175_VPR_PATH "${INT_BENCHMARKS_ROOT}/175.vpr/src")
set(SPEC_181_MCF_PATH "${INT_BENCHMARKS_ROOT}/181.mcf/src")
set(SPEC_197_PARSER_PATH "${INT_BENCHMARKS_ROOT}/197.parser/src")
set(SPEC_252_EON_PATH "${INT_BENCHMARKS_ROOT}/252.eon/src")
set(SPEC_255_VORTEX_PATH "${INT_BENCHMARKS_ROOT}/255.vortex/src")
set(SPEC_256_BZIP2_PATH "${INT_BENCHMARKS_ROOT}/256.bzip2/src")

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

add_executable(181.mcf
   ${SPEC_181_MCF_PATH}/mcf.c
   ${SPEC_181_MCF_PATH}/mcfutil.c
   ${SPEC_181_MCF_PATH}/readmin.c
   ${SPEC_181_MCF_PATH}/implicit.c
   ${SPEC_181_MCF_PATH}/pstart.c
   ${SPEC_181_MCF_PATH}/output.c
   ${SPEC_181_MCF_PATH}/treeup.c
   ${SPEC_181_MCF_PATH}/pbla.c
   ${SPEC_181_MCF_PATH}/pflowup.c
   ${SPEC_181_MCF_PATH}/psimplex.c
   ${SPEC_181_MCF_PATH}/pbeampp.c)

target_link_libraries(181.mcf PRIVATE
   m)

add_executable(197.parser
   ${SPEC_197_PARSER_PATH}/analyze-linkage.c
   ${SPEC_197_PARSER_PATH}/and.c
   ${SPEC_197_PARSER_PATH}/build-disjuncts.c
   ${SPEC_197_PARSER_PATH}/extract-links.c
   ${SPEC_197_PARSER_PATH}/fast-match.c
   ${SPEC_197_PARSER_PATH}/idiom.c
   ${SPEC_197_PARSER_PATH}/main.c
   ${SPEC_197_PARSER_PATH}/massage.c
   ${SPEC_197_PARSER_PATH}/parse.c
   ${SPEC_197_PARSER_PATH}/post-process.c
   ${SPEC_197_PARSER_PATH}/print.c
   ${SPEC_197_PARSER_PATH}/prune.c
   ${SPEC_197_PARSER_PATH}/read-dict.c
   ${SPEC_197_PARSER_PATH}/utilities.c
   ${SPEC_197_PARSER_PATH}/xalloc.c
   ${SPEC_197_PARSER_PATH}/word-file.c
   ${SPEC_197_PARSER_PATH}/strncasecmp.c)

target_link_libraries(197.parser PRIVATE
   m)

add_executable(252.eon
   ${SPEC_252_EON_PATH}/ggCoverageSolidTexture.cc
   ${SPEC_252_EON_PATH}/ggPathDielectricMaterial.cc
   ${SPEC_252_EON_PATH}/ggBox2.cc
   ${SPEC_252_EON_PATH}/ggBox3.cc
   ${SPEC_252_EON_PATH}/ggRasterSurfaceTexture.cc
   ${SPEC_252_EON_PATH}/ggJitterSample1.cc
   ${SPEC_252_EON_PATH}/ggNRooksSample2.cc
   ${SPEC_252_EON_PATH}/ggJitterSample2.cc
   ${SPEC_252_EON_PATH}/ggRGBFPixel.cc
   ${SPEC_252_EON_PATH}/ggRotatingPinholeCamera.cc
   ${SPEC_252_EON_PATH}/ggRandomSample2.cc
   ${SPEC_252_EON_PATH}/ggRandomSample3.cc
   ${SPEC_252_EON_PATH}/ggSolidNoise2.cc
   ${SPEC_252_EON_PATH}/ggSolidNoise3.cc
   ${SPEC_252_EON_PATH}/ggSolidTexture.cc
   ${SPEC_252_EON_PATH}/ggOakSolidTexture.cc
   ${SPEC_252_EON_PATH}/ggSpecularMaterial.cc
   ${SPEC_252_EON_PATH}/ggNA.cc
   ${SPEC_252_EON_PATH}/ggMaterial.cc
   ${SPEC_252_EON_PATH}/ggDiffuseMaterial.cc
   ${SPEC_252_EON_PATH}/ggDielectricMaterial.cc
   ${SPEC_252_EON_PATH}/ggConductorMaterial.cc
   ${SPEC_252_EON_PATH}/ggEdgeDiscrepancy.cc
   ${SPEC_252_EON_PATH}/ggPolishedMaterial.cc
   ${SPEC_252_EON_PATH}/ggFrameInterpolation.cc
   ${SPEC_252_EON_PATH}/ggQuaternion.cc
   ${SPEC_252_EON_PATH}/ggSpline.cc
   ${SPEC_252_EON_PATH}/ggONB2.cc
   ${SPEC_252_EON_PATH}/ggONB3.cc
   ${SPEC_252_EON_PATH}/ggFrame2.cc
   ${SPEC_252_EON_PATH}/ggFrame3.cc
   ${SPEC_252_EON_PATH}/ggHMatrix3.cc
   ${SPEC_252_EON_PATH}/ggSphere.cc
   ${SPEC_252_EON_PATH}/ggRGBE.cc
   ${SPEC_252_EON_PATH}/ggGamma.cc
   ${SPEC_252_EON_PATH}/ggBRDF.cc
   ${SPEC_252_EON_PATH}/ggDiffuseBRDF.cc
   ${SPEC_252_EON_PATH}/ggPhongBRDF.cc
   ${SPEC_252_EON_PATH}/ggPolishedBRDF.cc
   ${SPEC_252_EON_PATH}/ggCamera.cc
   ${SPEC_252_EON_PATH}/ggPinholeCamera.cc
   ${SPEC_252_EON_PATH}/ggThinLensCamera.cc
   ${SPEC_252_EON_PATH}/ggErr.cc
   ${SPEC_252_EON_PATH}/ggPixelFilter.cc
   ${SPEC_252_EON_PATH}/ggTrianglePixelFilter.cc
   ${SPEC_252_EON_PATH}/ggBoxPixelFilter.cc
   ${SPEC_252_EON_PATH}/ggFormat.cc
   ${SPEC_252_EON_PATH}/ggGeometry.cc
   ${SPEC_252_EON_PATH}/ggHAffineMatrix3.cc
   ${SPEC_252_EON_PATH}/ggHShearMatrix3.cc
   ${SPEC_252_EON_PATH}/ggHBoxMatrix3.cc
   ${SPEC_252_EON_PATH}/ggHPerspectiveMatrix3.cc
   ${SPEC_252_EON_PATH}/ggHTranslationMatrix3.cc
   ${SPEC_252_EON_PATH}/ggHRigidBodyMatrix3.cc
   ${SPEC_252_EON_PATH}/ggHRotationMatrix3.cc
   ${SPEC_252_EON_PATH}/ggHScaleMatrix3.cc
   ${SPEC_252_EON_PATH}/ggHPoint3.cc
   ${SPEC_252_EON_PATH}/ggPoint2.cc
   ${SPEC_252_EON_PATH}/ggPoint3.cc
   ${SPEC_252_EON_PATH}/ggOptics.cc
   ${SPEC_252_EON_PATH}/ggPlane.cc
   ${SPEC_252_EON_PATH}/ggPolygon.cc
   ${SPEC_252_EON_PATH}/ggGrayPixel_x.cc
   ${SPEC_252_EON_PATH}/ggRGBPixel_x.cc
   ${SPEC_252_EON_PATH}/ggRay2.cc
   ${SPEC_252_EON_PATH}/ggRay3.cc
   ${SPEC_252_EON_PATH}/ggBoardFloorSolidTexture.cc
   ${SPEC_252_EON_PATH}/ggVector2.cc
   ${SPEC_252_EON_PATH}/ggVector3.cc
   ${SPEC_252_EON_PATH}/ggString.cc
   ${SPEC_252_EON_PATH}/ggFineSpectrum.cc
   ${SPEC_252_EON_PATH}/ggSpectrum.cc
   ${SPEC_252_EON_PATH}/eon.cc
   ${SPEC_252_EON_PATH}/eonImageCalculator.cc
   ${SPEC_252_EON_PATH}/mrObjectRecord.cc
   ${SPEC_252_EON_PATH}/mrCoarsePixelRenderer.cc
   ${SPEC_252_EON_PATH}/mrIndirectPixelRenderer.cc
   ${SPEC_252_EON_PATH}/mrRushmeierPixelRenderer.cc
   ${SPEC_252_EON_PATH}/mrBruteForcePixelRenderer.cc
   ${SPEC_252_EON_PATH}/mrKajiyaPixelRenderer.cc
   ${SPEC_252_EON_PATH}/mrCookPixelRenderer.cc
   ${SPEC_252_EON_PATH}/mrGrid.cc
   ${SPEC_252_EON_PATH}/mrScene.cc
   ${SPEC_252_EON_PATH}/mrCamera.cc
   ${SPEC_252_EON_PATH}/mrTriangle.cc
   ${SPEC_252_EON_PATH}/mrFastTriangle.cc
   ${SPEC_252_EON_PATH}/mrPolygon.cc
   ${SPEC_252_EON_PATH}/mrXYDisk.cc
   ${SPEC_252_EON_PATH}/mrXZDisk.cc
   ${SPEC_252_EON_PATH}/mrYZDisk.cc
   ${SPEC_252_EON_PATH}/mrPhongAreaXYRectangleLuminaire.cc
   ${SPEC_252_EON_PATH}/mrPhongAreaXZRectangleLuminaire.cc
   ${SPEC_252_EON_PATH}/mrPhongAreaYZRectangleLuminaire.cc
   ${SPEC_252_EON_PATH}/mrEmitter.cc
   ${SPEC_252_EON_PATH}/mrImposter.cc
   ${SPEC_252_EON_PATH}/mrLinkedObjects.cc
   ${SPEC_252_EON_PATH}/mrBox.cc
   ${SPEC_252_EON_PATH}/mrXCylinder.cc
   ${SPEC_252_EON_PATH}/mrYCylinder.cc
   ${SPEC_252_EON_PATH}/mrZCylinder.cc
   ${SPEC_252_EON_PATH}/mrDiffuseAreaZCylinderLuminaire.cc
   ${SPEC_252_EON_PATH}/mrDiffuseCosineZCylinderLuminaire.cc
   ${SPEC_252_EON_PATH}/mrDiffuseVisibleAreaZCylinderLuminaire.cc
   ${SPEC_252_EON_PATH}/mrXEllipticalCylinder.cc
   ${SPEC_252_EON_PATH}/mrYEllipticalCylinder.cc
   ${SPEC_252_EON_PATH}/mrZEllipticalCylinder.cc
   ${SPEC_252_EON_PATH}/mrSpotAreaXYDiskLuminaire.cc
   ${SPEC_252_EON_PATH}/mrDiffuseAreaXYRectangleLuminaire.cc
   ${SPEC_252_EON_PATH}/mrDiffuseAreaXZRectangleLuminaire.cc
   ${SPEC_252_EON_PATH}/mrDiffuseAreaYZRectangleLuminaire.cc
   ${SPEC_252_EON_PATH}/mrSurfaceList.cc
   ${SPEC_252_EON_PATH}/mrDiffuseAreaTriangleLuminaire.cc
   ${SPEC_252_EON_PATH}/mrDiffuseAreaSphereLuminaire.cc
   ${SPEC_252_EON_PATH}/mrDiffuseCosineSphereLuminaire.cc
   ${SPEC_252_EON_PATH}/mrDiffuseSolidAngleSphereLuminaire.cc
   ${SPEC_252_EON_PATH}/mrShellLuminaire.cc
   ${SPEC_252_EON_PATH}/mrInstance.cc
   ${SPEC_252_EON_PATH}/mrMaterial.cc
   ${SPEC_252_EON_PATH}/mrPhongAreaTriangleLuminaire.cc
   ${SPEC_252_EON_PATH}/mrSolidTexture.cc
   ${SPEC_252_EON_PATH}/mrSphere.cc
   ${SPEC_252_EON_PATH}/mrSurface.cc
   ${SPEC_252_EON_PATH}/mrSurfaceTexture.cc
   ${SPEC_252_EON_PATH}/mrXYRectangle.cc
   ${SPEC_252_EON_PATH}/mrXZRectangle.cc
   ${SPEC_252_EON_PATH}/mrYZRectangle.cc
   ${SPEC_252_EON_PATH}/myrand.cc)

target_include_directories(252.eon PRIVATE
  ${SPEC_252_EON_PATH})

target_compile_options(252.eon PRIVATE
    -DSPEC_CPU2000_LP64 -DUSE_STRERROR -Wno-register)

target_link_libraries(252.eon PRIVATE
   c++
   m)
   
if (ANDROID_WASM)
  target_link_libraries(252.eon PRIVATE
   clang_rt.builtins)
endif()

add_executable(255.vortex
   ${SPEC_255_VORTEX_PATH}/bitvec.c
   ${SPEC_255_VORTEX_PATH}/bmt.c
   ${SPEC_255_VORTEX_PATH}/bmt0.c
   ${SPEC_255_VORTEX_PATH}/bmt01.c
   ${SPEC_255_VORTEX_PATH}/bmt10.c
   ${SPEC_255_VORTEX_PATH}/bmtlib.c
   ${SPEC_255_VORTEX_PATH}/bmtobj.c
   ${SPEC_255_VORTEX_PATH}/core01.c
   ${SPEC_255_VORTEX_PATH}/dba.c
   ${SPEC_255_VORTEX_PATH}/dbm0.c
   ${SPEC_255_VORTEX_PATH}/dbm1.c
   ${SPEC_255_VORTEX_PATH}/dbm2.c
   ${SPEC_255_VORTEX_PATH}/domain.c
   ${SPEC_255_VORTEX_PATH}/draw07.c
   ${SPEC_255_VORTEX_PATH}/draw7.c
   ${SPEC_255_VORTEX_PATH}/drawlib.c
   ${SPEC_255_VORTEX_PATH}/drawobj.c
   ${SPEC_255_VORTEX_PATH}/emplib.c
   ${SPEC_255_VORTEX_PATH}/empobj.c
   ${SPEC_255_VORTEX_PATH}/env0.c
   ${SPEC_255_VORTEX_PATH}/env01.c
   ${SPEC_255_VORTEX_PATH}/env1.c
   ${SPEC_255_VORTEX_PATH}/fm.c
   ${SPEC_255_VORTEX_PATH}/gdbm.c
   ${SPEC_255_VORTEX_PATH}/grp0.c
   ${SPEC_255_VORTEX_PATH}/grp1.c
   ${SPEC_255_VORTEX_PATH}/grp2.c
   ${SPEC_255_VORTEX_PATH}/hm.c
   ${SPEC_255_VORTEX_PATH}/iam.c
   ${SPEC_255_VORTEX_PATH}/ifm.c
   ${SPEC_255_VORTEX_PATH}/im.c
   ${SPEC_255_VORTEX_PATH}/km.c
   ${SPEC_255_VORTEX_PATH}/list01.c
   ${SPEC_255_VORTEX_PATH}/mem00.c
   ${SPEC_255_VORTEX_PATH}/mem01.c
   ${SPEC_255_VORTEX_PATH}/mem10.c
   ${SPEC_255_VORTEX_PATH}/oa0.c
   ${SPEC_255_VORTEX_PATH}/oa1.c
   ${SPEC_255_VORTEX_PATH}/oadmp.c
   ${SPEC_255_VORTEX_PATH}/obj01.c
   ${SPEC_255_VORTEX_PATH}/odbm.c
   ${SPEC_255_VORTEX_PATH}/ogrp.c
   ${SPEC_255_VORTEX_PATH}/om.c
   ${SPEC_255_VORTEX_PATH}/point.c
   ${SPEC_255_VORTEX_PATH}/primal.c
   ${SPEC_255_VORTEX_PATH}/pstub.c
   ${SPEC_255_VORTEX_PATH}/query.c
   ${SPEC_255_VORTEX_PATH}/rect.c
   ${SPEC_255_VORTEX_PATH}/rects.c
   ${SPEC_255_VORTEX_PATH}/sa.c
   ${SPEC_255_VORTEX_PATH}/shell.c
   ${SPEC_255_VORTEX_PATH}/sm.c
   ${SPEC_255_VORTEX_PATH}/testobj.c
   ${SPEC_255_VORTEX_PATH}/tm.c
   ${SPEC_255_VORTEX_PATH}/trans00.c
   ${SPEC_255_VORTEX_PATH}/trans01.c
   ${SPEC_255_VORTEX_PATH}/trans10.c
   ${SPEC_255_VORTEX_PATH}/trans20.c
   ${SPEC_255_VORTEX_PATH}/tree0.c
   ${SPEC_255_VORTEX_PATH}/tree00.c
   ${SPEC_255_VORTEX_PATH}/tree01.c
   ${SPEC_255_VORTEX_PATH}/ut.c
   ${SPEC_255_VORTEX_PATH}/vchunk.c
   ${SPEC_255_VORTEX_PATH}/vdbm.c
   ${SPEC_255_VORTEX_PATH}/voa.c
   ${SPEC_255_VORTEX_PATH}/vom.c)

target_compile_options(255.vortex PRIVATE
    -DSPEC_CPU2000_LP64)

target_link_libraries(255.vortex PRIVATE
   m)

add_executable(256.bzip2
   ${SPEC_256_BZIP2_PATH}/bzip2.c
   ${SPEC_256_BZIP2_PATH}/spec.c)
