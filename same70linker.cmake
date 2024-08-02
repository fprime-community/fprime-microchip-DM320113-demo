# # same70linker.cmake

# # Include necessary directories
# include_directories(
#     ${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B
#     ${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B_DFP
#     ${CMAKE_CURRENT_LIST_DIR}/CMSIS
#     ${CMAKE_CURRENT_LIST_DIR}/CMSIS/CMSIS/Core/Include
# )

# # Add ATSAME70Q21B specific source files
# add_library(ATSAME70Q21B_DFP
#     ${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B/startup_atsame70q21b.c
# )

# # Link directories
# link_directories(
#     ${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B
#     ${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B_DFP
#     ${CMAKE_CURRENT_LIST_DIR}/CMSIS
#     ${CMAKE_CURRENT_LIST_DIR}/CMSIS/CMSIS/Core/Include
# )

# # Add the linker script
# set(LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B/ATSAME70Q21B.ld)

# # Link the ATSAME70Q21B_DFP library to the target executable
# # target_link_libraries(${PROJECT_NAME} ATSAME70Q21B_DFP)

# # Set the linker script
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T${LINKER_SCRIPT}")

# # Additional configurations
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -specs=${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B/specs-ATSAME70Q21B")

