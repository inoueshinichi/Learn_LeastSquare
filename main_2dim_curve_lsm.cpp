/**
 * @file main_2dim_curve_lsm.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-02
 * 
 * @copyright Copyright (c) 2021
 * 2次曲線近似
 */

#include <utility>
#include <vector>
#include <tuple>
#include <iostream>

std::tuple<double,double,double> get_2dim_curve_with_lsm(
    std::vector<std::pair<double,double>> points, bool is_x_mode = true) {
    
    double x = 0;
    double y = 0;
    double num = 0;
    double sum_x = 0;
    double sum_xx = 0;
    double sum_xxx = 0;
    double sum_xxxx = 0;
    double sum_xxy = 0;
    double sum_xy = 0;
    double sum_y = 0;

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
            sum_xxx += x * x * x;
            sum_xxxx += x * x * x * x;
            sum_xxy += x * x * y;
            sum_xy += x * y;
            num += 1;
        }
    }

    /*公式*/
    double a_numerator = num * sum_xx * sum_xxy - 
                         sum_x * sum_x * sum_xxy + 
                         sum_x * sum_xx * sum_xy -
                         num * sum_xxx * sum_xy + 
                         sum_x * sum_xxx * sum_y -
                         sum_xx * sum_xx * sum_y;
    double b_numerator = sum_x * sum_xx * sum_xxy -
                         num * sum_xxx * sum_xxy +
                         num * sum_xxxx * sum_xy -
                         sum_xx * sum_xx * sum_xy +
                         sum_xx * sum_xxx * sum_y -
                         sum_x * sum_xxxx * sum_y;
    double c_numerator = -sum_xx * sum_xx * sum_xxy +
                         sum_x * sum_xxx * sum_xxy -
                         sum_x * sum_xxxx * sum_xy +
                         sum_xx * sum_xxx * sum_xy -
                         sum_xxx * sum_xxx * sum_y +
                         sum_xx * sum_xxxx * sum_y;
    double denominator = 2 * sum_x * sum_xx * sum_xxx + 
                         num * sum_xx * sum_xxxx - 
                         sum_x * sum_xxxx * sum_xy +
                         sum_xx * sum_xxx * sum_xxx -
                         sum_xx * sum_xx * sum_xx;
    
    double a = a_numerator / denominator;
    double b = b_numerator / denominator;
    double c = c_numerator / denominator;
    return std::make_tuple(a, b, c);
}

int main(int, char**) {

    std::cout << "Hello, world!\n";
    return 0;
}
