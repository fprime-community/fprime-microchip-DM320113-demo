####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
# UT_SOURCE_FILES: list of source files for unit tests
#
####

# Include the usart1src directory
include_directories(
  "${CMAKE_CURRENT_LIST_DIR}/usart1src"
)

# Find all source files in the usart1src directory
file(GLOB USART1SRC_FILES "${CMAKE_CURRENT_LIST_DIR}/usart1src/*.c")


# Include the sys directory
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/usart1src/sys")

set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/usart1Driver.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/usart1Driver.cpp"
  ${USART1SRC_FILES}  # Add all source files from the usart1src directory
)

# Uncomment and add any modules that this component depends on, else
# they might not be available when cmake tries to build this component.

# set(MOD_DEPS
#     Add your dependencies here
# )

register_fprime_module()
