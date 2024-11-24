cmake_minimum_required(VERSION 3.10)

# 設定專案名稱和語言
project(Clock
    VERSION 1.0
    DESCRIPTION "An analog clock generator"
    LANGUAGES CXX)

# 設定 C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OpenCV 手動設定路徑 (根據你的情況修改)
set(OpenCV_INCLUDE_DIRS "/opt/homebrew/Cellar/opencv/4.10.0_12/include/opencv4")
set(OpenCV_LIBS "/opt/homebrew/Cellar/opencv/4.10.0_12/lib/libopencv_core.dylib"
                "/opt/homebrew/Cellar/opencv/4.10.0_12/lib/libopencv_imgproc.dylib"
                "/opt/homebrew/Cellar/opencv/4.10.0_12/lib/libopencv_highgui.dylib"
                "/opt/homebrew/Cellar/opencv/4.10.0_12/lib/libopencv_imgcodecs.dylib")

# 如果需要 CMake 找不到 OpenCV，這裡手動指定
if(NOT EXISTS ${OpenCV_INCLUDE_DIRS})
    message(FATAL_ERROR "OpenCV include directory not found!")
endif()

# 顯示 OpenCV 版本資訊（方便除錯）
message(STATUS "OpenCV include dir: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")

# 添加執行檔
add_executable(clock clock.cpp)

# 設定包含目錄
target_include_directories(clock PRIVATE ${OpenCV_INCLUDE_DIRS})

# 連結 OpenCV 函式庫
target_link_libraries(clock PRIVATE ${OpenCV_LIBS})

# 設定編譯選項
if(MSVC)
    # Windows 的特殊編譯選項
    target_compile_options(clock PRIVATE /W4)
else()
    # Unix-like 系統的編譯選項
    target_compile_options(clock PRIVATE -Wall -Wextra)
endif()

# 設定輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 安裝規則（可選）
install(TARGETS clock
    RUNTIME DESTINATION bin)
