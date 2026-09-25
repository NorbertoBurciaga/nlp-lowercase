cmake_minimum_required(VERSION 3.15)
project(nlp_lowercase VERSION 1.0.0 LANGUAGES CXX)

add_library(nlp_lowercase src/lowercase.cpp)
add_library(nlp::lowercase ALIAS nlp_lowercase)

target_include_directories(nlp_lowercase PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_compile_features(nlp_lowercase PUBLIC cxx_std_17)

include(GNUInstallDirs)
install(TARGETS nlp_lowercase EXPORT nlp_lowercase_targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT nlp_lowercase_targets
    FILE nlp_lowercase-targets.cmake
    NAMESPACE nlp::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/nlp_lowercase)
