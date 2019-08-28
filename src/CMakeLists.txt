aux_source_directory(. EXECUTABLE)
foreach(T_FILE_NAME ${EXECUTABLE})
    # get solution id and solution name
    string(REGEX REPLACE ".cc" "" EXECUTABLE_NAME ${T_FILE_NAME})
    string(REGEX REPLACE "\.\/" "" EXECUTABLE_NAME ${EXECUTABLE_NAME})
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