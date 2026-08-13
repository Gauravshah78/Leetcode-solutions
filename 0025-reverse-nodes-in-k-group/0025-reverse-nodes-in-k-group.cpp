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
#define node ListNode
#define data val
#define ed endl
#define null NULL

    void reverse(node* head, int times) {
        node* curr = head;
        node* prev = null;
        while (times--) {
            node* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == null)
            return null;

        node* left = head;
        node* right;
        node* res = null;
        node* prevleft = null;
        int size = k;
        while (true) {
            right = left;
            for (int i = 0; i < size - 1; i++) {

                if (right == null)
                    break;

                right = right->next;
            }

            if (right) {
                node* nextleft = right->next;
                reverse(left, size);

                if (prevleft)
                    prevleft->next = right;
                if (res == null)
                    res = right;

                prevleft = left;
                left = nextleft;
            } else {
                if (prevleft)
                    prevleft->next = left;
                if (res == null)
                    res = left;
                break;
            }
        }
        return res;
    }
};