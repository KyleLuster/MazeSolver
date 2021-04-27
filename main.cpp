//Kyle Luster
//This is my own work; with source code from instructor

//Source for MazeSolver

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MazeCell.h"
#include "MyStack.h"

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define DONE 4
#define SUCCESS 10
#define FAILURE 20

//method headers*******************************************************

//depthFirst header
void depthFirst(MazeCell start, MazeCell end);

//global variables*****************************************************

//# rows and cols in the maze
int rows, cols;
//pointer to the grid (2-d array of ints)
int** grid;
//pointer to the maze cells (2-d array of MazeCell objects)
MazeCell** cells;

int main() {
	
	//create the Maze from the file
	ifstream fin("maze.in");	
	if(!fin){
		cout << "File not found\n";
		exit(2);
	}

	//read in the rows and cols
	fin >> rows >> cols;

	//create the maze rows
	grid = new int* [rows];
	
	//add each column
	for (int i = 0; i < rows; i++)
		grid[i] = new int[cols];

	//read in the data from the file to populate
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fin >> grid[i][j];
		}
	}

	//look at it 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == 3)
				cout << "S" << " ";
			else if (grid[i][j] == 4)
				cout << "E" << " ";
			else
				cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	//make a 2-d array of cells
	cells = new MazeCell * [rows];
	for (int i = 0; i < rows; i++) {
		cells[i] = new MazeCell[cols];
	}

	//all MazeCell in the cells grid has a default init
	//only update those cells that are not walls

	MazeCell start, end;
	
	//iterate over the grid
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] != 0) {
				cells[i][j].setCoordinates(i, j);
				//look for the start and end cells
				if (grid[i][j] == 3)
					start = cells[i][j];
				if (grid[i][j] == 4) 
					end = cells[i][j];
				
			}

		}
	}
	
	//testing
	cout <<"start: "<< start << " end: " << end << endl;
	//solve it!

	
depthFirst(start, end);

	return 0;
}


//this function should find a path through the maze
//if found, output the path from start to end
//if not path exists, output a message stating so

void depthFirst(MazeCell start, MazeCell end)
{	
  int row = start.getRow();
  int col = start.getCol();
	MyStack<MazeCell>theStack;
  //theStack.push(start);   //pushing in start
  //cout<< theStack.top() << endl;
  int i = row;
  int j = col;

 while(cells[i][j] != cells[end.getRow()][end.getCol()]){

   //I think that once I move a direction  need to start back at east
   //how do I do that?

    cout<<"testing before east"<<endl;
    cout<<cells[i][j]<<endl;

    if(cells[i][j].getCol()<5   //east checker
    &&
    cells[i][j+1].unVisited()
    &&
    cells[i][j+1].getRow()!=-1
    &&
    cells[i][j+1].getCol()!=-1) {
    //push location to stack
    theStack.push(cells[i][j]);
    //mark as visited
    cells[i][j].visit();
    j+=1;   //changed from j++ 
    cout<<"east answer"<<cells[i][j]<<endl;
    //I need to return to the start of east if statement here
    }

    cout<<"testing before south"<<endl;
    cout<<cells[i][j]<<endl;

    if(cells[i][j].getRow()<=3   //south checker
    &&
    cells[i+1][j].unVisited()
    &&
    cells[i+1][j].getRow()!=-1
    &&
    cells[i+1][j].getCol()!=-1) {
    //push location to stack
    theStack.push(cells[i][j]);
    //mark as visited
    cells[i][j].visit();
    i+=1;
    //I need to return to the start of east if statement here
    }


    cout<<"testing before west"<<endl;
    cout<<cells[i][j]<<endl;

    if(cells[i][j].getCol()>=0   //west checker
    &&
    cells[i][j-1].unVisited()
    &&
    cells[i][j-1].getRow()!=-1
    &&
    cells[i][j-1].getCol()!=-1) {
    //push location to stack
    theStack.push(cells[i][j]);
    //mark as visited
    cells[i][j].visit();
    j-=1;
    //I need to return to the start of east if statement here
    }

    //north checker causes a segmentation fault
    // if(cells[i][j].getRow()<4   //north checker
    // &&
    // cells[i-1][j].unVisited()
    // &&
    // cells[i-1][j].getRow()!=-1
    // &&
    // cells[i-1][j].getCol()!=-1) {
    // //push location to stack
    // theStack.push(cells[i][j]);
    // //mark as visited
    // cells[i][j].visit();
    // i-=1;
    // }

    //if we are stuck, pop and try again
    //the pop placement is causing issues
    // else {
    //   theStack.pop();
    // }

    } //end of while loop
        theStack.push(cells[i][j]);
    //printing the path from the stack
    //why does it print 0,0 ?
    if (!theStack.empty()) {                                         
        cout << "Maze Path: ";
        while (!theStack.empty()) {
            cout << theStack.top() << " ";
            theStack.pop();
        }

    }
    else{
      cout<<"No path found"<<endl;
  }

}
