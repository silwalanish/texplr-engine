cmake_minimum_required(VERSION 3.30)

project(engine CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)
find_package(GLEW REQUIRED)
find_package(eventpp REQUIRED)
find_package(ryml REQUIRED)

add_library(${PROJECT_NAME} STATIC)

file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_sources(${PROJECT_NAME} PRIVATE ${LIB_SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)
target_link_libraries(${PROJECT_NAME}
    PRIVATE glfw GLEW::GLEW ryml::ryml
    PUBLIC glm::glm eventpp::eventpp)

install(TARGETS ${PROJECT_NAME})
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/texplr" DESTINATION include)
install(DIRECTORY "${glm_INCLUDE_DIRS}/glm" DESTINATION include)
install(DIRECTORY "${eventpp_INCLUDE_DIRS}/eventpp" DESTINATION include)
