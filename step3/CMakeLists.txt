cmake_minimum_required(VERSION 3.10)

#set the project name
project(Tutorial VERSION 1.0.2)

SET(SRC_LIST tutorial.cpp)

# step3: add the MathFunctions library
add_subdirectory(MathFunctions)


#add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

#step3: 
target_link_libraries(${PROJECT_NAME} PUBLIC MathFunctions)




configure_file(TutorialConfig.h.in TutorialConfig.h)

#PROJECT_BINARY_DIR 表示当前工程的二进制路径，即编译产物会存放到该路径，
#此时PROJECT_BINARY_DIR 就是 build 所在路径
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${PROJECT_SOURCE_DIR}/MathFunctions
                           )


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

string(TIMESTAMP COMPILE_TIME %Y%m%d-%H%M%S)



