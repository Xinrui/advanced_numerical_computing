add_library(mumps_algo)

target_sources(mumps_algo PRIVATE 
	include/Doolittle.h 
	include/Factorization.h
	src/Doolittle.cpp
	src/Factorization.cpp
)

target_include_directories(mumps_algo PUBLIC include)

add_executable(mumps_algo_testrunner test/LU_Factorization.cpp)

target_link_libraries(mumps_algo_testrunner GTest::gtest_main mumps_algo)
