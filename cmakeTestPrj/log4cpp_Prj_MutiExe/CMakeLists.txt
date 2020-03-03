CMAKE_MINIMUM_REQUIRED(VERSION 2.8)  # 设定版本
PROJECT(myprj) # 设定工程名
SET(CMAKE_CXX_COMPILER "g++")  # 设定编译器
 
# 设定可执行二进制文件的目录（最后生成的可执行文件放置的目录）
SET(EXECUTABLE_OUTPUT_PATH /home/log4cpp_Prj/deploy/)

SET(LOG4CPP_INCLUDE  ./3part/log4cpp/include)
SET(LOG4CPP_DIR ${PROJECT_SOURCE_DIR}/3part/log4cpp/lib)
SET(LIB_LOG4CPP log4cpp)
SET(LIB_PTHREAD pthread)

LINK_DIRECTORIES(${LOG4CPP_DIR})


SUBDIRS(
			./myprj/sort
			./myprj/process
)

