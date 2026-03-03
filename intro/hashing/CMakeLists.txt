add_executable(intro_hash main.cpp src/hash_table.cpp)

target_include_directories(intro_search
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)