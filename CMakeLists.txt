# CMake 最低版本要求
cmake_minimum_required(VERSION 3.21)

# 项目信息
project(MyWebServer)

# 设置c++版本
set(CMAKE_CXX_STANDARD 14)

# 设置编译为debug 和 release
# set(CMAKE_BUILD_TYPE Debug|Release|MinSizeRel|RelWithDebInfo)

## 指定编译32bit或64bit程序
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")

# 设置变量path
set(path src/buffer src/http src/log src/pool src/server src/timer)



# 查找 src 目录下的所有源文件并将名称保存到 DIR_SRCS 变量
aux_source_directory(src DIR_SRCS)


## 通过cmake打印能获取的所有环境变量
#execute_process(
#        COMMAND ${CMAKE_COMMAND} -E environment
#)


# 添加需要编译的子目录
#add_subdirectory()

# 添加寻找头文件的目录
include_directories(${path})

#link_directories(${PROJECT_SOURCE_DIR}/lib)

# 显示当前目录包含文件

#message(${PROJECT_SOURCE_DIR})
#message("include_dirs = ${DIR_SRCS}")
message("${CMAKE_SYSTEM_NAME}")


# 生成可执行文件
add_executable(MyWebServer ${DIR_SRCS})

# 链接静态函数库
target_link_libraries(MyWebServer pthread mysqlclient)