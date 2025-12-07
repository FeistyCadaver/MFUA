cmake_minimum_required(VERSION 3.10)
project(AVLTree CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основной исполняемый файл
add_executable(avl_tree
    main.cpp
)

# Дополнительные цели для тестов
add_library(tree_lib INTERFACE)
target_include_directories(tree_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(avl_tree tree_lib)

# Опция для сборки тестов
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()