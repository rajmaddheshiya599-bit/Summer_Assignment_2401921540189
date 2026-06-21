#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        vector<int> v;
        ListNode* temp = head;

        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }

        reverse(v.begin(), v.end());

        temp = head;
        int i = 0;

        while(temp != NULL){
            if(v[i] == temp->val){
                i++;
                temp = temp->next;
            }
            else{
                return false;
            }
        }

        return true;
    }
};