cmake_minimum_required(VERSION 3.22)
project(mini_kv CXX)

set(CMAKE_CXX_STANDARD 17)

# 如果用系统包
find_package(RocksDB REQUIRED)
find_package(httplib REQUIRED)   # Ubuntu 包名 libhttplib-dev

add_executable(mini_kv src/main.cpp)
target_link_libraries(mini_kv RocksDB::rocksdb httplib::httplib)

# 如果用 third_party 源码
# target_link_libraries(mini_kv rocksdb httplib)