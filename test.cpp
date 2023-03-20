/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void test_position();
void test_ship();
void test_player();
void test_game();

void startTests() {
    test_position();
    test_ship();
    test_player();
    test_game();
    return;
}

void test_position() {
    // testing Position default constructor here
    Position start_pos;
    Position end_pos;
    cout << "Testing Position::Position() - default constructor\n";
    cout << "start_pos, expected output: (0,0) actual output: "
    << "(" << start_pos.get_row() << "," << start_pos.get_col() << ")" << endl;
    cout << "end_pos, expected output: (0,0) actual output: "
    << "(" << end_pos.get_row() << "," << end_pos.get_col() << ")" << endl;

    // testing Position non-default constuctor here
    Position you ('1', 'A');
    Position wanna(1, 1);
    Position hear(-1, -1);
    Position a('0', '!');
    Position funny('1', 'a');
    Position joke('1', '^');
    cout << "Testing Position::Position(int row_in, int col_in)" <<
    " - non-default constructor\n";
    cout << "you, expected output: (0,0) actual output: "
    << "(" << you.get_row() << "," << you.get_col() << ")" << endl;
    cout << "wanna, expected output: (1,1) actual output: "
    << "(" << wanna.get_row() << "," << wanna.get_col() << ")" << endl;
    cout << "hear, expected output: (0,0) actual output: "
    << "(" << hear.get_row() << "," << hear.get_col() << ")" << endl;
    cout << "a, expected output: (0,0) actual output: "
    << "(" << a.get_row() << "," << a.get_col() << ")" << endl;
    cout << "uranus, expected output: (0,0) actual output: "
    << "(" << funny.get_row() << "," << funny.get_col() << ")" << endl;
    cout << "joke, expected output: (0,0) actual output: "
    << "(" << joke.get_row() << "," << joke.get_col() << ")" << endl;


    // testing Position setters here
    start_pos.set_row(4);
    start_pos.set_col(5);
    cout << "\nTesting Position::set_row() and Position::set_col()\n";
    cout << "start_pos, expected output: (4,5) actual output: "
    << "(" << start_pos.get_row() << ","
    << start_pos.get_col() << ")" << endl;
    start_pos.set_row(10);
    start_pos.set_col(10);
    cout << "start_pos, expected output: (7,7) actual output: "
    << "(" << start_pos.get_row() << ","
    << start_pos.get_col() << ")" << endl;
    start_pos.set_row(-1);
    start_pos.set_col(-1);
    cout << "start_pos, expected output: (0,0) actual output: "
    << "(" << start_pos.get_row() << ","
    << start_pos.get_col() << ")" << endl;

    // testing Position read
    ifstream input_file;
    input_file.open("grid1.txt");
    if (input_file.good()) {

        // can use the Position::read() function directly
        start_pos.read(input_file);

        // or use the extraction operator
        input_file >> end_pos;

        cout << "\nTesting Position::read()\n";
        cout << "start_pos, expected output: (0,0) actual output: "
        << "(" << start_pos.get_row() << ","
        << start_pos.get_col() << ")" << endl;
        cout << "end_pos, expected output: (3,0) actual output: "
        << "(" << end_pos.get_row() << ","
        << end_pos.get_col() << ")" << endl;
    }
    else {
        cout << "\nError opening grid1.txt\n";
    }
    input_file.close();

    // testing Position write
    cout << endl << "testing Position::write()" << endl;
    ofstream output_file;
    output_file.open("grid2.txt");
    if (output_file.good()) {
        start_pos.write(output_file);
        output_file << " ";
        end_pos.write(output_file);
        output_file << endl << "expected: (4, A)" << endl;
        cout << "check grid2" << endl;
    }
    else {
        cout << "\nError opening grid1.txt\n";
    }
    cout << "Position has been checked" << endl << endl;
    output_file.close();
    return;
}

