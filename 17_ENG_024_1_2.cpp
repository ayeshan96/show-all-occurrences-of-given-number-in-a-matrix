#include<iostream>

using namespace std;

void elements(int **array,int row,int column,int x,int y)
{
	if (x < row && y < column)
	{
		cin >> array[x][y];
		elements(array, row, column, x, y + 1);
	
	}
	else if (x < row&&y == column)
	{
		elements(array, row, column, x + 1, 0);
	}
}

int numberElements(int number1,int count)
{
	if (number1> 0)
	{
		numberElements(number1 / 10, count + 1);
	}
	else
	{
		return count;
	}
}

void numberArray(int *dma, int number,int i)
{
	if (i >= 0)
	{
		dma[i] = number % 10;
		number = number / 10;
		numberArray(dma, number, i - 1);
	}
}
void rec(int **array, int *dma,int i,int j,int k,int row,int column,int count)
{
	if (dma[k] == array[i][j] && j < column&&i < row&&k < count)
	{
		cout << i <<" "<< j<<endl;
		if (dma[k + 1] == array[i][j + 1])
		{
			rec(array, dma, 0, 0, k + 1, row, column, count);
		}
	}
	else if(i<row)
	{
		if (i < row&&j < column)
		{
			rec(array, dma, i, j + 1, k, row, column, count);

		}
		else if (i < row&&j == column)
		{
			rec(array, dma, i + 1, 0, k, row, column, count);
		}

	}
}

int main()
{
	int row, column,number,length;
	cout << "Enter number of Rows : ";
	cin >> row;

	cout << "\n\n\nEnter number of column : ";
	cin >> column;

	int**array = new int*[row];
	for (int i = 0; i < row; i++)
	{
		array[i] = new int[column];
	}

	cout << "\n\n\nEnter the elements\n";
	elements(array,row,column,0,0);
	
	cout << "\n\nEnter the number which you want to find the occurrences : \n\n";
	cin >> number;


	int number1 = number;

	int count = numberElements(number1,0);
	
	int*dma = new int[count];

	numberArray(dma,number,count-1);

	rec(array, dma, 0, 0, 0, row, column, count);



	system("pause");
	return 0;
}