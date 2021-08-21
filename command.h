
/****************************************************************
command.h

Recursive Solution to the Robot movement in Richochet Robot Game
Developed by: Uday Bir Singh
March, 2020

*****************************************************************/
#ifndef COMMAND_H_
#define COMMAND_H_
struct command
{
  	command()
  	{
    	robot = 0;
    	dir = 4;
  	}
  	command(char c, unsigned short d) : robot(c), dir(d)
  	{
  	}
  	command(char c, unsigned short r, unsigned short d) : robot(c), robonum(r), dir(d)
  	{
  	}
  	char robot;
  	unsigned short dir;
  	unsigned short robonum;
}typedef command;
#endif

