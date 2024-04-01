cmake_minimum_required(VERSION 3.10)

#set the project name
project(Tutorial VERSION 1.0.2)

SET(SRC_LIST tutorial.cpp)

#option 表示提供用户可以选择的选项。命令格式为：option(<variable> "description [initial value])。
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# step3: add the MathFunctions library
# add_subdirectory(MathFunctions)


#step4
# 在 if 块中，有 add_subdirectory 命令和 list 命令，APPEND表示将元素MathFunctions追加到列表EXTRA_LIBS中，
# 将元素 ${PROJECT_SOURCE_DIR}/MathFunctions 追加到列表EXTRA_INCLUDES中。
# EXTRA_LIBS 存储 MathFunctions 库，EXTRA_INCLUDES 存储 MathFunctions 头文件。
# 变量EXTRA_LIBS用来保存需要链接到可执行程序的可选库，变量EXTRA_INCLUDES用来保存可选的头文件搜索路径
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  #step5
  # 现在我们已经为 MathFunctions 指定了使用要求 INTERFACE，那么可以从顶级 CMakeLists.txt 中删除EXTRA_INCLUDES变量的相关使用：
  # list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/MathFunctions)
endif()


#add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

#step3: 
# target_link_libraries(${PROJECT_NAME} PUBLIC MathFunctions)
#step4
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})



configure_file(TutorialConfig.h.in TutorialConfig.h)

#PROJECT_BINARY_DIR 表示当前工程的二进制路径，即编译产物会存放到该路径，
#此时PROJECT_BINARY_DIR 就是 build 所在路径
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           #step3
                        #    ${PROJECT_SOURCE_DIR}/MathFunctions
                        #step4
                        #${EXTRA_INCLUDES}  step5 删除此行
                           )


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

string(TIMESTAMP COMPILE_TIME %Y%m%d-%H%M%S)



