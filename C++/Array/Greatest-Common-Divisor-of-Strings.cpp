/**
 * Problem: 1071. Greatest Common Divisor of Strings
 * Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/
 * Difficulty: Easy
 * Topics: String, Math
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Tư duy: Sử dụng phương pháp tương tự thuật toán Euclid để tìm GCD của hai chuỗi.
     * Liên tục xóa chuỗi ngắn hơn khỏi chuỗi dài hơn nếu chuỗi dài bắt đầu bằng chuỗi ngắn.
     * Quá trình lặp lại cho đến khi chuỗi dài trở nên rỗng hoặc không thể khớp được nữa.
     */
    string gcdOfStrings(string str1, string str2) {
        string longer = str1;
        string shorter = str2;

        while (longer != "") {
            // Đảm bảo 'longer' luôn là chuỗi có độ dài lớn hơn
            if (longer.length() < shorter.length()) {
                swap(longer, shorter);
            }

            // Kiểm tra xem chuỗi 'longer' có bắt đầu bằng 'shorter' không
            int index = longer.find(shorter);
            if (index != 0) {
                return "";
            } else {
                // Tương tự phép trừ trong thuật toán Euclid
                longer = longer.substr(shorter.length());
            }
        }

        return shorter;
    }
};

/**
 * Phân tích độ phức tạp (Complexity Analysis):
 * - Time Complexity: O(N^2) trong trường hợp xấu nhất do hàm substr và find bên trong vòng lặp,
 *   với N là tổng độ dài của hai chuỗi.
 * - Space Complexity: O(N) để lưu trữ các chuỗi tạm (longer, shorter).
 */