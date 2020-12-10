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
Board::Board(int h, int w) : matrix::Matrix(h, w) { initialize_matrix(); }

void Board::initialize_matrix() {
  std::vector<std::vector<char>> m(height(), blank_mid_row);
  // draw the top and bottom board over the first and last row
  std::vector<char> top_bot_boarder(width(), board::HORZ_SYMBOL);
  m.at(0) = m.at(height() - 1) = top_bot_boarder;

  empty_matrix = m;

  // set the active board
  _matrix = empty_matrix;

  // fixed board is the same as the active board on initialization
  fixed_matrix = empty_matrix;

  // color board is parallel to active board and defaulted to white
  std::vector<std::vector<int>> cm(height(), blank_color_row);
  _color_matrix = cm;
}

void Board::set_matrix(std::vector<std::vector<char>> m) { _matrix = m; }

void Board::set_fixed_matrix(std::vector<std::vector<char>> m) {
  fixed_matrix = m;
}

void Board::save_state() { fixed_matrix = _matrix; }

/**
 * This draws a shape onto the board.  Nothing to console.
 */
void Board::draw_shape(Shape *shape, const int &row, const int &col,
                       const int &rotation) {
  set_matrix(fixed_matrix);
  Matrix::draw(shape, row, col, rotation);
}

void Board::draw_line(const std::vector<int> &row) {
  std::vector<char> line_clear(width(), board::LINE_SYMBOL);
  line_clear.at(0) = line_clear.at(width() - 1) = board::EMPTY_SYMBOL;
  line_clear.at(1) = line_clear.at(width() - 2) = board::VERT_SYMBOL;
  for (size_t r = 0; r < row.size(); r++) matrix()[row[r]] = line_clear;
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
            (fixed_matrix[y][x] != board::EMPTY_SYMBOL))
          return true;
    }

  return false;
}

bool Board::is_valid_board() {
  // this is first row that can have a tetris piece
  std::vector<char> &first_field_row = fixed_matrix[board::OFFSET_FROM_TOP];
  for (size_t c = board::OFFSET_FROM_LEFT;
       c < first_field_row.size() - board::OFFSET_FROM_RIGHT; c++)
    // if any of the pieces are on the first field row,
    // then the board is invalid
    if (first_field_row[c] != board::EMPTY_SYMBOL) return false;
  return true;
}

std::vector<int> Board::get_line(Shape *shape, const int &row, const int &col,
                                 const int &rotation) {
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  std::vector<int> line_num;
  line_num.reserve(4);  // cannot be more than 4 lines
  // for the placed shape...
  for (size_t r = 0; r < s.size(); r++) {
    int y = r + row;
    if (y < height()) {
      // if half the playing field is the left of a block, then this is a line
      if (std::count(fixed_matrix[y].begin(), fixed_matrix[y].end(),
                     '[') == (width() - board::OFFSET_LR) / 2) {
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

  matrix().erase(matrix().begin() + row[0],
                 matrix().begin() + row[0] + num_rows_to_modify);

  color_matrix().erase(color_matrix().begin() + row[0],
                       color_matrix().begin() + row[0] + num_rows_to_modify);

  // insert back deleted rows at the top
  for (int i = 0; i < num_rows_to_modify; i++) {
    matrix().insert(matrix().begin() + board::OFFSET_FROM_TOP, blank_mid_row);
    color_matrix().insert(color_matrix().begin() + board::OFFSET_FROM_TOP,
                          blank_color_row);
  }

  return num_rows_to_modify;
}
