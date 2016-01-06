#pragma once
#define SOQUE_HEADER

#include<deque>
using namespace std;

template <typename _type> class soque
{
private:
	deque<_type> stc;
public:
	void push(_type val)
	{
		if (stc.empty()) stc.push_back(val);
		else
		{
		//Binary Search
			int m, L = 0, R = stc.size() - 1;
			while (L <= R)
			{
				m = (L + R) / 2;
				if (stc[m] == val || L == R) break;
				if (stc[m] < val) L = m + 1;
				if (stc[m] > val) R = m - 1;
			}
			if (stc[m] < val) m++;
			stc.insert(stc.begin() + m, val);
		}
	}
	void erase(int tar)
	{
		if (tar >= 0 && tar < stc.size())
		{
			stc.erase(stc.begin() + tar);
		}
	}
	_type& operator[] (const int index)
	{
		return stc[index];
	}
	unsigned int size()
	{
		return stc.size();
	}
};
