# 類比時鐘生成器 Analog Clock Generator

這個程式能夠生成一個類比時鐘的圖像，並可進行旋轉和翻轉操作。
This program generates an analog clock image with rotation and flip capabilities.

## 功能特點 Features

- 生成高品質的類比時鐘圖像 Generate high-quality analog clock images
- 可自定義時間顯示 Customizable time display
- 支援 90 度旋轉 Supports 90-degree rotation
- 支援水平翻轉 Supports horizontal flipping
- 自動保存圖像 Automatic image saving

## 系統需求 System Requirements

- OpenCV 4.x
- C++ 編譯器 C++ Compiler
- CMake 3.x

## 安裝步驟 Installation

### Windows

1. 安裝 OpenCV Install OpenCV
   - 下載 OpenCV Download OpenCV: https://opencv.org/releases/
   - 執行安裝檔 Run installer
   - 設置環境變數 Set environment variables:
     ```
     OPENCV_DIR = C:\opencv\build
     PATH += %OPENCV_DIR%\x64\vc16\bin
     ```

2. 安裝 Visual Studio Install Visual Studio
   - 包含 C++ 開發工具 Include C++ development tools
   
3. 使用命令提示字元編譯 Compile using Command Prompt
   ```cmd
   mkdir build
   cd build
   cmake -G "Visual Studio 17 2022" ..
   cmake --build . --config Release
   ```

### macOS

1. 使用 Homebrew 安裝 OpenCV Install OpenCV using Homebrew
   ```bash
   brew install opencv
   ```

2. 編譯專案 Compile project
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

### Linux (Ubuntu/Debian)

1. 安裝 OpenCV Install OpenCV
   ```bash
   sudo apt-get update
   sudo apt-get install libopencv-dev
   ```

2. 編譯專案 Compile project
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## 使用方法 Usage

### Windows
```cmd
cd build\Release
analog_clock.exe
```

### macOS/Linux
```bash
cd build
./analog_clock
```

接著輸入時間（格式：時 分 秒）
Then enter time (format: hour minute second)
```
請輸入時間 (格式: hh mm ss): 10 30 45
```

## 常見問題解決 Common Issues

### Windows
- 如果出現 "無法找到 OpenCV_DIR" If "OpenCV_DIR not found" appears
  ```cmd
  cmake -D OpenCV_DIR=C:\opencv\build ..
  ```
- DLL 錯誤 DLL errors
  - 確保環境變數正確設置 Ensure environment variables are set correctly
  - 檢查 OpenCV bin 目錄是否在 PATH 中 Check if OpenCV bin directory is in PATH

### macOS
- 如果 OpenCV 找不到 If OpenCV not found
  ```bash
  cmake -D OpenCV_DIR=/usr/local/Cellar/opencv/[version]/lib/cmake/opencv4 ..
  ```
- 權限問題 Permission issues
  ```bash
  chmod +x analog_clock
  ```

## 輸出文件 Output Files

- `analog_clock_rotated_flipped.png`：最終生成的圖像 Final generated image

## 程式架構 Program Structure

```
calcHandPosition(): 計算指針位置 Calculate hand position
main():
    - 初始化畫布 Initialize canvas
    - 繪製時鐘外框 Draw clock frame
    - 繪製刻度 Draw time markers
    - 繪製指針 Draw clock hands
    - 圖像處理 Image processing
    - 儲存結果 Save result
```

## 開發環境建議 Recommended Development Environments

### Windows
- Visual Studio 2019/2022
- Windows Terminal
- Git Bash

### macOS
- Xcode Command Line Tools
- Terminal.app 或 iTerm2
- VS Code

## 開發者說明 Developer Notes

- 使用 OpenCV 的 `rotate()` 函數進行旋轉
  Using OpenCV's `rotate()` function for rotation
- 使用 OpenCV 的 `flip()` 函數進行翻轉
  Using OpenCV's `flip()` function for flipping
- 所有圖像操作都使用 OpenCV Mat 物件
  All image operations use OpenCV Mat objects

## 注意事項 Notes

- 確保有足夠的磁碟空間儲存圖像
  Ensure sufficient disk space for saving images
- 程式執行時會覆蓋同名的輸出文件
  Output files with the same name will be overwritten
- 按任意鍵關閉圖像視窗
  Press any key to close the image window

## 錯誤排除 Troubleshooting

1. 找不到編譯器 Compiler not found
   - Windows: 安裝 Visual Studio Install Visual Studio
   - macOS: 安裝 Xcode Command Line Tools Install Xcode Command Line Tools
     ```bash
     xcode-select --install
     ```

2. CMake 錯誤 CMake errors
   - 檢查 OpenCV 路徑 Check OpenCV path
   - 更新 CMake Update CMake
   - 清除 CMake 快取 Clear CMake cache:
     ```bash
     rm -rf build/*
     ```

## 授權協議 License

MIT License

## 聯絡方式 Contact

如有任何問題，請建立 Issue。
For any questions, please create an Issue.