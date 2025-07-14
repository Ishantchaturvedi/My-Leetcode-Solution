class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;  // Initialize result to store decimal value
        
        // Traverse the linked list from head to tail
        while (head != nullptr) {
            // Shift result left by 1 bit (multiply by 2) and add current bit
            result = result * 2 + head->val;
            
            // Move to the next node
            head = head->next;
        }
        
        return result;  // Return the final decimal value
    }
};