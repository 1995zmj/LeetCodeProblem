#include "Solution.h"

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	map<int, int> a;
	vector<int> b(2, -1);
	for (int i = 0; i < nums.size(); i++)
	{
		if (a.count(target - nums[i]) > 0)
		{
			b[0] = a[target - nums[i]];
			b[1] = i;
			break;
		}
		a[nums[i]] = i;
	}
	return b;
}

bool Solution::isPalindrome(int x)
{
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;

	int rev = 0;

	while (x > rev)
	{
		if (rev == x / 10)
			return true;

		int pop = x % 10;
		x /= 10;
		rev = rev * 10 + pop;
	}
	return x == rev || x == rev / 10;
}

int Solution::romanToInt(string s)
{
	map<char, int> roman = {
		{'I',1},
		{'V',5},
		{'X',10},
		{'L',50},
		{'C',100},
		{'D',500},
		{'M',1000},
	};
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i == s.length() - 1)
		{
			result += roman[s[i]];
			break;
		}
		if (roman[s[i]] >= roman[s[i + 1]])
		{
			result += roman[s[i]];
		}
		else
		{
			result += (roman[s[i + 1]] - roman[s[i]]);
			i++;
		}
	}

	return result;
}
