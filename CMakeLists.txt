cmake_minimum_required(VERSION 4.1)
project(pong_game)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.6 COMPONENTS system window graphics audio network REQUIRED)

add_executable(pong_game src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

if(WIN32)
    add_custom_command(
            TARGET ${PROJECT_NAME}
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy
            ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
            VERBATIM
    )
endif()