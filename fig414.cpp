//4.14
// Heuristics - tiles out of place & sum of distances
#include <bits/stdc++.h>
using namespace std;

map<vector<vector<int> > , bool> visited;
map<int , pair<int, int> > loc;
vector<vector<int> > goal(3, vector<int> (3));

bool valid(int &x, int &y)
{
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
		return true;

	return false;
}


int dx[] = { 0, -1, 1, 0};
int dy[] = { -1, 0, 0, 1,};


int calculateCostF(vector<vector<int> > temp, vector<vector<int> > goal)
{
	int count = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (goal[i][j] && temp[i][j] != goal[i][j])
				count++;
	return count;
}
int calculateDistance(vector<vector<int> > temp)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (temp[i][j])
				{
					int xx = loc[temp[i][j]].first;
					int yy = loc[temp[i][j]].second;
					sum += abs(xx - i) + abs(yy - j);
				}
	return sum;
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
	cout << "Tiles out of place " << calculateCostF(s, goal) << endl;
	cout << "Sum of distances out of place " << calculateDistance(s) << endl;
}

void findActualLocation(vector<vector<int> > goal)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			loc[goal[i][j]] = {i, j};
}
void solve(vector<vector<int> > a)
{

	queue<vector<vector<int> > > Q;
	Q.push(a);
	visited[a] = true;
	int pos1, pos2;
	vector<vector<int> > temp;
	if (!Q.empty())
		{
			vector<vector<int> > s = Q.front();
			Q.pop();

			cout << endl << "Start" << endl; print(s); cout << "------------------" << endl << endl;

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
									Q.push(temp);

									if (temp == goal)
										{
											cout << "\nFound Goal!!\n";
											print(temp);
										}
									else
										{
											print(temp);
										}
									cout << endl << endl;
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
		{2, 8, 3},
		{1, 6, 4},
		{7, 0, 5}
	};

	//goal of 8 puzzle
	goal =
	{
		{1, 2, 3},
		{8, 0, 4},
		{7, 6, 5}
	};

	findActualLocation(goal);

	solve(start);

	return 0;
}
