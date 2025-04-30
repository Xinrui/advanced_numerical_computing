add_library(mumps_algo)

target_sources(mumps_algo PRIVATE include/Doolittle.h src/Doolittle.cpp)

target_include_directories(mumps_algo PUBLIC include)

add_executable(mumps_algo_testrunner test/Doolittle.cpp)

target_link_libraries(mumps_algo_testrunner GTest::gtest_main mumps_algo)
