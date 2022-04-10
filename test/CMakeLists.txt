include_directories(${SimpleLogger_SOURCE_DIR}/src)

add_executable(logger_test
    main.cpp
)

target_link_libraries(logger_test PUBLIC simpleLogger LLVM)
