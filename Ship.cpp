/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Grace Tai, Qimeng Fang
 * gracetai, andyfqm
 *
 * Project 4: Battleship
 *
 * functions that help represent a ship
 */

#include <cmath>

#include "Ship.h"


Ship::Ship() {
    start = Position(0,0);
    end = Position(0, 0);
    num_hits = 0;
    size = 0;
}

Ship::Ship(Position start_in, Position end_in) {
    start = start_in;
    end = end_in;
    num_hits = 0;
    if (is_horizontal()) {
        size = abs(start.get_col() - end.get_col()) + 1;
    }
    else {
        size = abs(start.get_row() - end.get_row()) + 1;
    }
}

Position Ship::get_start() {
    return start;
}

Position Ship::get_end() {
    return end;
}

int Ship::get_size() {
    return size;
}

bool Ship::is_horizontal() {
    int start_row = start.get_row();
    int end_row = end.get_row();
    if (start_row == end_row) {
        return true;
    }
    else {
        return false;
    }
}

bool Ship::has_position(Position pos) {
    if (pos.get_row() >= start.get_row() && pos.get_row() <= end.get_row()) {
        if (pos.get_col() >= start.get_col() && pos.get_col() <= end.get_col()) {
            return true;
        }
        else if (pos.get_col() <= start.get_col() && pos.get_col() >= end.get_col()) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (pos.get_row() <= start.get_row() && pos.get_row() >= end.get_row()) {
        if (pos.get_col() <= start.get_col() && pos.get_col() >= end.get_col()) {
            return true;
        }
        else if (pos.get_col() >= start.get_col() && pos.get_col() <= end.get_col()) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void Ship::hit() {
    if (num_hits < size) {
        num_hits++;
    }
    return;
}

bool Ship::has_sunk() {
    if (num_hits == size) {
        return true;
    }
    else {
        return false;
    }
}
