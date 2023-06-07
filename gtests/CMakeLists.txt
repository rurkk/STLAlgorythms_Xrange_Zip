include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        zip_tests
        zip_tests.cpp
)
add_executable(
        xrange_tests
        xrange_tests.cpp
)
add_executable(
        algorithms_tests
        algorithms_tests.cpp
)


target_link_libraries(
        zip_tests
        GTest::gtest_main
)
target_link_libraries(
        xrange_tests
        GTest::gtest_main
)
target_link_libraries(
        algorithms_tests
        GTest::gtest_main
)

target_include_directories(zip_tests PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(xrange_tests PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(algorithms_tests PUBLIC ${PROJECT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(zip_tests)
gtest_discover_tests(xrange_tests)
gtest_discover_tests(algorithms_tests)