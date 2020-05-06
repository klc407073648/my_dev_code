CMAKE_MINIMUM_REQUIRED(VERSION 2.8)  # 设定版本
PROJECT(jsonTest) # 设定工程名
SET(CMAKE_CXX_COMPILER "g++")  # 设定编译器
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 
# 设定可执行二进制文件的目录（最后生成的可执行文件放置的目录）
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/deploy)
  
# 设定头文件目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# 查找当前目录下的所有源文件,并将名称保存到 DIR_SRCS 变量
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/source DIR_SRCS)

# 生成可执行文件
ADD_EXECUTABLE(jsonTest ${DIR_SRCS})

