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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* size = head;
        int num = 0;
        while(size){
            num++;
            size = size->next;
        }
        
        if(num < k) return head;
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        
        for(int i=1; i<k; i++){
            p1 = first;
            first = first->next;
        }
        
        for(int j=1; j<num-k+1; j++){
            p2 = second;
            second = second->next;
        }
        
        if(p1){
            p1->next = second;
        }
        
        if(p2){
            p2->next = first;
        }
        
        ListNode* temp = second->next;
        second->next = first->next;
        first->next = temp;
        
        if(k==1) head = second;
        if(k == num) head = first;
        
        return head;
    }
};