# 该指令必须在最顶部; 要求CMake版本不低于 3.10
cmake_minimum_required(VERSION 3.10)

# 生成 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# @顺序：`cmake_minimum_required()` → `project()` → 其他代码
project(MyProjectxxxx LANGUAGES C CXX)
    # MyProjectxxxx 是逻辑项目名称, 并无实际意义
    # ${PROJECT_NAME} 是 CMake 变量, 表示项目名称
    # LANGUAGE 指定项目语言 C CXX 表示该项目支持 C 和 C++ 语言
    # ${PROJECT_SOURCE_DIR} 是 CMake 变量, 表示项目根目录
    # ${PROJECT_BINARY_DIR} 是 CMake 变量, 表示构建目录
# !@顺序：`cmake_minimum_required()` → `project()` → 其他代码

# @指定 语言 标准
    # 全局变量，必须写在 `project()` 之后，add_executable /add_library 之前
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)   # 配套常用，很多人漏掉
#set(CMAKE_C_STANDARD 99)                # C语言版本：90 / 99 / 11 / 17
#set(CMAKE_C_STANDARD_REQUIRED ON)       # 强制该C标准，不支持则报错
#set(CMAKE_C_EXTENSIONS OFF)             # 关闭编译器GNU扩展，跨平台
# !@指定 语言 标准

# @指定 可执行文件
add_executable(MyEXExxxx
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/src/selectionSort.cpp
    ${PROJECT_SOURCE_DIR}/src/insertSort.cpp
    ${PROJECT_SOURCE_DIR}/src/shellsort.cpp
)
# !@指定 可执行文件

# @头文件路径
target_include_directories(MyEXExxxx
    PRIVATE                                                                     
        ${PROJECT_SOURCE_DIR}/include
        # ${PROJRECT_SOURCE_DIR}/third_party/include
)
# !@头文件路径

## -----------------------------------------------------------------@额外补充---------------------------------------------------------------- ##

# @链接 库文件
# # ①: 设置 库 的搜索目录
# target_link_directories(MyEXExxxx
#     PRIVATE
#         ${PROJECT_SOURCE_DIR}/third_party/lib
# )
# # ②: 指定链接库的名字 不需要写libxxx.so / xxx.lib全名
# target_link_libraries(MyEXExxxx
#     PRIVATE
#         libxx
#         libxxxx
# )
# !@链接 库文件

# @生成库文件
# add_library(MyLibxxxx STATIC/SHARED                                             # STATIC 生成静态库 ;SHARED 生成动态库
#     ${PROJECT_SOURCE_DIR}/src/x1.cpp
#     ${PROJECT_SOURCE_DIR}/srcxx/x2.cpp
# )
# target_include_directories(Mylibxxxx
#     PUBLIC
#         ${PROJECT_SOURCE_DIR}/include
# )
# !@生成库文件
## -----------------------------------------------------------------!@额外补充---------------------------------------------------------------- ##

## -----------------------------------------------------------------@构建步骤----------------------------------------------------------------- ##
# 1. 创建 `CMakLists.txt`
# 	- 在 MyProject **根目录**下创建 CMakeLists.txt 文件，
# 	- 这是整个CMake构建的**起点**
# 	- 所有构建规则都定义在这个文件中.
# 2. 创建**构建目录**
# 	- `mdir build && cd build` 
# 	- 为了保持源代码目录的整洁，推荐使用 `Out-of-source` 构建方式——在项目根目录下创建一个独立的构建目录。
# 3. **配置**项目 
# 	- 在`build目录`中运行CMake配置: `cmake ..` (**到上层目录寻找CMakeLists.txt文件已经生成构建文件**)
# 		- `cmake -DCMAKE_BUILD_TYPE=Debug` -------**Debug版本**
# 		- `cmake -DCMAKE_BUILD_TYPE=Release` -------**Release版本**
# 		- 在构建目录中运行CMake, ==生成适合当前平台的构建系统文件==,如 Makefile
# 		- `..`: 指向包含 CMakeLists.txt 的源代码目录。
# 	- *或者*  `cmake -B build`(但不进去`build目录`下) ⭐⭐⭐⭐⭐⭐
# 		- `cmake -B build -DCMAKE_BUILD_TYPE=Debug` --------*Debug版本*
# 		- `cmake -B build -DCMAKE_BUILD_TYPE=Release` -------*Release版本* 
# 4. **编译**项目
# 	- ==构建文件==生成后, 使用对应的构建命令==编译项目==
# 	- 默认情况下 CMake 在类 Unix 系统上生成 Makefile，因此可以直接使用 make 命令。
# 		- `make`
# 		- 也可以使用跨平台的通用构建命令：`cmake --build ./build`
# 5. **运行**可执行文件
# 	- `./MyExecutable`
# 6. **清理**构建文件.
# 	- 清理操作会删除编译过程中生成的中间文件（.o 文件等）和目标文件，释放磁盘空间。
# 		- `make clean`
## -----------------------------------------------------------------!@构建步骤----------------------------------------------------------------- ##


