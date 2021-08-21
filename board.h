#include <cassert>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>

#include "command.h"

/****************************************************************
board.h

Recursive Solution to the Robot movement in Richochet Robot Game
Developed by: Uday Bir Singh
March, 2020

*****************************************************************/

#ifndef BOARD_H
#define BOARD_H
class Position
{
	public:
  	// The default coordinate (-1,-1) is invalid/unitialized
  	Position(int r = -1, int c = -1) : row(r), col(c)
  	{
  	}
  	int row, col;
};

// Prototype of non-member operator functions to print and equality compare Positions
std::ostream& operator<<(std::ostream &ostr, const Position &p);
bool operator==(const Position &a, const Position &b);
bool operator!=(const Position &a, const Position &b);


// ==================================================================
// A class to hold information about the puzzle board including the
// dimensions, the location of all walls, the current position of all
// robots, the goal location, and the robot (if specified) that must
// reach that position

class Board
{
	public:
		//friend functions are able to access its members even being as an outsider
		//This functions returns a structure of type struct command which is defined for our convinient
		
  		friend command BuildPlausibleCommand(const Board&, const Board&); 
    	Board(int num_rows, int num_cols); //Non-inline constructor that is defined inside board.cpp

  		// ACCESSORS
  		int  getRows() const
  		{
    		return rows;
  		}
  		int getCols() const
  		{
    		return cols;
  		}
  		bool getHorizontalWall(double r, int c) const;
  		bool getVerticalWall(int r, double c) const;

  		// ACCESSORS related to the robots and their current positions
  		unsigned int numRobots() const
  		{
    		return robots.size();
  		}
  		// lookup the assigned "id" for a robot by name 
  		int whichRobot(char a) const; // A constant non-modifyable member function
  		// given a robot's id, lookup the name
  		char getRobot(int i) const
  		{
    		return robots[i];
  		}
  		// get the robots current position
  		Position getRobotPosition(int i) const
  		{
    		return robot_positions[i];
  		}

  		// ACCESSORS related to the overal puzzle goal target location
  		// the position
  		Position getGoal() const
  		{
    		return goal;
  		}
  		// the id of the robot that must reach the goal position
  		// (if any robot is allowed to reach the goal, this value is -1)
  		int getGoalRobot() const
  		{
    		return goal_robot;
  		}

  		// MODIFIERS related to board geometry
  		void addHorizontalWall(double r, int c);
  		void addVerticalWall(int r, double c);

  		// MODIFIERS related robot position
  		// initial placement of a new robot
  		void placeRobot(const Position &p, char a);
  		// move an existing robot
  		bool moveRobot(int i, const std::string &direction);
  		bool moveRobot(int i, unsigned short direction);
  		// MODIFIER related to the puzzle goal
  		void setGoal(const std::string &goal_robot, const Position &p);

  		// PRINT
  		void print();
  		const std::vector<Position>& getRobots() const
  		{
    		return robot_positions;
  		}
  		bool canMoveRobot(unsigned int i, unsigned short direction) const;
  		void executeCommand(const command&);
  		Board executeCommandToNewBoard(const command&) const;
	private:

  		// private member function to help inside
  		char getspot(const Position &p) const;
  		void setspot(const Position &p, char a);

  		bool isPositionFilledByRobot(const Position&) const;

  		// REPRESENTATION

  		// the board geometry
  		int rows;
  		int cols;
  		std::vector<std::vector<char> > board;
  		std::vector<std::vector<bool> > vertical_walls;
  		std::vector<std::vector<bool> > horizontal_walls;

  		// information about the names and current positions of the robots
  		std::vector<char> robots;
  		std::vector<Position> robot_positions;

  		// the goal position and the id of the robot that must reach it
  		Position goal;
  		// the goal robot is -1 if the puzzle is solved if any robot reaches the goal
  		int goal_robot;
};
#endif
