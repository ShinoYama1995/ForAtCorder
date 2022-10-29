# CMakeList.txt : 最上位の CMake プロジェクト ファイル。グローバル構成を行います
# また、サブプロジェクトをここに含めます。
#
cmake_minimum_required (VERSION 3.8)

project ("CMakeProject")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
   # template.cpp
    "Test/test.cpp"
)