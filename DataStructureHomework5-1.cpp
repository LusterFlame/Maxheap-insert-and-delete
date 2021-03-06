#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void CheckChange(vector<int> &v_input, int index);
void ReplaceValue(vector<int> &v_input);

int main()
{
	//Create Max Heap
	int temp = 0;
	string input;
	getline(cin, input);
	stringstream ss_input(input);
	vector<int> v_input;
	while(ss_input >> temp)
		v_input.push_back(temp);
	for(temp = v_input.size() - 1;temp >= 0;--temp)
		CheckChange(v_input, temp);

	ReplaceValue(v_input);
}

void CheckChange(vector<int> &v_input, int index)
{
	if(index * 2 + 2 < (int)v_input.size())
	{
		if(v_input[index * 2 + 1] > v_input[index * 2 + 2])
		{
			if(v_input[index * 2 + 1] > v_input[index])
			{
				v_input[index * 2 + 1] += v_input[index];
				v_input[index] = v_input[index * 2 + 1] - v_input[index];
				v_input[index * 2 + 1] -= v_input[index];

				CheckChange(v_input, index * 2 + 1);
			}
		}
		else
		{
			if(v_input[index * 2 + 2] > v_input[index])
			{
				v_input[index * 2 + 2] += v_input[index];
				v_input[index] = v_input[index * 2 + 2] - v_input[index];
				v_input[index * 2 + 2] -= v_input[index];

				CheckChange(v_input, index * 2 + 2);
			}
		}
	}
	else if(index * 2 + 1 < (int)v_input.size())
	{
		if(v_input[index * 2 + 1] > v_input[index])
			{
				v_input[index * 2 + 1] += v_input[index];
				v_input[index] = v_input[index * 2 + 1] - v_input[index];
				v_input[index * 2 + 1] -= v_input[index];

				CheckChange(v_input, index * 2 + 1);
			}
	}
}

void ReplaceValue(vector<int> &v_input)
{
	int index = 0, target, NewValue, temp;
	cin >> target >> NewValue;
	while(v_input[index] != target)
		++index;
	v_input[index] = NewValue;

	//Sort the tree
	for(temp = v_input.size() - 1;temp >= 0;--temp)
		CheckChange(v_input, temp);

	//Print result
	for(temp = 0;temp < (int)v_input.size();++temp)
		cout << v_input[temp] << " ";
}