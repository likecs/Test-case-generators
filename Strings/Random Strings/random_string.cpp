//Below code is used to generate random strings consisting of either lowercase or uppercase letters

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 100;

//Output is space separated numbers 
void generate_strings_lowercase(int n) {
	int mod = 26;

	for(int i=1; i<=n; ++i) {
		int number = rand() % mod;
		assert(number >= 0 && number <= 25);
		char ch = number + 'a';
		printf("%c", ch);
	}
	printf("\n");
}

void generate_strings_uppercase(int n) {
	int mod = 26;

	for(int i=1; i<=n; ++i) {
		int number = rand() % mod;
		assert(number >= 0 && number <= 25);
		char ch = number + 'A';
		printf("%c", ch);
	}
	printf("\n");
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "w", stdout);
	#endif
	srand(unsigned(time(0)));

	int test_cases = 2;
	//Comment below line if not needed
	printf("%d\n", test_cases);
	
	for(int t=1; t<=test_cases; ++t) {
	
		//get random value of "n" between (1, lim_n)
		int n = rand() % lim_n + 1;
		//Comment below line if not needed
		printf("%d\n", n);
	
		//for generating strings consisting of only lowercase english alphabets
		generate_strings_lowercase(n);

		//for generating strings consisting of only uppercase english alphabets
		// generate_strings_uppercase(n);		
	}

	return 0;
}