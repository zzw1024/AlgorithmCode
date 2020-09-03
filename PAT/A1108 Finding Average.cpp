////#include <iostream>
////#include <vector>
////using namespace std;
////#define inf 1000
////double sum = 0.0, number;
////int n, nums = 0;
////int main()
////{
////	cin >> n;
////	char str1[100], str2[100];
////	while (n--)
////	{
////		cin >> str1;
////		bool flag = true;
////		sscanf(str1, "%lf", &number);//将字符转换为浮点数值
////		sprintf(str2, "%0.2f", number);//按要求输出
////		for (int i = 0; str1[i] != '\0'&& flag; ++i)
////			if (str1[i] != str2[i])
////				flag = false;
////		if (!flag || number<-inf || number>inf)
////			cout << "ERROR: " << str1 << " is not a legal number" << endl;
////		else
////		{
////			nums++;
////			sum += number;
////		}
////	}
////	cout << "The average of " << nums << (nums == 1 ? " number is " : " numbers is ");
////	if (nums == 0)
////		cout << "Undefined" << endl;
////	else
////		printf("%0.2f\n", sum / nums);
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int n, nums = 0;
//	double number, res = 0.0;
//	char s1[1010], s2[1010];
//	cin >> n;
//	while (n--)
//	{
//		cin >> s1;
//		bool flag = true;
//		sscanf(s1, "%lf", &number);
//		sprintf(s2, "%.2f", number);		
//		for (int i = 0; s1[i] != '\0' && flag; ++i)
//			if (s1[i] != s2[i])
//				flag = false;
//		if (flag == false || number<-1000 ||number>1000)
//			cout << "ERROR: " << s1 << " is not a legal number" << endl;
//		else
//		{
//			nums++;
//			res += number;
//		}
//	}
//	if (nums == 0)
//		cout << "The average of 0 numbers is Undefined" << endl;
//	else
//		printf("The average of %d number%s is %.2f\n", nums, nums == 1 ? "" : "s", res / nums);
//	return 0;
//}


