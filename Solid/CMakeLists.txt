file(GLOB SOLID_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/Platform/Linux/*.cpp"
)

add_library(Solid SHARED ${SOLID_SOURCES})

target_include_directories(Solid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Solid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Core)
target_include_directories(Solid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Event)
target_include_directories(Solid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Linux)

add_library(glad STATIC ${CMAKE_SOURCE_DIR}/vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glad/include)

target_link_libraries(Solid PUBLIC spdlog::spdlog)
target_link_libraries(Solid PUBLIC glfw)
target_link_libraries(Solid PUBLIC glad)
