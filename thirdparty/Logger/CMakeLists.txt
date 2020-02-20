project (logger)

# Header only library, therefore INTERFACE
add_library(logger INTERFACE)

# INTERFACE targets only have INTERFACE properties
target_include_directories(logger INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(logger INTERFACE cxx_std_14)