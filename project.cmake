# This CMake file is intended to register project-wide objects.
# This allows for reuse between deployments, or other projects.

# Add the CMSIS directory
include_directories(
  "${CMAKE_CURRENT_LIST_DIR}/CMSIS/CMSIS/Core/Include"
  "${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B_DFP"
)

# Find all directories in the ATSAME70Q21B_DFP directory and include them
file(GLOB_RECURSE ATSAME70Q21B_INCLUDE_DIRS
  LIST_DIRECTORIES true
  "${CMAKE_CURRENT_LIST_DIR}/ATSAME70Q21B_DFP/*"
)

foreach(atsame70q21b_dir ${ATSAME70Q21B_INCLUDE_DIRS})
  if(IS_DIRECTORY ${atsame70q21b_dir})
    include_directories(${atsame70q21b_dir})
  endif()
endforeach()

add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Components")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/RefDemo/")
