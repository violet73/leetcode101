#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> set;
        vector<int> res;
        for(auto i : nums1) {
            set.insert({i, 0});
        }

        for(auto i : nums2) {
            if(set.find(i) != set.end()) {
                set[i]++;
                if(set[i] == 1)
                    res.push_back(i);
            }
        }

        return res;
    }
};

int main() {



    return 0;
}