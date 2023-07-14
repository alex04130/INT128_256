cmake_minimum_required(VERSION 3.10)
project(pj1)

set(CMAKE_CXX_STANDARD 20)

# 添加源文件
file(GLOB SOURCES "src/*.cpp")

# 添加头文件路径
include_directories(include)

# 编译生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接库文件
# target_link_libraries(${PROJECT_NAME} your_library)

# 输出文件夹
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)