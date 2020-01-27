project(testapp)
cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules/)
add_executable(${PROJECT_NAME} testapp.cpp tested_class.cpp nontested_class.cpp)

if(WITH_TESTS)
    include(CTest)
    enable_testing()
    set(OBJECT_DIR ${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}.dir)
    find_package(GTest)
    set(OBJs
        ${OBJECT_DIR}/tested_class.cpp.o
        ${OBJECT_DIR}/nontested_class.cpp.o
        )
    add_executable(test_unittest
		testclass_unittest.cpp
		${OBJs}
    )
    foreach(src ${OBJs})
		set_property(SOURCE ${src} PROPERTY GENERATED 1)
    endforeach()
    
    target_link_libraries(test_unittest ${GTEST_LIBRARY} -lpthread)
    add_dependencies(test_unittest ${PROJECT_NAME})
    add_test(NAME test_unittest COMMAND test_unittest)

    if(WITH_COVERAGE)
        include(CodeCoverage)
        append_coverage_compiler_flags()
        set(COVERAGE_EXCLUDES
            testclass_unittest.cpp) #exclude test file from coverage

        setup_target_for_coverage_gcovr_html(NAME ${PROJECT_NAME}_coverage EXECUTABLE ctest -j ${n_cores})
    endif()

endif()
