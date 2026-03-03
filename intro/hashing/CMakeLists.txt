add_executable(intro_hash main.cpp src/hash_table.cpp)

target_include_directories(intro_hash
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)