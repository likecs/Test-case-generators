//Below code is used to generate undirected linear graoh

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 100005;

vector<int> adj[lim_n+1];
int visited[lim_n+1];

//check whether the graph is connected or not
//check also every vertex has only 2 vertices connected to it except leaves
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

	int one = 0, two = 0;
	for(int i=1; i<=n; ++i) {
		assert(0 < adj[i].size() <= 2);
		if (adj[i].size() == 1) {
			one += 1;
		}
		else {
			two += 1;
		}
	}

	assert(one == 2);
	assert(two == n-2);
}

//Output is space separated vertices pairs which contain an edge
//There is extra line after every test case
void generate_unweighted_linear(int n) {
	vector<int> perm;
	vector< pair<int,int> > graph;
	for(int i=1; i<n; ++i) {
		int x = i;
		int y = i + 1;
		if (i % 10 == 0) {
			swap(x, y);
		}
		graph.push_back(make_pair(x, y));
		perm.push_back(i);
	}
	perm.push_back(n);

	random_shuffle(perm.begin(), perm.end());
	random_shuffle(graph.begin(), graph.end());

	for(int i=0; i<n-1; ++i) {
		int x = perm[graph[i].first - 1];
		int y = perm[graph[i].second - 1];
		assert(1 <= x <= n);
		assert(1 <= y <= n);
		assert(x != y);
		printf("%d %d\n", x, y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	//check whether the graph made is connected or not
	check_graph(n);
	
	for(int i=1; i<=n; ++i) {
		adj[i].clear();
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
		printf("%d\n", n);
	
		generate_unweighted_linear(n);
	}

	return 0;
}