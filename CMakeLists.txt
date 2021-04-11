cmake_minimum_required(VERSION 3.16.3)
project(google_dino_ai)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2")

find_package(pig REQUIRED)
message("path is" ${pig_DIR})
find_package(sdl2_vendor REQUIRED)
find_package(sdl2_custom REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)


add_executable(main src/main.cpp src/redeNeural.c)
target_link_libraries(main PUBLIC pig::pig SDL2::SDL2 SDL2::Image SDL2::TTF)
target_include_directories(main PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}>
)
target_compile_definitions(main 
  PRIVATE PIG_RESOURCES_PATH="${pig_DIR}/../fontes" 
  PRIVATE GOOGLE_DINO_AI_RESOURCES_PATH="${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}/resources"
)

install(TARGETS main
  DESTINATION bin
)

install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION include
)

install(FILES package.xml 
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY resources
  DESTINATION share/${PROJECT_NAME}
)


# export the package
install(TARGETS main
    EXPORT ${PROJECT_NAME}Config
    # ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    # LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    # RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
export(TARGETS main
    NAMESPACE ${PROJECT_NAME}::
    FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
)
install(EXPORT ${PROJECT_NAME}Config
    DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}/cmake"
    NAMESPACE ${PROJECT_NAME}::
)
