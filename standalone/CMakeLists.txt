# cmake_minimum_required(VERSION 3.14...3.22)
#
# project(ConcurrencyStandalone LANGUAGES CXX)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

# CPMAddPackage( GITHUB_REPOSITORY jarro2783/cxxopts VERSION 3.0.0 OPTIONS "CXXOPTS_BUILD_EXAMPLES
# NO" "CXXOPTS_BUILD_TESTS NO" "CXXOPTS_ENABLE_INSTALL YES" )

# CPMAddPackage(NAME Concurrency SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# ---- Create standalone executable ----

file(GLOB sourcesstandalone CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_executable(ConcurrencyStandalone ${sourcesstandalone})

if(EMSCRIPTEN)
  # todo: add pre js to have this if (!crossOriginIsolated) SharedArrayBuffer = ArrayBuffer;
  set(CMAKE_EXECUTABLE_SUFFIX ".html") # todo: we should not need this!
  message(STATUS "EMSCRIPTEN BUILD")
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/../html/shell.html"
  )
  file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../html/thread.js
       DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  )
endif()

message(STATUS "CMAKE_EXECUTABLE_SUFFIX: ${CMAKE_EXECUTABLE_SUFFIX}")

set_target_properties(ConcurrencyStandalone PROPERTIES CXX_STANDARD 20)

target_link_libraries(ConcurrencyStandalone Concurrency::Concurrency)
