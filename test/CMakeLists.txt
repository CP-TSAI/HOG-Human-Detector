set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    ../app/perception.cpp
    ../app/inputHandle.cpp
    ../app/imageProcess.cpp
    ../app/hogHumanDetect.cpp
    ../app/outputDisplay.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
