bool hasCycle(struct ListNode *head) {
    if(head==NULL){return false;}
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while(fast && slow && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){return true;}
    }
    return false;
};
