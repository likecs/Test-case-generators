//Below code is used to generate matrix filled with random numbers in specified range

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 10;
const int lim_m = 10;

//Each test is "not" separated by new line
void generate_matrix(int n, int m, LL x, LL y) {
	LL mod = (y - x + 1);
	LL displace = x;

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			LL number = ((LL)rand() * rand()) % mod + displace;
			assert(number >= x && number <= y);
			printf("%lld", number);
			if (j < m) {
				printf(" ");
			}
		}
		printf("\n");
	}	
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
		//get random value of "m" between (1, lim_m)
		int m = rand() % lim_m + 1;
		//Comment below line if not needed
		printf("%d %d\n", n, m);

		//set the limits of the range array elements
		//works even with negative numbers
		LL range_low = -(LL)10;
		LL range_high = (LL)10;
		generate_matrix(n, m, range_low, range_high);
	}

	return 0;
}