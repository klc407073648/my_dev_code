#include<vector>
#include<iostream>
using namespace std;

bool isHasPath(char* matrix, int rows, int cols,int curRow,int curCol, char* str,int strPos,vector<int> s)
{
	if (strPos == strlen(str))
		return true;
	if (curRow < 0 || curRow >= rows || curCol < 0 || curCol >= cols)
		return false;
	int index = curRow*(cols)+curCol;
	bool result = false;
	if (s[index] == 0 && matrix[index] == str[strPos])
	{
		strPos++;
		s[index] = 1;
		result= (isHasPath(matrix, rows, cols, curRow - 1, curCol, str, strPos, s) || isHasPath(matrix, rows, cols, curRow + 1, curCol, str, strPos, s)
			|| isHasPath(matrix, rows, cols, curRow, curCol - 1, str, strPos, s) || isHasPath(matrix, rows, cols, curRow, curCol + 1, str, strPos, s));
	}
	if (result)
		return true;
	return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	bool flag = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int curIndex = i*cols + j;
			vector<int> res;
			int start = 0;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					res.push_back(0);
				}
			}
			if (res[curIndex] == 0 && matrix[curIndex] == str[start])
			{
				start++;
				res[curIndex] = 1;
				flag = (isHasPath(matrix, rows, cols, i - 1, j, str, start, res) || isHasPath(matrix, rows, cols, i + 1, j, str, start, res)
					|| isHasPath(matrix, rows, cols, i, j - 1, str, start, res) || isHasPath(matrix, rows, cols, i, j + 1, str, start, res));
			}
			if (flag == true)
				return true;
		}
	}
	return false;

}



void hasPathTest()
{
	//bool t = hasPath("abcesfcsadee",3,4,"bcced");
	//bool t = hasPath("ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS", 5, 8, "SGGFIECVAASABCEHJIGQEMS");
	bool t = hasPath("ABCESFCSADEE", 3, 4, "SEE");
	
	int s = 0;
}
