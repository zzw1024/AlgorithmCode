
//
//
// struct ListNode {
//       int val;
//       struct ListNode *next;
//       ListNode(int x) :
//             val(x), next(NULL) {
//       }
// };
//
//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//		ListNode *p = head;
//		int nums = 0;
//		while (p != nullptr)
//		{
//			nums++;
//			p = p->next;
//		}
//		vector<int>res;
//		res.resize(nums);
//		p = head;
//		while (p != nullptr)
//		{
//			res[--nums] = p->val;
//			p = p->next;
//		}
//		return res;
//	}
//};
//
//int main()
//{
//
//}