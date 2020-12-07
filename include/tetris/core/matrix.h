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

#pragma once

#include <tetris/core/shape.h>

#include <vector>

namespace matrix {
class Matrix {
 public:
  explicit Matrix(int height = 0, int width = 0);  // constructor

  // setters and getters
  virtual int height(bool incl_border = true);
  virtual int width(bool incl_border = true);
  virtual std::vector<std::vector<char>> &matrix();
  virtual std::vector<std::vector<int>> &color_matrix();

 protected:
  int _width;   // nun cols for playing field
  int _height;  // num rows for playing field
  std::vector<std::vector<char>> empty_matrix;
  std::vector<std::vector<int>> _color_matrix;  // holds ansi color code
  std::vector<std::vector<char>> _matrix;
  std::vector<char> blank_mid_row;
  std::vector<int> blank_color_row;

  virtual void set_height(int height);
  virtual void set_width(int width);

  virtual void initialize_matrix();
  virtual void reset_matrix();

  virtual void draw(Shape *shape, const int &row, const int &col,
                    const int &rotation);
};

}  // namespace matrix
