#ifndef EVALUATION_H
#define EVALUATION_H

#include "Board.h"
#include "Move.h"
#include "Search.h"
#include<vector>
// pair for minimax algorithm
typedef std::pair<Board, int> eval_pair;

// Depth first search tree which implements alpha-beta pruning
eval_pair mini_max(Board currBoard, int alpha, int beta, bool is_max_player);

// evaluates the current board state
int evaluate(Board currBoard);

// gets the value of a piece at a give location
int get_piece_value(Piece p, int x, int y);

//calls generateMoveList, makes each move and appends to vector to be processed later.
std::vector<Board> get_states(Board curr);

// board evaluation tables
// Pawn evaluation tables
const double white_pawn_eval[8][8] = {{ 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0},
                                      { 5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0},
                                      { 1.0,  1.0,  2.0,  3.0,  3.0,  2.0,  1.0,  1.0},
                                      { 0.5,  0.5,  1.0,  2.5,  2.5,  1.0,  0.5,  0.5},
                                      { 0.0,  0.0,  0.0,  2.0,  2.0,  0.0,  0.0,  0.0},
                                      { 0.5, -0.5, -1.0,  0.0,  0.0, -1.0, -0.5,  0.5},
                                      { 0.5,  1.0,  1.0, -2.0, -2.0,  1.0,  1.0,  0.5},
                                      { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}};

const double black_pawn_eval[8][8] = {{ 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0},
                                      { 0.5,  1.0,  1.0, -2.0, -2.0,  1.0,  1.0,  0.5},
                                      { 0.5, -0.5, -1.0,  0.0,  0.0, -1.0, -0.5,  0.5},
                                      { 0.0,  0.0,  0.0,  2.0,  2.0,  0.0,  0.0,  0.0},
                                      { 0.5,  0.5,  1.0,  2.5,  2.5,  1.0,  0.5,  0.5},
                                      { 1.0,  1.0,  2.0,  3.0,  3.0,  2.0,  1.0,  1.0},
                                      { 5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0},
                                      { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}};


// Knight evaluation tables
const double white_knight_eval[8][8] = {{ -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0},
                                        { -4.0, -2.0,  0.0,  0.0,  0.0,  0.0, -2.0, -4.0},
                                        { -3.0,  0.0,  1.0,  1.5,  1.5,  1.0,  0.0, -3.0},
                                        { -3.0,  0.5,  1.5,  2.0,  2.0,  1.5,  0.5, -3.0},
                                        { -3.0,  0.0,  1.5,  2.0,  2.0,  1.5,  0.0, -3.0},
                                        { -3.0,  0.5,  1.0,  1.5,  1.5,  1.0,  0.5, -3.0},
                                        { -4.0, -2.0,  0.0,  0.5,  0.5,  0.0, -2.0, -4.0},
                                        { -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0}};

const double black_knight_eval[8][8] = {{ -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0},
                                        { -4.0, -2.0,  0.0,  0.5,  0.5,  0.0, -2.0, -4.0},
                                        { -3.0,  0.5,  1.0,  1.5,  1.5,  1.0,  0.5, -3.0},
                                        { -3.0,  0.0,  1.5,  2.0,  2.0,  1.5,  0.0, -3.0},
                                        { -3.0,  0.5,  1.5,  2.0,  2.0,  1.5,  0.5, -3.0},
                                        { -3.0,  0.0,  1.0,  1.5,  1.5,  1.0,  0.0, -3.0},
                                        { -4.0, -2.0,  0.0,  0.0,  0.0,  0.0, -2.0, -4.0},
                                        { -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0}};


// Bishop evaluation tables
const double white_bishop_eval[8][8] = {{ -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0},
                                        { -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0},
                                        { -1.0,  0.0,  0.5,  1.0,  1.0,  0.5,  0.0, -1.0},
                                        { -1.0,  0.5,  0.5,  1.0,  1.0,  0.5,  0.5, -1.0},
                                        { -1.0,  0.0,  1.0,  1.0,  1.0,  1.0,  0.0, -1.0},
                                        { -1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, -1.0},
                                        { -1.0,  0.5,  0.0,  0.0,  0.0,  0.0,  0.5, -1.0},
                                        { -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0}};

const double black_bishop_eval[8][8] = {{ -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0},
                                        { -1.0,  0.5,  0.0,  0.0,  0.0,  0.0,  0.5, -1.0},
                                        { -1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, -1.0},
                                        { -1.0,  0.0,  1.0,  1.0,  1.0,  1.0,  0.0, -1.0},
                                        { -1.0,  0.5,  0.5,  1.0,  1.0,  0.5,  0.5, -1.0},
                                        { -1.0,  0.0,  0.5,  1.0,  1.0,  0.5,  0.0, -1.0},
                                        { -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0},
                                        { -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0}};


// Rook evaluation tables
const double white_rook_eval[8][8] = {{  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0},
                                      {  0.5,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      {  0.0,  0.0,  0.0,  0.5,  0.5,  0.0,  0.0,  0.0}};

const double black_rook_eval[8][8] = {{  0.0,  0.0,  0.0,  0.5,  0.5,  0.0,  0.0,  0.0},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      { -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
                                      {  0.5,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  0.5},
                                      {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}};


// Queen evaluation tables
const double white_queen_eval[8][8] = {{ -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0},
                                       { -1.0,  0.0,  0.0,  0.0,  0.0,  0.5,  0.0, -1.0},
                                       { -1.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.5, -1.0},
                                       { -0.5,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5},
                                       {  0.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5},
                                       { -1.0,  0.5,  0.5,  0.5,  0.5,  0.5,  0.0, -1.0},
                                       { -1.0,  0.0,  0.5,  0.0,  0.0,  0.0,  0.0, -1.0},
                                       { -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0}};

const double black_queen_eval[8][8] = {{ -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0},
                                       { -1.0,  0.0,  0.0,  0.0,  0.0,  0.5,  0.0, -1.0},
                                       { -1.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.5, -1.0},
                                       { -0.5,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5},
                                       {  0.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5},
                                       { -1.0,  0.5,  0.5,  0.5,  0.5,  0.5,  0.0, -1.0},
                                       { -1.0,  0.0,  0.5,  0.0,  0.0,  0.0,  0.0, -1.0},
                                       { -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0}};


// King evaluation tables
const double white_king_eval[8][8] = {{ -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
                                      { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
                                      { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
                                      { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
                                      { -2.0, -3.0, -3.0, -4.0, -4.0, -3.0, -3.0, -2.0},
                                      { -1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -1.0},
                                      {  2.0,  2.0,  0.0,  0.0,  0.0,  0.0,  2.0,  2.0},
                                      {  2.0,  3.0,  1.0,  0.0,  0.0,  1.0,  3.0,  2.0}};

const double black_king_eval[8][8] = {{  2.0,  3.0,  1.0,  0.0,  0.0,  1.0,  3.0,  2.0},
                                      {  2.0,  2.0,  0.0,  0.0,  0.0,  0.0,  2.0,  2.0},
                                      { -1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -1.0},
                                      { -2.0, -3.0, -3.0, -4.0, -4.0, -3.0, -3.0, -2.0},
                                      { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
                                      { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
                                      { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
                                      { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0}};



#endif