cmake_minimum_required(VERSION 3.12)
project(spriterplusplus VERSION 1.0 LANGUAGES CXX)

# GLOB is gross
file(GLOB_RECURSE SPRITER_ENGINE_SRCS *.cpp)

add_library(spriterengine STATIC ${SPRITER_ENGINE_SRCS})
add_library(spriterplusplus::spriterengine ALIAS spriterengine)

target_include_directories(spriterengine PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)

target_compile_features(spriterengine PUBLIC cxx_std_11)

target_compile_options(spriterengine PRIVATE
    $<$<NOT:$<PLATFORM_ID:Windows>>:-Wall>
    $<$<NOT:$<PLATFORM_ID:Windows>>:-Wno-sign-compare>
    $<$<NOT:$<PLATFORM_ID:Windows>>:-Wno-reorder>
    $<$<NOT:$<PLATFORM_ID:Windows>>:-Wno-unused-variable>
)

set_target_properties(spriterengine PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
