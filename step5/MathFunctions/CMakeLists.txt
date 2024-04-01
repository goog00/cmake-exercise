# MathFunctions/CMakeLists.txt
add_library(MathFunctions mysqrt.cpp)

#step5
# INTERFACE是指消费者需要、但生产者不需要的那些东西。在MathFunctions/CMakeLists.txt
#CMAKE_CURRENT_SOURCE_DIR 表示 MathFunctions 库所在目录。
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )