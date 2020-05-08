CMAKE_MINIMUM_REQUIRED(VERSION 2.8)  # 设定版本
PROJECT(tinyxmlTest) # 设定工程名
SET(CMAKE_CXX_COMPILER "g++")  # 设定编译器
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 
# 设定可执行二进制文件的目录（最后生成的可执行文件放置的目录）
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/deploy)
  
# 设定头文件目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/tinyxml)

#目录源码路径
SET( TINYXMLTEST_SRC_DIR ${PROJECT_SOURCE_DIR}/source/tinyxml )

#代码列表
FILE (GLOB TINYXMLTEST_FILES ${TINYXMLTEST_SRC_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/source/*.cpp)


# 生成可执行文件
ADD_EXECUTABLE(tinyxmlTest ${TINYXMLTEST_FILES})

