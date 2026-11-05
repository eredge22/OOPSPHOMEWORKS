add_library(safe_lib
    src/Valuable.cpp
    src/Safe.cpp
    src/KeySafe.cpp
    src/CombinationSafe.cpp
    src/ElectronicSafe.cpp
)

target_include_directories(safe_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(safe_lib PUBLIC cxx_std_17)
