/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Grace Tai, Qimeng Fang
 * gracetai, andyfqm
 *
 * Project 4: Battleship
 *
 * Seems to include many functions of the battleship game, including
 * information about the player and their board.
 */

#include <fstream>

#include "Player.h"


Player::Player() {
    name = "";
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

Player::Player(string name_val) {
    name = name_val;
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

void Player::init_grid() {
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            grid[i][j] = EMPTY_LETTER;
            guess_grid[i][j] = EMPTY_LETTER;
        }
    }
}

string Player::get_name() {
    return name;
}

int Player::get_num_ships() {
    return num_ships;
}

int Player::get_remaining_ships() {
    return remaining_ships;
}

char Player::get_grid_at(int row, int col) {
    return grid[row][col];
}

char Player::get_guess_grid_at(int row, int col) {
    return guess_grid[row][col];
}

void Player::add_ship(Ship ship) {
    if (num_ships >= MAX_NUM_SHIPS) {
        return;
    }

    int start_row = ship.get_start().get_row();
    int start_col = ship.get_start().get_col();
    int end_row = ship.get_end().get_row();
    int end_col = ship.get_end().get_col();

    ships[num_ships] = ship;
    num_ships++;
    remaining_ships++;

    if (ship.is_horizontal()){
        if (start_col < end_col) {
            for (int i = start_col; i <= end_col; i++) {
                grid[start_row][i] = SHIP_LETTER;
            }
        }
        else {
            for (int i = end_col; i <= start_col; i++) {
                grid[start_row][i] = SHIP_LETTER;
            }
        }
    }
    else {
        if (start_row < end_row) {
            for (int i = start_row; i <= end_row; i++) {
                grid[i][start_col] = SHIP_LETTER;
            }
        }
        else {
            for (int i = end_row; i <= start_row; i++) {
                grid[i][start_col] = SHIP_LETTER;
            }
        }
    }
    return;
}

void Player::attack(Player &opponent, Position pos) {
    char opponent_grid_pos =
    opponent.get_grid_at(pos.get_row(), pos.get_col());
    
    char guess_grid_pos = guess_grid[pos.get_row()][pos.get_col()];

    if (opponent_grid_pos == SHIP_LETTER && guess_grid_pos == EMPTY_LETTER) {
        // Hit
        guess_grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
        opponent.grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
        cout << name << " " << pos << " hit" << endl;
        for (int i = 0; i < opponent.num_ships; i++) {
            if (opponent.ships[i].has_position(pos)) {
                opponent.ships[i].hit();
                if (opponent.ships[i].has_sunk()) {
                    int size = opponent.ships[i].get_size();
                    announce_ship_sunk(size);
                    opponent.remaining_ships--;
                }
            }
        }
    }
    else {
        // Miss
        guess_grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
        opponent.grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
        cout << name << " " << pos << " miss" << endl;
    }
}

void Player::announce_ship_sunk(int size) {
    if (size == 2) {
        cout << "Congratulations "<< name
        <<"! You sunk a Destroyer" << endl;
    }
    else if (size == 3) {
        cout << "Congratulations " << name
        << "! You sunk a Submarine" << endl;
    }
    else if (size == 4) {
        cout << "Congratulations " << name
        << "! You sunk a Battleship" << endl;
    }
    else {
        cout << "Congratulations " << name
        << "! You sunk a Carrier" << endl;
    }
    return;
}

bool Player::load_grid_file(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    else {
        string input;
        int start_row;
        int start_col;
        int end_row;
        int end_col;
        for (int i = 0; i <= num_ships; i++) {
            getline(file, input);
            if (input.length() == 5) {
                start_row = input[0] - '1';
                start_col = tolower(input[1]) - 'a';
                end_row = input[3] - '1';
                end_col = tolower(input[4]) - 'a';
            }
            else {
                start_row = input[1] - '1';
                start_col = tolower(input[3]) - 'a';
                end_row = input[7] - '1';
                end_col = tolower(input[9]) - 'a';
            }
            add_ship(Ship(Position(start_row, start_col),
                          Position(end_row, end_col)));
        }
        file.close();
        return true;
    }
}

bool Player::destroyed() {
    if (remaining_ships == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_guess_grid() {
    ::print_grid(guess_grid);
}
