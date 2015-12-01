/*
 * MathGameModel.h
 *
 *  Created on: Nov 19, 2015
 *      Author: Matt
 */

#include "boardmodel.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#ifndef MATHGAMEMODEL_H_
#define MATHGAMEMODEL_H_

class MathGameModel {
private:
	GameBoardModel* 	board_model;
	int			difficulty;
	long		        current_time; // Not quite sure if necessary
	std::vector<std::string>     formula;
	std::vector<int> arrayofnumbers;//contains all the operators
	std::vector<char> arrayofchars;//contains all the numbers
public:
    MathGameModel();

	/*Used to return the private board object*/
	GameBoardModel get_board();

	/* Used to figure out how many digits a number has in the given formula*/
	int findLengthofNum(std::string formula, unsigned int index);//unsigned to make less compiler warnings, not important

	/*Used to find the length of operator signs. SHOULD only be 1 between two numbers, so this checks for that*/
	int findLengthofOper(std::string formula, unsigned int index);

	/*Creates a number after figuring out how many digits it has from findLenthofNum function*/
	int generateNumber(std::string formula, int index, int length);

	/*Function that calculates each operation and number from given formula, to check if the result is found in the grid*/
	int CalculateNumber(int originalnum, int num, char oper);

	/*Another debug function; can remove later after testing completed*/
	void printVector(std::vector<char> array, std::vector<int> array2);

	/* Try to clear tiles from the board used in the given formula.
	   Return true if valid, else false */
	bool handle_formula(std::string formula);

        // Returns a string representation of the formula
        std::string get_formula();

	/* Fill the board with new numbers at the beginning of the game */
	void fill_board(int num_to_fill);

	/* Removes the last num or operator from the formula */
	void dequeue();

	/* Adds a num or operator to the formula */
	void append(std::string);


	/* Fills in more grid squares based on game mode and difficulty */
	void tick();
};

 /* namespace std */

#endif /* MATHGAMEMODEL_H_ */
