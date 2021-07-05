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
    int length;
    ListNode *head;
    
    int getLength(ListNode *head)
    {
        int cnt = 0;
        
        while(head != NULL)
        {
            head = head->next;
            cnt++;
        }
        
        return cnt;
    }
    
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    {
        this->head = head;
        length = getLength(head);
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int index = rand() % length;
        
        ListNode *node = head;
        
        for(int i=0; i<index; i++)
            node = node->next;
        
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */