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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head; 
        ListNode *p_head = head, *first = head, *tmp = first, *second = head->next;
        bool flg = false;
        while(second != nullptr) {
            if(first->val == second->val) {
                second = second->next;
                flg = true;
            } else {
                if(!flg) tmp = first;
                if(flg && first == p_head) {
                    head = second;
                }
                if(flg) {
                    tmp->next = second;
                    flg = false;
                }
                first = second;
                second = first->next;
            }
        }
        if(!flg) tmp = first;
        if(flg && first == p_head) {
            head = second;
        }
        if(flg) {
            tmp->next = second;
        }
        return head;
    }
};

int main() {


    return 0;
}