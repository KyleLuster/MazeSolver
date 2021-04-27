//Kyle Luster
//This is my own work; with source code from instructor

/*
*
*	CST-201, Maze Solver Project
*	Provided starter code
*	MazeCell class
*	DO NOT CHANGE THIS FILE
*
*/

#ifndef MAZECELL_H
#define MAZECELL_H

#include <iostream>
#include <string>

using namespace std;

//models an open cell in a maze
//each cell knows its coordinates (row, col),
//direction keeps track of the next unchecked neighbor.
//a cell is considered 'visited' once processing moves to a neighboring cell
//the visited variable is necessary so that a cell is not eligible for visits 
//from the cell just visited

class MazeCell {
private:

	int row, col;
	//direction to check next
	//0: north, 1: east, 2: south, 3: west,	4: complete
	int direction;
	bool visited;

public:
	//set row and col with r and c
	MazeCell(int r, int c) {
		row = r;
		col = c;
		direction = 0;
		visited = false;
	}

	//no-arg constructor
	MazeCell() {
		row = col = -1;
		direction = 0;
		visited = false;
	}

	//copy constructor
	MazeCell(const MazeCell& rhs) {
		this->row = rhs.row;
		this->col = rhs.col;
		this->direction = rhs.direction;
		this->visited = rhs.visited;
	}

	int getDirection()const { return direction; }

	//update direction.  if direction is 4, mark cell as visited
	void advanceDirection() {
		direction++;
		if (direction == 4) visited = true;
	}

	//change row and col to r and c
	void setCoordinates(int r, int c) {
		this->row = r;
		this->col = c;
	}

	int getRow()const { return row; }

	int getCol()const { return col; }

	//cells are equal if they have the same row and col, respectively
	bool operator==(const MazeCell& rhs)const {
		return row == rhs.row && col == rhs.col;
	}

	bool operator!=(const MazeCell& rhs)const {
		return !((*this) == rhs);
	}

	//output cell as ordered pair
	friend ostream& operator<<(ostream& out, const MazeCell& rhs) {
		out << "(" << rhs.row << "," << rhs.col << ")";
		return out;
	}

	//set visited status to true
	void visit() { visited = true; }

	//reset visited status
	void reset() { visited = false; }

	//return true if this cell is unvisited
	bool unVisited()const { return !visited; }

	//may be useful for testing, return string representation of cell
	string toString()const {
		string str = "(" + to_string(getRow()) + "," + to_string(getCol())+ ")";		
		return str;
	}


};





#endif