void test_ship() {
    // testing Ship default constructor here

    Ship ship_1;
    cout << "Testing Ship::Ship() - default constructor\n";
    cout << "ship_1's start, expected output: (1,A), actual output: "
    << ship_1.get_start() << endl;
    cout << "ship_1's end, expected output: (1,A), actual output: "
    << ship_1.get_end() << endl;
    cout << "ship_1's size, expected output: 0, actual output: "
    << ship_1.get_size() << endl;
    // testing Ship non-default constuctor here
    Position main (1,3);
    Position vertical_end(3,3);
    Position horizontal_end(1, 1);
    Ship one (main,vertical_end);
    Ship two (vertical_end, main);
    Ship three(main, horizontal_end);
    Ship four (horizontal_end, main);

    cout << "Testing Ship::Ship(Position start_in, Position end_in)"
    << " - non-default constructor\n";
    cout << "one's start, expected output: (2,D), actual output: "
    << one.get_start() << endl;
    cout << "one's end, expected output: (4,D), actual output: "
    << one.get_end() << endl;
    cout << "one's size, expected output: 3, actual output: "
    << one.get_size() << endl;
    cout << "two's start, expected output: (4,D), actual output: "
    << two.get_start() << endl;
    cout << "two's end, expected output: (2,D), actual output: "
    << two.get_end() << endl;
    cout << "two's size, expected output: 3, actual output: "
    << two.get_size() << endl;
    cout << "three's start, expected output: (2,D), actual output: "
    << three.get_start() << endl;
    cout << "three's end, expected output: (2,B), actual output: "
    << three.get_end() << endl;
    cout << "three's size, expected output: 3, actual output: "
    << three.get_size() << endl;
    cout << "four's start, expected output: (2,B), actual output: "
    << four.get_start() << endl;
    cout << "four's end, expected output: (2,D), actual output: "
    << four.get_end() << endl;
    cout << "four's size, expected output: 3, actual output: "
    << four.get_size() << endl;


    // testing Ship::has_position here
    Position test1(2, 3);
    Position test2(0, 0);
    Position test3(2, 1);
    Position test4(1, 2);
    cout << "testing Ship::has_position(Position pos)" << endl;
    cout << "test1, Expected: 1, Actual:" << one.has_position(test1) << endl;
    cout << "test1, Expected: 1, Actual:" << two.has_position(test1) << endl;
    cout << "test2, Expected: 0, Actual:" << one.has_position(test2) << endl;
    cout << "test4, Expected: 1, Actual:" << three.has_position(test4) << endl;
    cout << "test4, Expected: 1, Actual:" << four.has_position(test4) << endl;
    cout << "test4, Expected: 0, Actual:" << three.has_position(test2) << endl;
    //Testing Ship::hit
    cout << "testing Ship::hit()" << endl;
    for (int i = 0; i < one.get_size(); i++){
        cout << "Expected: 0: Actual: " << one.has_sunk() << endl << endl;
        one.hit();
    }
    cout << "Expected: 1, Actual " << one.has_sunk() << endl << endl;
    one.hit();
    cout << "Expected: 1, Actual " << one.has_sunk() << endl << endl;
    return;
}

