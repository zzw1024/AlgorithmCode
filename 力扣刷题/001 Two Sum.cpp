#include "000head.h"



vector<int> twoSum(vector<int>& nums, int target) {
	vector<int>v, v1, v2;
	if (nums.size() <= 0) {
		return v;
	}
	v1 = nums;
	int num1, num2, p1 = 0, p2 = 0, f = 0;
	for (int i = 0; i < nums.size(); ++i) {
		p1 = nums.size() - 1 - i;
		p2 = p1;
		num1 = v1.back();
		v1.pop_back();
		v2 = v1;
		for (int j = 0; j < v1.size(); ++j) {
			num2 = v2.back();
			p2 = p2 - 1;
			v2.pop_back();
			if ((num1 + num2) == target) {
				v.push_back(p2);
				v.push_back(p1);
				f = 1;
				break;
			}

		}

		if (f) {
			break;
		}


	}
	for (int i = 0; i < v.size(); ++i)
		v[i]++;
	return v;

}

int main()
{
    cout<<"sucessed!"<<endl;
    return 0;
}