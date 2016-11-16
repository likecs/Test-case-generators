//Below code is used to generate undirected unweighted tree

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 20;

vector<int> adj[lim_n+1];
int visited[lim_n+1];

//check whether the graph is connected or not
void check_graph(int n) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
			if (!visited[*it]) {
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	
	bool connected = true;
	for(int i=1; i<=n; ++i) {
		connected &= visited[i];
	}

	assert(connected);
}


//Output is space separated vertices pairs which contain an edge
//There is extra line after every test case
void generate_unweighted_tree(int n, LL low, LL high) {
	LL mod = (high - low + 1);
	LL displace = low;

	set< pair<int,int> > duplicates;
	vector< pair<int,int> > perm;
	for(int i=2; i<=n; ++i) {
		int x = i;
		int y = rand() % (i - 1) + 1;
		if (i % 10 == 0) {
			swap(x, y);
		}
		assert (1 <= x <= n);
		assert (1 <= y <= n);
		if (duplicates.find(make_pair(x, y)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		if (duplicates.find(make_pair(y, x)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		duplicates.insert(make_pair(x, y));
		adj[x].push_back(y);
		adj[y].push_back(x);
		perm.push_back(make_pair(x, y));
	}

	random_shuffle(perm.begin(), perm.end());

	for(int i=0; i<n-1; ++i) {
		LL weight = rand() % mod + displace;
		assert(low <= weight <= high);
		printf("%d %d %lld\n", perm[i].first, perm[i].second, weight);
	}

	//check whether the graph made is connected or not
	check_graph(n);
	
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
	
		//set the limits on the range of edges weights
		//works even with negative numbers
		LL range_low = 1;
		LL range_high = 1e7;
		generate_unweighted_tree(n, range_low, range_high);
	}

	return 0;
}