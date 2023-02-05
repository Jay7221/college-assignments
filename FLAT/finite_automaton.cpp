#include<bits/stdc++.h>
using namespace std;
class Machine 
{
	public:
		int numStates;
		int alphabetSize;
		map<char, int> alphabet;
		vector<vector<int>> nextState;
		int initialState = 0;
		vector<bool> isFinal;
		Machine(int numStates, vector<char> alphabet, vector<tuple<int, char, int>> trans, int initialState, vector<int> finalStates)
		{
			this -> numStates = numStates;
			int alphabetSize = alphabet.size();
			for(int i = 0; i < alphabetSize; ++i)
			{
				this -> alphabet[alphabet[i]] = i;
			}
			nextState = vector<vector<int>>(numStates, vector<int>(alphabetSize, -1));
			for(auto [prevState, ch, nxt] : trans)
			{
				int symbol = this -> alphabet[ch];
				nextState[prevState][symbol] = nxt;
			}
			this -> initialState = initialState;
			isFinal = vector<bool>(numStates);
			for(int state : finalStates)
			{
				isFinal[state] = true;
			}
		}
		bool isValid(string s)
		{
			int curState = initialState;
			for(char ch : s)
			{
				int symbol = alphabet[ch];
				curState = nextState[curState][symbol];
				if(curState == -1)
				{
					return false;
				}
			}
			return isFinal[curState];
		}
};
int main()
{
	vector<tuple<int, char, int>> trans = {{0, '0', 0}, {0, '1', 1}, {1, '1', 1}, {1, '0', 2}, {2, '0', 1}, {2, '1', 1}};
	Machine M1(3, {'0', '1'}, trans,  0, {1});
	vector<string> v = {"001", "1001", "10"};
	for(string word : v)
	{
		cout << word << " : " << M1.isValid(word) << endl;
	}
	cout << "Enter number of strings : ";
	int n;
	cin >> n;
	while(n--)
	{
		cout << "Enter word : ";
		string s;
		cin >> s;
		if(M1.isValid(s))
		{
			cout << "Word is in language L(M1)" << endl;
		}
		else
		{
			cout << "Word is not in language L(M1)" << endl;
		}
	}
	return 0;
}
