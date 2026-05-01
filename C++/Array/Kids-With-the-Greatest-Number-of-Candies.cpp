/**
 * Problem: 1431. Kids With the Greatest Number of Candies
 * Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
 * Difficulty: Easy
 * Topics: Array, Greedy
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max= candies[0];
        vector<bool> result;
        for (int u:candies){
            if(u>max)max=u;
        }
        for(int u:candies){
            if((u+extraCandies)>=max) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};

/**
 * Phân tích độ phức tạp (Complexity Analysis):
 * - Time Complexity: O(n)
 *   Thuật toán duyệt qua mảng candies hai lần độc lập (một lần tìm max, một lần so sánh).
 * - Space Complexity: O(n)
 *   Sử dụng một vector<bool> để lưu trữ kết quả trả về cho n đứa trẻ.
 */