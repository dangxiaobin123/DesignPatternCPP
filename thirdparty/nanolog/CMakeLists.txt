project (nanolog)

# Header only library, therefore INTERFACE
add_library(nanolog INTERFACE)

# INTERFACE targets only have INTERFACE properties
target_include_directories(nanolog INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(nanolog INTERFACE cxx_std_17)