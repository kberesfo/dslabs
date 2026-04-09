add_executable(bst
    src/main.cpp
    src/bst/tree.cpp
)

target_include_directories(bst
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)