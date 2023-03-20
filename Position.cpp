/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Grace Tai, Qimeng Fang
 * gracetai, andyfqm
 *
 * Project 4: Battleship
 *
 * sets and returns the position of battleships
 */

#include "Position.h"
#include "utility.h"

 // The difference between the value of an integer and its ASCII value.
const int int_difference = 48;
// The difference between the uppercase letter and the corresponsing integer
const int upper_difference = 65;
// The difference between the lowercase letter and the corresponsing integer
const int lower_difference = 97;

Position::Position() {
    row = 0;
    col = 0;
}

Position::Position(int row_in, int col_in) {
    row = check_range(row_in);
    col = check_range(col_in);
}

Position::Position(char row_in, char col_in) {
    row = int(row_in) - int_difference - 1;
    check_range(row);
    if (col_in > 64 && col_in < 91) {
        col = int(col_in) - upper_difference;
    }
    else {
        col = int(col_in) - lower_difference;
    }
    check_range(col);
}

int Position::get_row() {
    return row;
}

void Position::set_row(int row_in) {
    row = row_in;
    row = check_range(row);
    return;
}

int Position::get_col() {
    return col;
}

void Position::set_col(int col_in) {
    col = col_in;
    col = check_range(col);
    return;
}

void Position::read(istream& is) {
    string input;
    is >> input;

    if (input.length() == 2) {
        col = tolower(input[1]) - 'a';
        row = input[0] - '1';

    }
    else {
        row = input[1] - '1';
        col = tolower(input[3]) - 'a';
    }
    check_range(row);
    check_range(col);
}

void Position::write(ostream& os) {
    os << "(" << check_range(row) + 1 << "," << char(check_range(col) + upper_difference) << ")";
    return;
}

int Position::check_range(int val) {
    if (val >= 0 && val < MAX_GRID_SIZE) {
        return val;
    }
    else {
        if (abs(val - 0) < abs(val - (MAX_GRID_SIZE - 1))) {
            return 0;
        }
        else {
            return MAX_GRID_SIZE - 1;
        }
    }
    return -1;
}

// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is,  Position &pos) {
    pos.read(is);
    return is;
}

ostream &operator<<(ostream &os, Position pos) {
    pos.write(os);
    return os;
}

