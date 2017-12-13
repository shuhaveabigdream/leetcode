#include<iostream>
#include<string>
#include<conio.h>

using namespace::std;

int check(string s,int start,int end)
{
	int diff = end - start + 1;
	for (int i = start; i < end-1; i++)
	{
		for (int j = i + 1; j < end; j++)
		{
			if (s[i] == s[j])
			{
				if (j - start + 1 < diff)diff = j - start + 1;
			}
			else if (j == end - 1)
			{
				if (end - start + 1 < diff)diff = end - start + 1;
			}
		}
	}
	return diff;
}

int find(string s)
{
	int lenth=s.length();
	int diff = 0;
	for (int i = 0; i < lenth-1; i++)
	{
		for (int j = i + 1; j < lenth; j++)
		{
			int temp = 0;
			if (s[i] == s[j])//两个字符相同
			{
				if (i == j - 1)temp = 1;
				else temp=check(s, i, j-1);
				if (temp > diff)diff = temp;
				break;
			}
			else if (j == lenth-1)//整个字符串均不出现该字符的重复
			{
				if (i == j - 1)temp = 2;
				else temp = check(s, i, lenth - 1);
				if (temp>diff)diff = temp;
			}
		}
	}
	return diff;
}

void findarry(int*s,int lenth)
{
	for (int i = 0; i < lenth - 2; i++)
		for (int j = i + 1; j < lenth - 1; j++)
			for (int m = j + 1; m < lenth; m++)
			{
				if (s[i] + s[j] + s[m] == 0)
				{
					cout << "find arry:" << s[i] << " " << s[j] << " " << s[m] << endl;
				}
			}
}

int main()
{
	string x = "aabqfnwoqwf";
	cout << "max_sub:" << find(x) << endl;
	int test[10] = { 1, 0, 2, 3, -1,-1,-7, 4, 8, -4};
	findarry(test, 10);
	_getch();
}