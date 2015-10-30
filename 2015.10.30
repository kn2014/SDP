#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define MAZE_W 5
#define MAZE_H 5

int maze[MAZE_W][MAZE_H] = {0,1,0,0,0,
             	      		0,1,0,1,0,
			                0,1,0,1,0,
		                	0,0,0,1,0,
		                	1,1,1,1,0};
bool correct (int x, int y)
{
	return x >=0 && x < MAZE_W &&
	       y >=0 && y < MAZE_H &&
	       maze[x][y] == 0;
}
bool way (int x, int y, int targetX, int targetY)
{
	if (!correct (x,y))
		return false;

	if (x == targetX && y == targetY)
		return true;

	maze[x][y] = 2;

	return way (x,y-1,targetX,targetY) ||
		   way (x-1,y,targetX, targetY) ||
		   way (x+1,y,targetX,targetY) ||
		   way (x,y+1,targetX,targetY);
}

void cleanup ()
{
	for (int i = 0; i < MAZE_H; i++)
		for (int j = 0; j < MAZE_W; j++)
			if (maze[i][j] > 1)
				maze[i][j] = 0;
}

int main ()
{
	cout << wayIter (0,0,4,4) << endl;
	return 0;
}
