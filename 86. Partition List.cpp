#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *before = new ListNode, *after = new ListNode;
        ListNode *tmp = head, *tmp1 = before, *tmp2 = after;
        while(tmp != nullptr) {
            if(tmp->val < x) {
                before->next = tmp;
                before = tmp;
            } else {
                after->next = tmp;
                after = tmp;
            }
            tmp = tmp->next;
        }
        before->next = tmp2->next;
        after->next = nullptr;
        return tmp1->next;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode;
    ListNode *tmp = head;
    int value;
    while(cin >> value) {
        tmp->val = value;
        tmp->next = new ListNode;
        tmp = tmp->next;
    }
    cin >> value;
    s.partition(head, value);

    return 0;
}