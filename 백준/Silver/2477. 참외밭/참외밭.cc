#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int k;
	cin >> k;
	
	vector<int> arr(6);
	vector<bool> maxFlag(6);
	for (int i = 0; i < 6; i++)
	{
		int tmp;
		cin >> tmp>> arr[i];
	}

	int max1 = 0, max2 = 0; // 제일 큰 너비, 높이 구하기
	int idx1, idx2;
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			if (max1 < arr[i])
			{
				max1 = arr[i];
				idx1 = i;
			}
		}
		else
		{
			if (max2 < arr[i])
			{
				max2 = arr[i];
				idx2 = i;
			}
		}
	}

	maxFlag[idx1] = 1;
	maxFlag[idx2] = 1;

	int minus = 1;

	for (int i = 0; i < 6; i++)
	{
		if (maxFlag[i] == 1) continue;
		if (i == 0)
		{
			if ((maxFlag[i + 1] | maxFlag[5]) == 0) minus *= arr[i];
		}
		else if (i == 5)
		{
			if ((maxFlag[0] | maxFlag[i - 1]) == 0) minus *= arr[i];
		}
		else
		{
			if ((maxFlag[i - 1] | maxFlag[i + 1]) == 0) minus *= arr[i];
		}
	}
	

	cout << (max1 * max2 - minus)*k << endl;

}