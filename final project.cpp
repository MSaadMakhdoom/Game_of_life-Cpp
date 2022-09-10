#include <iostream> // iostream used cout and cin and other function perform
#include <string>  // string used user put file name store in string variable
#include <fstream> //fstream used file read and write
using namespace std;
const int SIZE_OF_GRID = 30; //used constant size of two dimensional array set 
const int Xcordinate = SIZE_OF_GRID + 1+1;  //size of grid in x-axis.add one because loop start 1 to check neighbour in grid
const int Ycordinate = SIZE_OF_GRID + 1+1;//size of grid in y-axis
void DISPLAY_GRID(int ORIGNALGRID[Xcordinate][Ycordinate]); //the function prototype perform grid print alive and dead cell
void DETERMINE_STATE(int ORIGNALGRID[Xcordinate][Ycordinate]);//the function prototype check the neighbour around the cell
int iteration;//file read itration and store 
void PERFORM_FUNCTION(int ORIGNALGRID[Xcordinate][Ycordinate]); //the function prototype file write 
void READ_FILE(int ORIGNALGRID[Xcordinate][Ycordinate]);//function prototype read file to put user name
int main()
{

	int ORIGNALGRID[Xcordinate][Ycordinate];// define the size of grid 
	for (int i = 0; i <= SIZE_OF_GRID; i++)
	{
		for (int j = 0; j <= SIZE_OF_GRID; j++)
		{
			ORIGNALGRID[i][j] = 0; // initialization of grid every element 0
		}
	}
	READ_FILE(ORIGNALGRID);//read file function call
	
	PERFORM_FUNCTION(ORIGNALGRID); //perform function call

}
void READ_FILE(int ORIGNALGRID[Xcordinate][Ycordinate]) // read file and store
{

	int x, y; string filename; int READ_FILE_LINE, aliveCells;
	do
	{
		cout << "Enter name of file to read programe : ";
		cin >> filename;// user enter the name of file to save in string variable
		ifstream readfile(filename); //ifstream read file 
		if (readfile.is_open()) //file name correct then open file .other wise message display
		{

			{
				int count = 0;//count countrol the file  first readfile
				while (readfile >> READ_FILE_LINE)
				{
					if (count == 0)
					{

						iteration = READ_FILE_LINE;//fist integer store in itreation

					}
					else if (count == 1)
					{
						aliveCells = READ_FILE_LINE;//second integer store in alive cell

					}
					else
					{
						x = READ_FILE_LINE;// third cordinate integer firat cordinate store in x
						readfile >> y; // after the space store integer in  y
						ORIGNALGRID[x][y] = 1; // file read cordinate point grid in position element is 1.

					}
					count++;
				}
				break;
			}
		}
		else
		{
			cout << "Error in name of file,Please try again :";//user wrong the name of file to message display
		}
	} while (true);
	DISPLAY_GRID(ORIGNALGRID);//function call the change in grid

}
ofstream FILE_WRITE;    //ofstream  file-write  
void PERFORM_FUNCTION(int ORIGNALGRID[Xcordinate][Ycordinate])
{

	int counter = 0;

	FILE_WRITE.open("example.txt");// write  the file save in example.txt


	do
	{

		DISPLAY_GRID(ORIGNALGRID); // function call grid postion 
		DETERMINE_STATE(ORIGNALGRID);//function call
		system("CLS"); // system clear screen used to fixed the size of grid 
		counter++;

	} while (counter <= iteration);//read file then times of generation show

	FILE_WRITE.close(); //file close example.txt
}
void DISPLAY_GRID(int ORIGNALGRID[Xcordinate][Ycordinate]) //function print the grid
{
	for (int a = 1; a <= SIZE_OF_GRID; a++)
	{
		for (int b = 1; b <= SIZE_OF_GRID; b++)
		{
			if (ORIGNALGRID[a][b] == 1)//the grid position element is equal to one
			{
				cout << " * ";//print in compiler
				FILE_WRITE << " * ";//print in file
			}
			else
			{
				cout << " . ";//grid position element is not equal to one
				FILE_WRITE << " . ";
			}
			if (b == SIZE_OF_GRID )
			{
				cout << "\n";//next line the grid 
				FILE_WRITE << endl;//file write next line the grid 
			}
		}
	}
}

void compareGrid(int ORIGNALGRID[Xcordinate][Ycordinate], int COPYGRID[Xcordinate][Ycordinate]) {
	for (int a = 0; a <= SIZE_OF_GRID; a++)
	{
		for (int b = 0; b <= SIZE_OF_GRID; b++)
		{
			COPYGRID[a][b] = ORIGNALGRID[a][b];//copy the grid 
		}
	}
}
void DETERMINE_STATE(int ORIGNALGRID[Xcordinate][Ycordinate])
{
	int COPYGRID[Xcordinate][Ycordinate];
	for (int i = 0; i <= SIZE_OF_GRID; i++)
	{
		for (int j = 0; j <= SIZE_OF_GRID; j++)
		{
			COPYGRID[i][j] = 0;
		}
	}

	compareGrid(ORIGNALGRID, COPYGRID);
	int alive_cell;
	for (int i = 1; i <= SIZE_OF_GRID; i++)
	{
		for (int j = 1; j <= SIZE_OF_GRID; j++)
		{

			alive_cell = 0;
			alive_cell += COPYGRID[i - 1][j - 1];// check the position upward left corner side . if grid element is one or zero add in cell
			alive_cell += COPYGRID[i][j - 1];         // check neighbour left side
			alive_cell += COPYGRID[i + 1][j - 1]; //next step check neighbour downward left corner side
			alive_cell += COPYGRID[i + 1][j];     //right side check neighbour downward 
			alive_cell += COPYGRID[i + 1][j + 1];// next step check neighbour downward right corner side
			alive_cell += COPYGRID[i][j + 1];     //check neighbour  right side
			alive_cell += COPYGRID[i - 1][j + 1];//check neighbour upward right corner side
			alive_cell += COPYGRID[i - 1][j];//check neighbour upward


			if (alive_cell == 3)// alive cell three the cell alive mean three neighbour alive
			{
				ORIGNALGRID[i][j] = 1;
			}
			else if (alive_cell > 3 || alive_cell < 2)//alive cell greater then three the cell dead mean greater then three neighbour alive
			{
				ORIGNALGRID[i][j] = 0;
			}

		}
	}
}

