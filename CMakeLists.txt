# CMake 最低版本要求
cmake_minimum_required(VERSION 3.21)

# 项目信息
project(MyWebServer)

# 设置c++版本
set(CMAKE_CXX_STANDARD 14)

# 查找 src 目录下的所有源文件并将名称保存到 DIR_SRCS 变量
aux_source_directory(src DIR_SRCS)

# 添加 子目录
add_subdirectory(src/buffer)
add_subdirectory(src/http)
add_subdirectory(src/log)
add_subdirectory(src/pool)
add_subdirectory(src/server)
add_subdirectory(src/timer)

message("include_dirs = ${DIR_SRCS}")
add_executable(MyWebServer ${DIR_SRCS})
target_link_libraries(MyWebServer Buffer Http Log Pool Server Timer)