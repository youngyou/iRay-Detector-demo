cmake_minimum_required(VERSION 3.0.0)
project(CapDriver VERSION 0.1.0)

include(CTest)
enable_testing()

# find_package(Boost 1.78.0 REQUIRED CONFIG PATHS libs/boost/tools/boost_install)

include_directories(./sdk/cpp)
link_directories(./sdk/bin/x64) 

include_directories(include)

file(GLOB SOURCE_FILES  "src/*.cpp"  "include/*.h")
list(REMOVE_ITEM SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# add_subdirectory(deps/fmt)
# add_subdirectory(deps/boost EXCLUDE_FROM_ALL)

add_library(CapDriver ${SOURCE_FILES})

add_executable(CapTest src/main.cpp)
add_dependencies(CapTest CapDriver)
target_link_libraries(CapTest CapDriver)

# test
# add_subdirectory(test)
add_test(NAME test COMMAND CapTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# macro(add_sdk_dll DLL)
#     add_custom_command(TARGET CapDriver POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/sdk/bin/x64/${DLL}" $<TARGET_FILE_DIR:CapDriver>)
# endmacro()

# add_sdk_dll(E3.dll)


file(GLOB SDK_DLL "sdk/bin/x64/*.dll" "sdk/bin/x64/*.exe")
foreach(dllFile IN LISTS SDK_DLL)
	add_custom_command(TARGET CapDriver POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${dllFile} $<TARGET_FILE_DIR:CapDriver> COMMENT "Copying SDK DLL: ${dllFile}")
endforeach()