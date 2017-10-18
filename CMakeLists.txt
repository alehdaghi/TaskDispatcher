cmake_minimum_required(VERSION 3.0)
project(TaskDispatcher)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed")


set(SOURCE_FILES main.cpp AsyncDispatcher.cpp  SimpleDispatcher.cpp )
set(HEADER_FILES Include/AsyncDispatcher.h Include/ThreadDispatcher.h Include/SimpleDispatcher.h)
include_directories(
        Include
)

set(
        LIBS
        pthread
)

add_executable(TaskDispatcher ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(TaskDispatcher ${LIBS})
