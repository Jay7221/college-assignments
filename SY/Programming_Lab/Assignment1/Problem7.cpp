#include<iostream>
#include<string.h>
using namespace std;
int to_int(string s, int k){
	int n = 0;
	for(int i = 0; i < s.size(); ++i){
		n *= k;
		if(s[i] >= 'a'){
			n += s[i] - 'a' + 10;
		}else{
			n += s[i] - '0';
		}
	}
	return n;
}
string to_string(int n, int k){
	string s;
	while(n){
		if(n % k < 10){
			s.push_back('0' + (n % k));
		}else{
			s.push_back('a' + (n % k) - 10);
		}
		n /= k;
	}
	for(int i = 0; i < s.size() / 2; ++i){
		char tmp = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = s[i];
		s[i] = tmp;
	}
	return s;
}
int main(){
	cout << "Enter " << endl;
	cout << "1. Binary to Octal" << endl;
	cout << "2. Octal to Binary" << endl;
	cout << "3. Binary to Hexadecimal" << endl;
	cout << "4. Hexadecimal to Binary" << endl;
	cout << "5. Octal to Hexadecimal" << endl;
	cout << "6. Hexadecimal to Octal" << endl;
	int p, n, m;
	cin >> p;
	switch(p){
		case 1:
			n = 2, m = 8;
			break ;
		case 2:
			n = 8, m = 2;
			break ;
		case 3:
			n = 2, m = 16;
			break;
		case 4:
			n = 16, m = 2;
			break ;
		case 5:
			n = 8, m = 16;
			break;
		case 6:
			n = 16, m = 8;
			break;
	}
	string s;
	cin >> s;
	for(auto c : s){
		if(c >= 'a')
			c = '0' + (c - 'a');
	}
	s = to_string(to_int(s, n), m);
	cout << s << endl;
	return 0;
}

	
