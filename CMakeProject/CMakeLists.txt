# CMakeList.txt : 最上位の CMake プロジェクト ファイル。グローバル構成を行います
# また、サブプロジェクトをここに含めます。
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

project ("CMakeProject")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
   # template.cpp
   # "Test/test.cpp"
   # "Practice/YokanParty.cpp"
 #"Practice/EncyclopediaOfParentheses.cpp"
 #"Practice/LongestCircular.cpp"
 #"Practice/CrossSum.cpp" 
 #"ABC275/A.cpp" 
 #"ABC275/B.cpp" 
 "ABC275/C.cpp" 
 #"ABC275/D.cpp" 
)