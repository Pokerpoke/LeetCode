# aux_source_directory(. EXECUTABLE)
# foreach(T_FILE_NAME ${EXECUTABLE})
# 	get_filename_component(EXECUTABLE_NAME ${T_FILE_NAME} NAME_WE)
# 	# message(${EXECUTABLE_NAME})
# 	add_library(${EXECUTABLE_NAME} ${T_FILE_NAME})
# 	# target_link_libraries(${EXECUTABLE_NAME}
# 	# )
# endforeach()

aux_source_directory(. LEETCODE)
add_library(leetcode ${LEETCODE})