/**
 * Problem: 345. Reverse Vowels of a String
 * Link: https://leetcode.com/problems/reverse-vowels-of-a-string/
 * Difficulty: Easy
 * Topics: Two Pointers, String
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Tư duy: Dùng Two Pointers (i, j) duyệt từ hai đầu. 
    // Chỉ swap khi cả hai con trỏ đều dừng lại ở nguyên âm, con trỏ ở vị trí không phải nguyên âm sẽ tiếp tục di chuyển.
    bool isVowel(char c) {
        c = tolower(c);
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (j > i) {
            if (!isVowel(s[i])) {
                i++;
                continue;
            };
            if (!isVowel(s[j])) {
                j--;
                continue;
            };
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

/**
 * Phân tích độ phức tạp (Complexity Analysis):
 * - Time Complexity: O(n)
 *   Duyệt qua chuỗi một lần duy nhất bằng hai con trỏ chạy từ hai đầu.
 * - Space Complexity: O(1)
 *   Thực hiện đảo ngược trực tiếp trên chuỗi đầu vào (in-place), 
 *   không sử dụng thêm bộ nhớ phụ đáng kể.
 */