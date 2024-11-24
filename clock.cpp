#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>

#define PI 3.14159265358979323846

using namespace cv;
using namespace std;

// 計算指針的終點
Point calcHandPosition(Point center, double length, double angle) {
    return Point(center.x + length * cos(angle), center.y - length * sin(angle));
}

int main() {
    // 畫布大小與中心點
    const int width = 600, height = 600;
    Mat clockImage = Mat::zeros(height, width, CV_8UC3);
    clockImage.setTo(Scalar(255, 255, 255)); // 背景填充白色
    Point center(width / 2, height / 2);
    int radius = 250;

    // 畫錶盤
    circle(clockImage, center, radius, Scalar(0, 0, 0), 3);

    // 畫時鐘刻度
    for (int i = 0; i < 60; ++i) {
        double angle = i * 6 * PI / 180.0; // 每 6 度為一刻度
        Point outer = calcHandPosition(center, radius, angle);
        Point inner = calcHandPosition(center, (i % 5 == 0) ? radius - 20 : radius - 10, angle);
        line(clockImage, outer, inner, Scalar(0, 0, 0), (i % 5 == 0) ? 2 : 1);
    }

    // 使用者輸入時間
    int hour, minute, second;
    cout << "請輸入時間 (格式: hh mm ss): ";
    cin >> hour >> minute >> second;

    // 計算指針角度
    double hourAngle = ((hour % 12) + minute / 60.0) * 30 * PI / 180.0;
    double minuteAngle = (minute + second / 60.0) * 6 * PI / 180.0;
    double secondAngle = second * 6 * PI / 180.0;

    // 畫指針
    line(clockImage, center, calcHandPosition(center, radius * 0.5, hourAngle), Scalar(0, 0, 255), 6);  // 時針
    line(clockImage, center, calcHandPosition(center, radius * 0.7, minuteAngle), Scalar(0, 255, 0), 4); // 分針
    line(clockImage, center, calcHandPosition(center, radius * 0.9, secondAngle), Scalar(255, 0, 0), 2); // 秒針

    // 旋轉影像 90 度順時針
    Mat rotatedImage;
    rotate(clockImage, rotatedImage, ROTATE_90_COUNTERCLOCKWISE);

    // 水平翻轉影像（左右翻轉）
    Mat flippedImage;
    flip(rotatedImage, flippedImage, 1);  // 1 表示水平翻轉

    // 顯示與儲存影像
    imshow("Analog Clock (Rotated & Flipped)", flippedImage);
    imwrite("analog_clock_rotated_flipped.png", flippedImage);
    waitKey(0);

    return 0;
}