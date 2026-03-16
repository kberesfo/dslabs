add_executable(linked_list
    src/main.cpp
    src/linked_list/stack.cpp
)

target_include_directories(linked_list
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)