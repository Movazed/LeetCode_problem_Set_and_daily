#include<bits/stdc++.h>
using namespace std;
#define ll long long


// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    int pairSum(ListNode* head){
        int ans = 0;

        ListNode* newList  = NULL;
        ListNode* current = head;
        ListNode* currHalf = head;

        while(currHalf){
            currHalf = currHalf->next->next;
            ListNode* temp = current->next;
            current->next = newList;
            newList = current;
            current = temp;
        }

        while(current){
            ans = max(ans, (current->val + newList->val));
            current = current->next;
            newList = newList->next;
        }
        return ans;
    }
};