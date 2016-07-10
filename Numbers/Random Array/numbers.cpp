//Below code is used to generate array filled with random numbers in specified range

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 100;

//Output is space separated numbers 
void generate_numbers(int n, LL x, LL y) {
	LL mod = (y - x + 1);
	LL displace = x;

	for(int i=1; i<=n; ++i) {
		LL number = ((LL)rand() * rand()) % mod + displace;
		assert(number >= x && number <= y);
		printf("%lld", number);
		if (i < n) {
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "w", stdout);
	#endif
	srand(unsigned(time(0)));

	int test_cases = 2;
	//Comment below line if not number of test cases is not ti be printed
	printf("%d\n", test_cases);
	
	for(int t=1; t<=test_cases; ++t) {
	
		//get random value of "n" between (1, lim_n)
		int n = rand() % lim_n + 1;
		//Comment below line if not needed
		printf("%d\n", n);
	
		//set the limits of the range array elements
		//works even with negative numbers
		LL range_low = (LL)1;
		LL range_high = (LL)1e7;
		generate_numbers(n, range_low, range_high);
	}

	return 0;
}