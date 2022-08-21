#include <bits/stdc++.h>

using namespace std;

map<vector<vector<int> > , bool> visited;
map<vector<vector<int> > , vector<vector<int> > > parent;
vector<vector<int> > goal(3, vector<int> (3));


bool valid(int &x, int &y)
{
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
		return true;

	return false;
}


int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};


void print_path(vector<vector<int> > s)
{
	if (parent.count(s))
		print_path(parent[s]);

	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				{
					printf("%d ", s[i][j]);
				}
			cout << endl;
		}
	cout << endl;

	return;
}

void print(vector<vector<int> > &s)
{
	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				{
					printf("%d ", s[i][j]);
				}
			cout << endl;
		}
}


void solve(vector<vector<int> > a)
{

	queue<vector<vector<int> > > Q;
	Q.push(a);
	visited[a] = true;
	int pos1, pos2;
	vector<vector<int> > temp;
	while (!Q.empty())
		{
			vector<vector<int> > s = Q.front();
			Q.pop();

			//cout << endl; print(s); cout << endl;

			for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
						{
							if (s[i][j] == 0)
								{
									pos1 = i;
									pos2 = j;
									break;
								}
						}

				}


			for (int k = 0; k < 4; k++)
				{
					int cx = pos1 + dx[k];
					int cy = pos2 + dy[k];
					temp = s;
					if (valid(cx, cy))
						{
							swap(temp[cx][cy], temp[pos1][pos2]);
							if (visited[temp] == false)
								{
									visited[temp] = true;
									parent[temp] = s;
									Q.push(temp);

									if (temp == goal) //print(s)
										{
											cout << "\n\nFound!!\n\n";
											print_path(temp);
											return;
										}
								}
						}
				}
		}
	return;
}

int main()
{

	//start of 8 puzzle
	vector<vector<int> > start =
	{
		{1, 2, 3},
		{0, 4, 6},
		{7, 5, 8}
	};

	//goal of 8 puzzle
	goal =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0}
	};
	solve(start);

	return 0;
}