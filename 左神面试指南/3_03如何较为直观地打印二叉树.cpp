//class PrintTree
//{
//public:
//	void Print(Node* root)
//	{
//		cout << "The shape of tree is: " << endl;
//		cout << "=============================================================" << endl;
//		PrintShape(root, 0, "H", 17);
//		cout << "=============================================================" << endl;
//	}
//	void PrintShape(Node* root, int h, string c, int len)
//	{
//		if (root)
//		{
//			PrintShape(root->rchild, h + 1, "v", len);
//			string val;
//			stringstream ss;
//			ss << root->val;
//			ss >> val;
//			val = c + val + c;
//			int lenM = val.length();
//			int lenL = (len - lenM) / 2;
//			int lenR = len - lenM - lenL;
//			val = getSpace(lenL) + val + getSpace(lenR);
//			cout << getSpace(h*len) + val << endl;
//			PrintShape(root->lchild, h + 1, "^", len);
//		}
//
//	}
//	string getSpace(int num)
//	{
//		string space = " ";
//		for (int i = 0; i < num; ++i)
//			space.append(" ");
//		return space;
//	}
//};