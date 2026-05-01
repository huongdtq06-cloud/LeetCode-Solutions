/**
 * Problem: 1768. Merge Strings Alternately
 * Link: https://leetcode.com/problems/merge-strings-alternately/
 * Difficulty: Easy
 * Topics: Two Pointers, String
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * Tư duy: Sử dụng kỹ thuật Two Pointers để duyệt qua cả hai chuỗi đồng thời.
     * Ở mỗi bước, lần lượt thêm ký tự từ word1 và word2 vào chuỗi kết quả.
     * Cuối cùng, nối phần còn dư của chuỗi dài hơn (nếu có).
     */
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int n1 = word1.length();
        int n2 = word2.length();
        int i = 0;

        // Duyệt đồng thời cả hai chuỗi cho đến khi một chuỗi hết
        while (i < n1 || i < n2) {
            if (i < n1) {
                res += word1[i];
            }
            if (i < n2) {
                res += word2[i];
            }
            i++;
        }

        return res;
    }
};

/**
 * Độ phức tạp (Complexity Analysis):
 * - Time Complexity: O(m + n), với m và n là độ dài của word1 và word2.
 *   Chúng ta duyệt qua mỗi ký tự của cả hai chuỗi đúng một lần.
 * - Space Complexity: O(m + n) để lưu trữ chuỗi kết quả.
 */