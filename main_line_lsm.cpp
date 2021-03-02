/**
 * @file main_line_lsm.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-02
 * 
 * @copyright Copyright (c) 2021
 * 直線近似
 */

#include <utility>
#include <vector>
#include <tuple>
#include <iostream>

std::tuple<double,double> get_line_with_lsm(
    const std::vector<std::pair<double,double>>& points, bool is_x_mode = true) {
    double x = 0;
    double y = 0;
    double sum_x = 0;
    double sum_xx = 0;
    double sum_xy = 0;
    double sum_y = 0;
    double num = 0;

    for (auto&& point : points) {
        if (x != -1 && y != -1) {
            if (is_x_mode) {
                x = point.first;
                y = point.second;
            } else {
                x = point.second;
                y = point.first;
            }
            sum_x += x;
            sum_y += y;
            sum_xx += x * x;
            sum_xy += x * y;
            num += 1;
        }
    }

    /*公式*/
    double a_numerator = num * sum_xy - sum_x * sum_y;
    double b_numerator = sum_xx * sum_y - sum_xy * sum_x;
    double denominator = num * sum_xx - sum_x * sum_x;
    double a = a_numerator / denominator;
    double b = b_numerator / denominator;

    return std::make_tuple(a, b);
}

int main(int argc, char** argv) {

    return 0;
}