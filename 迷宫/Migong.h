#pragma once

class Pos
{
public:
	Pos(int _row,int _col)
		:row(_row)
		,col(_col)
	{}
	int row;
	int col;

};
bool IsAccess(int *a,int row,int col,Pos &cur)
{
	if(cur.col < col && cur.row < row && a[cur.row * col + cur.col ] == 0)
	{
		return true;
	}
	return false;
}

void GetMaze(int *a,int row,int col)
{
	FILE* FOut = fopen("MazeMap.txt","r");
	assert(FOut);
	for(int i = 0;i < row; ++i)
	{
		for(int j = 0;j < col; )
		{
			char ch = fgetc(FOut);
			if(ch == '0'||ch == '1')
			{
				a[i*col +j] = ch - '0';
				++j;
			}
		}
	}
	fclose(FOut);
}
stack<Pos> GetMazePath(int* a, int row, int col, Pos entry)
{
	stack<Pos> path;
	path.push(entry);
	Pos cur = entry;

	while(cur.col < col && cur.row < row &&!path.empty())
	{
		Pos cur = path.top();
		Pos next = cur;

		if(next.row == row - 1)
		{
			return path;
		}
		// 右
		next.col++;
		if (IsAccess(a, 10, 10, next))
		{
			a[next.row * col + next.col] = 2;
			cur = next;
			path.push(next);
			continue;
		}
		// 上
		next = cur;
		next.row--;
		if (IsAccess(a, 10, 10, next))
		{
			a[next.row * col + next.col] = 2;
			cur = next;
			path.push(next);
			continue;
		}

		// 下
		next = cur;
		next.row++;
		if (IsAccess(a, 10, 10, next))
		{
			a[next.row * col + next.col] = 2;
			cur = next;
			path.push(next);
			continue;
		}
		//左
		next = cur;
		cur.col--;
		if(IsAccess(a,10,10,cur))
		{
			a[next.row*col + next.col] = 2;
			cur = next;
			path.push(next);
			continue;
		}

 		Pos top = path.top();
 		a[top.row* col + top.col] = 3;
 		path.pop();
	}
	cout<<"没有"<<endl;
}
void PrintMaze(int* a, int row, int col)
{
	for (int i = 0 ; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout<<a[i*col+j]<<" ";
		}

		cout<<endl;
	}

	cout<<endl;
}
