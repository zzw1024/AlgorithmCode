#include <iostream>
#include <vector>

#define JH(a,b,t) t=a;a=b;b=t;

using namespace std;
#define MeetN 10




struct Meet
{
	int No;
	int TimeBeg;
	int TimeEnd;
};

void SortTime(Meet (&meet)[MeetN])
{
	for (int i = 0; i < MeetN - 1; ++i)
	{
		for (int j = i+1; j < MeetN; ++j)
		{
			if (meet[i].TimeEnd > meet[j].TimeEnd ||
				meet[i].TimeEnd == meet[j].TimeEnd && meet[i].TimeBeg < meet[j].TimeBeg)
			{
				Meet Temp = meet[i];
				meet[i] = meet[j];
				meet[j] = Temp;
			}
		}
	}
}

void Tan1()
{
	Meet meet[MeetN];
	vector<int>v = { 3,6,1,4,5,7,2,5,5,9,3,8,8,11,6,10,8,12,12,14 };

	for (int i = 0; i < MeetN; ++i)
	{
		meet[i].No = i+1;
		meet[i].TimeBeg = v[2 * i];
		meet[i].TimeEnd = v[2 * i + 1];
	}

	SortTime(meet);

	cout << "选择的会议为： " << endl;
	int ChooseNo = 0;
	cout << meet[ChooseNo].No << "  ";
	for (int i = 1; i < MeetN; ++i)
	{
		int StartEnd = meet[ChooseNo].TimeEnd;
		if (meet[i].TimeBeg >= StartEnd)
		{
			ChooseNo = i;
			cout << meet[ChooseNo].No << "  ";
		}
	}
}
