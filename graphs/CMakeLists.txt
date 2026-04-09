add_executable(graphs
    src/main.cpp
    src/graph/list_graph.cpp
    src/graph/matrix_graph.cpp
)

target_include_directories(graphs
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)