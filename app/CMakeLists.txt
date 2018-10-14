add_executable(shell-app main.cpp)

# Link OpenCV library
target_link_libraries(shell-app ${OpenCV_LIBS})

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
