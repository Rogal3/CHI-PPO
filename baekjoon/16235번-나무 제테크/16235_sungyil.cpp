#include<iostream>
#include<vector>
using namespace std;
void prints();

int n;
int m;
int k;

int treeDelAge[11][11] = { 0, };

int ground[11][11];
int groundPower[11][11];

vector<vector<vector<int>>> tree;

int main() {
	int x, y, z;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> groundPower[i][j];
			ground[i][j] = 5;
		}
	}

	tree.assign(11, vector<vector<int>>(11));//vector<int>를 가지는 11*11개의 방


	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		tree[y][x].push_back(z);
		//이거 정렬해서 순서대로 넣어야함
		if (tree[y][x].size() != 0) {
			for (int j = 0; j < tree[y][x].size(); ++j) {
				if (tree[y][x][j] > z) {
					tree[y][x].insert(tree[y][x].begin() + j, z);
				}
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		//봄
		//여름
		for (int j = 1; j <= n; ++j) {
			for (int h = 1; h <= n; ++h) {
				if (tree[j][h].size() != 0) {
					int size = tree[j][h].size();
					int cnt = 0;
					for (int u = 0; u < size; ++u) {
						if (ground[j][h] >= tree[j][h][u]) {
							ground[j][h] = ground[j][h] - tree[j][h][u];
							tree[j][h][u]++;
						}
						else {
							treeDelAge[j][h] += tree[j][h][u];
							cnt++;
						}
					}
					tree[j][h].erase(tree[j][h].begin() + size - cnt, tree[j][h].end());
					ground[j][h] += treeDelAge[j][h] / 2;
					treeDelAge[j][h] = 0;
				}
				
			}
		 }
		
		//가을
		for (int j = 1; j <= n; ++j) {
			for (int h = 1; h <= n; ++h) {
				if (tree[j][h].size() != 0) {
					int cnt = 0;
					for (int u = 0; u < tree[j][h].size(); ++u) {
						if (tree[j][h][u] % 5 == 0) {
							cnt++;
						}
					}
					if (cnt != 0) {
						if (j - 1 > 0) {//왼쪽
							if (tree[j - 1][h].size() != 0) {
								for (int q = 0; q < cnt; ++q) {
									tree[j - 1][h].insert(tree[j-1][h].begin(), 1);
								}
							}
							else {
								tree[j - 1][h].push_back(1);
								for (int q = 1; q < cnt; ++q) {
									tree[j - 1][h].insert(tree[j-1][h].begin(), 1);
								}
							}

							if (h + 1 < n + 1) {//왼쪽아래 대각
								if (tree[j - 1][h+1].size() != 0) {
									for (int q = 0; q < cnt; ++q) {
										tree[j - 1][h+1].insert(tree[j-1][h+1].begin(), 1);
									}
								}
								else {
									tree[j - 1][h+1].push_back(1);
									for (int q = 1; q < cnt; ++q) {
										tree[j - 1][h+1].insert(tree[j-1][h+1].begin(), 1);
									}
								}
							}

							if (h - 1 > 0) {//왼쪽 위 대각
								if (tree[j - 1][h-1].size() != 0) {
									for (int q = 0; q < cnt; ++q) {
										tree[j - 1][h-1].insert(tree[j-1][h-1].begin(), 1);
									}
								}
								else {
									tree[j - 1][h-1].push_back(1);
									for (int q = 1; q < cnt; ++q) {
										tree[j - 1][h-1].insert(tree[j-1][h-1].begin(), 1);
									}
								}
							}
						}
						if (h-1 > 0) {//위쪽
							if (tree[j][h - 1].size() != 0) {
								for (int q = 0; q < cnt; ++q) {
									tree[j][h - 1].insert(tree[j][h - 1].begin(), 1);
								}
							}
							else {
								tree[j][h - 1].push_back(1);
								for (int q = 1; q < cnt; ++q) {
									tree[j][h-1].insert(tree[j][h - 1].begin(), 1);
								}
							}
						}
						if (j + 1 < n+1) {//오른쪽
							if (tree[j + 1][h].size() != 0) {
								for (int q = 0; q < cnt; ++q) {
									tree[j+1][h].insert(tree[j + 1][h].begin(), 1);
								}
							}
							else {
								tree[j+1][h ].push_back(1);
								for (int q = 1; q < cnt; ++q) {
									tree[j + 1][h].insert(tree[j + 1][h].begin(), 1);
								}
							}

							if (h + 1 < n + 1) {//오른쪽 아래대각
								if (tree[j + 1][h+1].size() != 0) {
									for (int q = 0; q < cnt; ++q) {
										tree[j + 1][h+1].insert(tree[j + 1][h+1].begin(), 1);
									}
								}
								else {
									tree[j + 1][h+1].push_back(1);
									for (int q = 1; q < cnt; ++q) {
										tree[j + 1][h+1].insert(tree[j + 1][h+1].begin(), 1);
									}
								}
							}

							if (h - 1 > 0) {//오른쪽 위 대각
								if (tree[j + 1][h-1].size() != 0) {
									for (int q = 0; q < cnt; ++q) {
										tree[j + 1][h-1].insert(tree[j + 1][h-1].begin(), 1);
									}
								}
								else {
									tree[j + 1][h-1].push_back(1);
									for (int q = 1; q < cnt; ++q) {
										tree[j + 1][h-1].insert(tree[j + 1][h-1].begin(), 1);
									}
								}
							}
						}
						if (h + 1 < n+1) {//오른쪽
							if (tree[j][h+1].size() != 0) {
								for (int q = 0; q < cnt; ++q) {
									tree[j][h+1].insert(tree[j][h+1].begin(), 1);
								}
							}
							else {
								tree[j][h+1].push_back(1);
								for (int q = 1; q < cnt; ++q) {
									tree[j][h + 1].insert(tree[j][h + 1].begin(), 1);
								}
							}
						}
					}
				}
			}
		}
		//겨울
		for (int j = 1; j <= n; ++j) {
			for (int h = 1; h <= n; ++h) {
				ground[j][h] += groundPower[j][h];
			}
		}
	}
	int fullcnt = 0;
	for (int j = 1; j <= n; ++j) {
		for (int h = 1; h <= n; ++h) {
			if (tree[j][h].size() != 0) {
				for (int u = 0; u < tree[j][h].size(); ++u) {
					fullcnt++;
				}
			}
		}
	}

	cout << fullcnt << endl;

	getchar();
	getchar();
}
void prints() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << tree[i][j].size() << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << ground[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (tree[i][j].size() != 0)
				cout << tree[i][j][0] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;
}