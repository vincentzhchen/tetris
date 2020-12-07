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
#include <tetris/constants/color.h>
#include <tetris/core/matrix.h>

#include <stdexcept>

namespace matrix {

Matrix::Matrix(int h, int w) {
  _height = h;
  _width = w * 2;  // * 2 because this game uses double-width block

  std::vector<char> _mid_row(width(), board::EMPTY_SYMBOL);
  // draw the left and right board onto the empty row
  _mid_row.at(1) = _mid_row.at(width() - 2) = board::VERT_SYMBOL;
  blank_mid_row = _mid_row;  // store this, frequently used

  std::vector<int> _blank_color_row(width(), color::WHITE);
  blank_color_row = _blank_color_row;  // store this, frequently used
}

int Matrix::height(bool incl_border) {
  if (incl_border) {
    return _height + board::TOP_BORDER_WIDTH + board::BOTTOM_BORDER_WIDTH;
  } else {
    return _height;
  }
}

int Matrix::width(bool incl_border) {
  if (incl_border) {
    return _width + board::LEFT_BORDER_WIDTH + board::RIGHT_BORDER_WIDTH;
  } else {
    return _width;
  }
}

std::vector<std::vector<char>> &Matrix::matrix() { return _matrix; }
std::vector<std::vector<int>> &Matrix::color_matrix() { return _color_matrix; }

void Matrix::set_height(int height) { _height = height; }
void Matrix::set_width(int width) { _width = width; }
void Matrix::initialize_matrix() { throw std::logic_error("Not implemented."); }
void Matrix::reset_matrix() { _matrix = empty_matrix; }

/**
 * Generic method to draw the shape.
 */
void Matrix::draw(Shape *shape, const int &row, const int &col,
                  const int &rotation) {
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  for (size_t r = 0; r < s.size(); r++)
    // s.size() * 2 because using double spacing tiles: []
    for (size_t c = 0; c < s.size() * 2; c++) {
      int y = r + row;
      int x = c + col - board::OFFSET_LR;
      if ((s[r][c] != board::EMPTY_SYMBOL) && (y >= board::OFFSET_FROM_TOP)) {
        matrix()[y][x] = s[r][c];
        color_matrix()[y][x] = shape->color();
      }
    }
}

}  // namespace matrix
