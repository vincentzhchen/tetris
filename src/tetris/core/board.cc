// Tetris console game.
// Copyright (C) 2020  Vincent Chen

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <tetris/constants/board.h>
#include <tetris/core/board.h>

#include <algorithm>
#include <iostream>

/**
 * Construct a board on instantiation.
 */
Board::Board(int h, int w) {
  _height = h;
  _width = w * 2;  // * 2 because this game uses double-width block

  std::vector<char> _mid_row(width(), board::EMPTY_SYMBOL);
  // draw the left and right board onto the empty row
  _mid_row.at(1) = _mid_row.at(width() - 2) = board::VERT_SYMBOL;
  blank_mid_row = _mid_row;  // store this, frequently used

  std::vector<int> _blank_color_row(width(), color::WHITE);
  blank_color_row = _blank_color_row;  // store this, frequently used

  initialize_board();
}

int Board::height(bool incl_boarder) {
  if (incl_boarder) {
    return _height + board::TOP_BORDER_WIDTH + board::BOTTOM_BORDER_WIDTH;
  } else {
    return _height;
  }
}

int Board::width(bool incl_boarder) {
  if (incl_boarder) {
    return _width + board::LEFT_BORDER_WIDTH + board::RIGHT_BORDER_WIDTH;
  } else {
    return _width;
  }
}

/**
 * Creates the game map in a matrix (vector of vector).
 */
void Board::initialize_board() {
  std::vector<std::vector<char>> b(height(), blank_mid_row);
  // draw the top and bottom board over the first and last row
  std::vector<char> top_bot_boarder(width(), board::HORZ_SYMBOL);
  b.at(0) = b.at(height() - 1) = top_bot_boarder;

  empty_board = b;

  // set the active board
  set_board(empty_board);

  // fixed board is the same as the active board on initialization
  set_fixed_board(empty_board);

  // color board is parallel to active board and defaulted to white
  std::vector<std::vector<int>> cb(height(), blank_color_row);
  color_board = cb;
}

/**
 * Use this to help reset the board.
 */
void Board::reset_board() { board = empty_board; }

void Board::set_board(std::vector<std::vector<char>> b) { board = b; }

void Board::set_fixed_board(std::vector<std::vector<char>> b) {
  fixed_board = b;
}

std::vector<std::vector<char>> Board::get_board() { return board; }
std::vector<std::vector<int>> Board::get_color_board() { return color_board; }

void Board::save_state() { fixed_board = board; }

/**
 * Prints board to console.
 */
void Board::draw() {
  system("clear");
  for (int i = 0; i < height(); i++) {
    for (int j = 0; j < width(); j++) {
      if ((board[i][j] == '[') || (board[i][j] == ']'))
        std::cout << "\033[1;" << color_board[i][j] << "m" << board[i][j]
                  << "\033[0m";
      else
        std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}

/**
 * This draws a shape onto the board.  Nothing to console.
 */
void Board::draw_shape(Shape *shape, const int &row, const int &col,
                       const int &rotation) {
  set_board(fixed_board);
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  for (size_t r = 0; r < s.size(); r++)
    // s.size() * 2 because using double spacing tiles: []
    for (size_t c = 0; c < s.size() * 2; c++) {
      int y = r + row;
      int x = c + col - board::OFFSET_LR;
      if ((s[r][c] != board::EMPTY_SYMBOL) && (y >= board::OFFSET_FROM_TOP)) {
        board[y][x] = s[r][c];
        color_board[y][x] = shape->color();
      }
    }
}

void Board::draw_line(const std::vector<int> &row) {
  std::vector<char> line_clear(width(), board::LINE_SYMBOL);
  line_clear.at(0) = line_clear.at(width() - 1) = board::EMPTY_SYMBOL;
  line_clear.at(1) = line_clear.at(width() - 2) = board::VERT_SYMBOL;
  for (size_t r = 0; r < row.size(); r++) board[row[r]] = line_clear;
}

/**
 * Let the board check for collision since it has access to all the data.
 */
bool Board::is_collide(Shape *shape, const int &row, const int &col,
                       const int &rotation) {
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  for (size_t r = 0; r < s.size(); r++)
    // s.size() * 2 because using double spacing tiles: []
    for (size_t c = 0; c < s.size() * 2; c++) {
      int y = r + row;
      int x = c + col - board::OFFSET_LR;
      if (y >= board::OFFSET_FROM_TOP)
        if ((s[r][c] == '[' || s[r][c] == ']') &&
            (fixed_board[y][x] != board::EMPTY_SYMBOL))
          return true;
    }

  return false;
}

bool Board::is_valid_board() {
  std::vector<char> &first_field_row = fixed_board[board::OFFSET_FROM_TOP];
  for (size_t c = board::OFFSET_FROM_LEFT;
       c < first_field_row.size() - board::OFFSET_FROM_RIGHT; c++)
    if (first_field_row[c] != board::EMPTY_SYMBOL) return false;
  return true;
}

std::vector<int> Board::get_line(Shape *shape, const int &row, const int &col,
                                 const int &rotation) {
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  std::vector<int> line_num;
  // for the placed shape...
  for (size_t r = 0; r < s.size(); r++) {
    int y = r + row;
    if (y < height()) {
      // if there is only 2 white space from boarder, this is a line
      if (std::count(fixed_board[y].begin(), fixed_board[y].end(),
                     board::EMPTY_SYMBOL) == 2) {
        line_num.push_back(y);
      }
    }  // bottom border guard
  }    // for loop
  return line_num;
}

/**
 * Clear lines and return number of lines cleared.
 */
int Board ::clear_line(const std::vector<int> &row) {
  int num_rows_to_modify = row.size();
  if (num_rows_to_modify == 0) return num_rows_to_modify;

  board.erase(board.begin() + row[0],
              board.begin() + row[0] + num_rows_to_modify);

  color_board.erase(color_board.begin() + row[0],
                    color_board.begin() + row[0] + num_rows_to_modify);

  // insert back deleted rows at the top
  for (int i = 0; i < num_rows_to_modify; i++) {
    board.insert(board.begin() + board::OFFSET_FROM_TOP, blank_mid_row);
    color_board.insert(color_board.begin() + board::OFFSET_FROM_TOP,
                       blank_color_row);
  }

  return num_rows_to_modify;
}
