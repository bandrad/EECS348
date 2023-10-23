#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//constants
const int MAX_SIZE = 100;


//functions
void readFile(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int& actualSize, string fileName)
{

	//checks if input file can be opened
	ifstream File(fileName);
	if (!File)
	{
		cerr << "Error opening file: " << fileName << endl;
	}

	File >> actualSize;

	//reads in first matrix
	for (int i = 0; i < actualSize; i++)
	{
		for (int j = 0; j < actualSize; j++)
		{
			File >> m1[i][j];
		}
	}

	//reads in second matrix
	for (int i = 0; i < actualSize; i++)
	{
		for (int j = 0; j < actualSize; j++)
		{
			File >> m2[i][j];
		}
	}

	File.close();

}//end readFile

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int actualSize, ofstream &File)
{
	for (int i = 0; i < actualSize; i++)
	{
		for (int j = 0; j < actualSize; j++)
		{
			File << matrix[i][j] << " ";
		}

		File << endl;
	}

}//end printMatrix

void addMatrix(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int actualSize, ofstream &File)
{
	// resut array
	int result[MAX_SIZE][MAX_SIZE];


	for (int i = 0; i < actualSize; i++)
	{
		for (int j = 0; j < actualSize; j++)
		{
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}

	printMatrix(result, actualSize, File);

}//end addMatrix

void multiplyMatrix(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int actualSize, ofstream &File)
{
	// resut array
	int result[MAX_SIZE][MAX_SIZE];
	

	for (int i = 0; i < actualSize; i++)
	{
		for (int j = 0; j < actualSize; j++)
		{
			int product = 0;

			for (int k = 0; k < actualSize; k++)
			{
				product += m1[i][k] * m2[k][j];
			}

			result[i][j] = product;
		}
	}

	printMatrix(result, actualSize, File);

}//end multiplyMatrix

void subractMatrix(int m1[MAX_SIZE][MAX_SIZE], int m2[MAX_SIZE][MAX_SIZE], int actualSize, ofstream &File)
{
	// resut array
	int result[MAX_SIZE][MAX_SIZE];


	for (int i = 0; i < actualSize; i++)
	{
		for (int j = 0; j < actualSize; j++)
		{
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}

	printMatrix(result, actualSize, File);

}//end subractMatrix


int main()
{
	int m1[MAX_SIZE][MAX_SIZE];
	int m2[MAX_SIZE][MAX_SIZE];

	int actualSize = 0;

	string fileName = "input.txt";
	ofstream File("output.txt");

	readFile(m1, m2, actualSize, fileName);

	File << "Brisa Andrade" << endl;
	File << "Matrix Manipulation\n" << endl;

	File << "Matrix A: " << endl;
	printMatrix(m1, actualSize, File);

	File << "\nMatrix B: " << endl;
	printMatrix(m2, actualSize, File);

	File << "\nMatrix Sum (A + B):" << endl;
	addMatrix(m1, m2, actualSize, File);

	File << "\nMatrix Product ( A * B): " << endl;
	multiplyMatrix(m1, m2, actualSize, File);

	File << "\nMatrix Difference (A - B):" << endl;
	subractMatrix(m1, m2, actualSize, File);

	File.close();

}

