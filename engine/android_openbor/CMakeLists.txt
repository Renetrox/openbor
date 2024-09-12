cmake_minimum_required(VERSION 3.14.7 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
project(openbor)

#FetchContent_Declare(
#  SDL
#  URL            https://github.com/libsdl-org/SDL/archive/refs/tags/release-2.28.5.zip
#  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/external/SDL2
#)
#
#FetchContent_Declare(
#  SDL_IMAGE
#  URL            https://github.com/libsdl-org/SDL_image/archive/release-2.8.1.zip
#  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/external/SDL2_image
#)
#
#FetchContent_MakeAvailable(SDL SDL_IMAGE)

#######################################
# add libraries
#######################################

add_library(libCalcLibAndroid STATIC IMPORTED)

add_library(libSDL2 SHARED IMPORTED)
set_target_properties(libSDL2
                      PROPERTIES
                      IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/libs/${ANDROID_ABI}/libSDL2.so )
                      #INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/include)

add_library(libhidapi SHARED IMPORTED)
set_target_properties(libhidapi
                      PROPERTIES
                      IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/libs/${ANDROID_ABI}/libhidapi.so )

add_library(libpng STATIC IMPORTED )
set_target_properties(libpng
                      PROPERTIES
                      IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/libs/${ANDROID_ABI}/libpng.a )

add_library(libogg STATIC IMPORTED )
set_target_properties(libogg
                      PROPERTIES
                      IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/libs/${ANDROID_ABI}/libogg.a )

add_library(libvorbisidec STATIC IMPORTED )
set_target_properties(libvorbisidec
                      PROPERTIES
                      IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/libs/${ANDROID_ABI}/libvorbisidec.a )

add_library(libvpx STATIC IMPORTED )
set_target_properties(libvpx
                      PROPERTIES
                      IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/libs/${ANDROID_ABI}/libvpx.a )

# Copying needed files for the android project
set(SDL_ACTIVITY_FOLDER app/src/main/java/org/libsdl/app/)
file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/android/${SDL_ACTIVITY_FOLDER})
file(COPY ${CMAKE_SOURCE_DIR}/external/SDL2/android-project/${SDL_ACTIVITY_FOLDER} DESTINATION ${CMAKE_SOURCE_DIR}/android/${SDL_ACTIVITY_FOLDER})
file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/android/app/src/main/assets/res)
file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_SOURCE_DIR}/android/app/src/main/assets)

 #native library

file(GLOB SRC_OBOR  "${CMAKE_SOURCE_DIR}/../* .c"
                    "${CMAKE_SOURCE_DIR}/../sdl/*.c"
                    "${CMAKE_SOURCE_DIR}/../*.c"
                    "${CMAKE_SOURCE_DIR}/../source/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/adpcmlib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/gamelib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/gfxlib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/pnglib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/preprocessorlib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/ramlib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/randlib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/scriptlib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/openborscript/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/webmlib/*.c"
                    "${CMAKE_SOURCE_DIR}/../source/webmlib/*/*.c")
# Target Sources
set(SRC_FILES ${SRC_OBOR})

# Target Executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} SHARED  ${CMAKE_SOURCE_DIR}/src/include
                                                    ${CMAKE_SOURCE_DIR}/include/png
                                                    ${CMAKE_SOURCE_DIR}/include/sdl
                                                    ${CMAKE_SOURCE_DIR}/../
                                                    ${CMAKE_SOURCE_DIR}/../sdl
                                                    ${CMAKE_SOURCE_DIR}/../resources
                                                    ${CMAKE_SOURCE_DIR}/../source
                                                    ${CMAKE_SOURCE_DIR}/../source/adpcmlib
                                                    ${CMAKE_SOURCE_DIR}/../source/gamelib
                                                    ${CMAKE_SOURCE_DIR}/../source/gfxlib
                                                    ${CMAKE_SOURCE_DIR}/../source/pnglib
                                                    ${CMAKE_SOURCE_DIR}/../source/preprocessorlib
                                                    ${CMAKE_SOURCE_DIR}/../source/ramlib
                                                    ${CMAKE_SOURCE_DIR}/../source/randlib
                                                    ${CMAKE_SOURCE_DIR}/../source/scriptlib
                                                    ${CMAKE_SOURCE_DIR}/../source/openborscript
                                                    ${CMAKE_SOURCE_DIR}/../source/tracelib2
                                                    ${CMAKE_SOURCE_DIR}/../source/webmlib
                                                    ${CMAKE_SOURCE_DIR}/../source/webmlib/halloc
                                                    ${CMAKE_SOURCE_DIR}/../source/webmlib/nestegg
                                                    )

#add_library( main SHARED ${SOURCE_FILES} )

target_link_libraries(${PROJECT_NAME}
                      libSDL2
                      libhidapi
                      libpng
                      libogg
                      libvorbisidec
                      libvpx
                      )
