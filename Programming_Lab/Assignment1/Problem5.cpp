#include<iostream>
using namespace std;
bool is_vowel(char ch){
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	bool ans = false;
	for(int i = 0; i < 5; ++i){
		if(ch == vowels[i]){
			ans = true;
		}
	}
	return ans;
}
int main(){
	string s = "CPP is easy and great and Python is also great";
	int number_vowels = 0, number_consonants = 0;
	for(auto ch : s){
		if(is_vowel(ch)){
			++number_vowels;
		}else{
			++number_consonants;
		}
	}
	cout << "Number of vowels is : " << number_vowels << endl;
	cout << "Number of consonants is : " << number_consonants << endl;
}
