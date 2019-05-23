aux_source_directory(. EXECUTABLE)
foreach(T_FILE_NAME ${EXECUTABLE})
    get_filename_component(EXECUTABLE_NAME ${T_FILE_NAME} NAME_WE)
    # message(${EXECUTABLE_NAME})
    add_executable(${EXECUTABLE_NAME} ${T_FILE_NAME})
    target_link_libraries(
        ${EXECUTABLE_NAME}
        PRIVATE
        leetcode
        ${CMAKE_THREAD_LIBS_INIT}
        GTest::GTest
        GTest::Main
    )
    gtest_discover_tests(${EXECUTABLE_NAME})
endforeach()