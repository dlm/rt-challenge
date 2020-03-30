# setup catch
set(CATCH_DIR ${DEPS_DIR}/catch)
include_directories(${CATCH_DIR}/include)
add_library(Catch INTERFACE)

# aggreage all the test files
FILE(GLOB TEST_FILES *_test.cpp)
add_executable(tests main.cpp ${TEST_FILES})
target_link_libraries(tests Catch)
