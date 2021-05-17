#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int *p1 = &numbers[0], *p2 = &numbers[len - 1];
        int left = 1, right = len;
        while(p1 != p2) {
            if(*p1 + *p2 == target) {
                return {left, right};
            }
            if(*p1 + *p2 < target) {
                p1++;
                left++;
            } else {
                p2--;
                right--;
            }
        }
        return {left, right};
    }
};

int main() {
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(4);
    numbers.push_back(9);
    Solution s;
    s.twoSum(numbers, 6);

    return 0;
}