//#include "000库函数.h"
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//方法一：
//就是使用快慢指针先判断链表长度，然后遍历该链表
//
//方法二：
//使用倒数正方向数即可的概念，
//使用双指针
//
//
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (head == nullptr || n < 1)return head;
//        int nums = 0;
//        ListNode* p, * q;
//        p = q = head;
//        while (q && q->next)
//        {
//            p = p->next;
//            q = q->next->next;
//            ++nums;
//        }
//        nums = q == nullptr ? (2 * nums) : (2 * nums + 1);
//        if (n == nums)return head->next;
//        p = head;
//        while (nums != n + 1)
//        {
//            p = p->next;
//            --nums;
//        }
//        p->next = p->next->next;
//        return head;
//    }
//};
//
//
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (!head || !head->next)return nullptr;
//        ListNode* p, * q;
//        p = q = head;
//        for (int i = 0; i < n; ++i) p = p->next;
//        if (!p)return head->next;
//        while (p->next)
//        {
//            p = p->next;;
//            q = q->next;
//        }
//        q->next = q->next->next;
//        return head;
//    }
//};
//
//int main()
//{
//    Solution s;
//    ListNode* head = new ListNode(1);
//    head->next = new ListNode(2);
//    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
//    head->next->next->next->next = new ListNode(5);
//    ListNode* p = s.removeNthFromEnd(head, 2);
//    while (p)
//    {
//        cout<< p->val << " ";
//        p = p->next;
//    }
//    return 0;
//}

