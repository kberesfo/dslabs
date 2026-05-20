add_executable(project
    src/main.cpp
    src/task1/task1.cpp
    src/task2/task2.cpp
    src/task3/task3.cpp
    src/task4/task4.cpp
    src/task5/task5.cpp
    src/task6/task6.cpp
)

target_include_directories(project
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
