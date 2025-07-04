file(GLOB SOLID_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp"
)

add_library(Solid SHARED ${SOLID_SOURCES})

target_include_directories(Solid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Solid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Core)
target_link_libraries(Solid PUBLIC spdlog::spdlog)
