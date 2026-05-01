/**
 * Problem: 151. Reverse Words in a String
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 * Difficulty: Medium
 * Topics: Two Pointers, String, Stack
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * Tư duy:
     * - Duyệt ngược: Chạy biến i từ cuối chuỗi về đầu để đảo thứ tự từ.
     * - Sử dụng Stack: Khi gặp ký tự khác khoảng trắng, đẩy vào stack để giữ đúng thứ tự các chữ cái trong một từ.
     * - Xử lý khoảng trắng: Khi gặp khoảng trắng hoặc đầu chuỗi (i == 0) mà stack không rỗng, lấy toàn bộ ký tự trong stack ra nối vào kết quả (res) và thêm dấu cách.
     * - Xử lý khoảng trắng thừa: Bỏ qua các khoảng trắng liên tiếp bằng lệnh continue và xóa dấu cách thừa ở cuối chuỗi kết quả trước khi trả về.
     */
    string reverseWords(string s) {
        int i = s.length() - 1;
        stack<char> st;
        string res;
        bool firstspace=false;
        while (i >= 0) {
            char c= s[i];
            if (s[i]!=' ')
                st.push(c);
                
            while ((c == ' '||i==0)   && !st.empty()) {
                res += st.top();
                st.pop();
                if(st.empty() )res += " "  ;                
            }
            if (c == ' ' && st.empty()){
                i--;
                continue;
            }
            i--;
        }
        if(res[res.length()-1]==' ') res.erase(res.length()-1,1);
        return res;
    }
};

/**
 * ĐỘ PHỨC TẠP:
 * - Time: O(n) - Duyệt qua chuỗi s một lần.
 * - Space: O(n) - Sử dụng stack và chuỗi kết quả để lưu trữ.
 */