/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<int> st;
        ListNode *temp = head;  
        ListNode *cur = head;
        int cnt=0;
        while(cur != nullptr) { 
            cnt++;
            st.push(cur->val);
            if(cnt==k){
                while(!st.empty()){
                    temp->val=st.top();
                    st.pop();
                    temp=temp->next;
                }
                cnt=0;
            }
            cur = cur->next;
        }
       return head;
    }
};