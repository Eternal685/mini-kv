cmake_minimum_required(VERSION 3.22)
project(mini_kv CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # 后续第三方库都会放在这里
# add_subdirectory(third_party)

# 主程序
add_executable(mini_kv src/main.cpp)