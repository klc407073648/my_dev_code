CMAKE_MINIMUM_REQUIRED(VERSION 2.8)  # 设定版本
PROJECT(myprj) # 设定工程名
SET(CMAKE_CXX_COMPILER "g++")  # 设定编译器
 
# 设定可执行二进制文件的目录（最后生成的可执行文件放置的目录）
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/deploy)

SET(INC_DIR ${PROJECT_SOURCE_DIR}/myprj/include ${PROJECT_SOURCE_DIR}/3part/log4cpp/include)
SET(LINK_DIR ${PROJECT_SOURCE_DIR}/3part/log4cpp/lib)
#SET(LINK_DIR  /usr/local/lib)
  
include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(log4cpp)


# 查找当前目录下的所有源文件,并将名称保存到 DIR_SRCS 变量
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/myprj/source DIR_SRCS)

# 增加子文件夹，进入源代码文件夹继续构建
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/myprj)

