add_executable(binary_heaps
    src/main.cpp
    src/heap/heap.cpp
    src/heap/max_heap.cpp
    src/heap/min_heap.cpp
)

target_include_directories(binary_heaps
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)