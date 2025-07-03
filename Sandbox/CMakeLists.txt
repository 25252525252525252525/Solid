add_executable(Sandbox main.cpp)

target_link_libraries(Sandbox PRIVATE Solid)

target_include_directories(Sandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