void test_player() {
    Player grace;
    cout << "testing Player::Player() default constructor" << endl;
    cout << "Expected: Actual:" << grace.get_name() << endl;
    cout << "Expected: 0, Actual: " << grace.get_num_ships() << endl;
    cout << "Expected: 0, Actual: " << grace.get_remaining_ships() << endl;
    cout << "Expected: empty grid" << endl;
    grace.print_grid();
    Player grace1 ("Grace");
    cout << "testing Player::Player(string name_val),"
    << " non-default constructor" << endl;
    cout << "Expected: Grace Actual: " << grace1.get_name() << endl;
    cout << "Expected: 0, Actual: " << grace1.get_num_ships() << endl;
    cout << "Expected: 0, Actual: " << grace1.get_remaining_ships() << endl;
    cout << "Expected: empty grid" << endl;
    grace1.print_grid();
    //forwards vertical
    Position main(1, 3);
    Position vertical_end(3, 3);
    Ship one(main, vertical_end);
    //backwards vertical
    Position vertical_start(3, 2);   
    Position vertical_end2(1, 2);
    Ship andy(vertical_start, vertical_end2);
    //forward horizontal
    Position horizontal_end2(4, 1);
    Position main2(4, 2);
    Ship eight(horizontal_end2, main2);
    // backward horizontal
    Position mars_start(0, 5);
    Position horizontal_end(0, 1);
    Ship mars (horizontal_end, mars_start);
    //two more ships
    Position titanic_start(7, 7);
    Position titanic_end(7, 6);
    Ship titanic(titanic_start, titanic_end);
    Ship basement;
    grace1.add_ship(one);
    cout << "expected: 1, actual: " << grace1.get_num_ships() << endl;
    grace1.print_grid();
    grace1.add_ship(andy);
    cout << "expected: 2, actual: " << grace1.get_num_ships() << endl;
    grace1.print_grid();
    grace1.add_ship(eight);
    cout << "expected: 3, actual: " << grace1.get_num_ships() << endl;
    grace1.print_grid();
    grace1.add_ship(mars);
    cout << "expected: 4, actual: " << grace1.get_num_ships() << endl;
    grace1.add_ship(titanic);
    grace1.print_grid();
    cout << "expected: 5, actual: " << grace1.get_num_ships() << endl;
    grace1.add_ship(basement);
    grace1.print_grid();
    cout << "expected: 5, actual: " << grace1.get_num_ships() << endl;
    
    cout << endl;
    Player Andy("Andy");
    Player grace2;

    cout << "THE PART WE'RE TRYING TO FIX" << endl;
    
    cout << Andy.load_grid_file("grid1.txt") << endl;
    Andy.print_grid();
    cout << "Expected: 5, Actual: " << Andy.get_num_ships() << endl;
    cout << grace2.load_grid_file("") << endl;
    cout << "Expected: 0, Actual: " << grace2.get_num_ships() << endl;
    
    Position main_vertical(2, 3);
    cout << endl << "testing attack" << endl;
    Andy.attack(grace1, main);
    grace1.print_grid();
    Andy.attack(grace1, main_vertical);
    grace1.print_grid();
    Andy.attack(grace1, vertical_end);
    grace1.print_grid();
    cout << "expected: 2, actual: " << grace1.get_remaining_ships() << endl;
    Position position1 (7,7);
    Andy.attack(grace1, position1); 
    grace1.print_grid();
//PLAYER_ATTACK
//PLAYER_LOAD_GRID_FILE
//
    return;
}

void test_game() {
    cout << "non-default game" << endl;
    Player grace("Grace");
    Player player2("Player2");
    Game game2(grace, "", player2, "");
    cout << "Grace, " << game2.get_p1().get_name() << endl;
    cout << "Player2, " << game2.get_p2().get_name() << endl;
    grace.print_grid();
    player2.print_grid();
    Player grace2("Grace2");
    Player player3("Player3");
    cout << "non-default game 2" << endl;
    
    Game game(grace2, "grid2.txt", player3, "grid2.txt");
    cout << "Grace2, " << game.get_p1().get_name() << endl;
    cout << "Player3, " << game.get_p2().get_name() << endl;
    grace2.print_grid();
    player3.print_grid();
    
    Player grace3("Grace3");
    Player player4("Player4");
    cout << "non-default game 3" << endl;
    Game game3(grace3, "planet", player4, "planet2");
    cout << "Grace3, " << game3.get_p1().get_name() << endl;
    cout << "Player4, " << game3.get_p2().get_name() << endl;
    grace3.print_grid();
    player4.print_grid();
    cout << "expected: 1, Actual: " << game2.check_valid_move("1A") << endl;
    cout << "expected: 1, Actual: " << game2.check_valid_move("1a") << endl;
    cout << "expected: 0, Actual: " << game2.check_valid_move("0a") << endl;
    cout << "expected: 0, Actual: " << game2.check_valid_move("10") << endl;
    /* need tests for GAME_CHECK_VALID_MOVE
GAME_NON_DEFAULT_CONSTRUCTOR*/
    return;
}
