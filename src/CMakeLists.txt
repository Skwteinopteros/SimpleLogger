include_directories(${LLVM_INCLUDE_DIRS})

add_library(simpleLogger STATIC
    simple_logger.hpp
    simple_logger.cpp
)

set_target_properties(simpleLogger
    PROPERTIES PREFIX ""
    COMPILE_FLAGS "-fPIC"
)
