#头文件目录
INCLUDE_DIRECTORIES( ${LOG4CPP_INCLUDE} ${MINILOG_INCLUDE} ./include )

#目录源码路径
SET( SORT_SRC_DIR ./source )

#代码列表
FILE (GLOB SORT_FILES ${SORT_SRC_DIR}/*.cpp)

#依赖的LIB
SET(SORT_LIB ${LIB_LOG4CPP} ${LIB_PTHREAD} ${LIB_MINILOG})

#生成sort 
ADD_EXECUTABLE( sort1 ${SORT_FILES})

#连接生成相关库
TARGET_LINK_LIBRARIES( sort1 ${SORT_LIB} )
