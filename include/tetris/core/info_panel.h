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

#include <tetris/core/matrix.h>
#include <tetris/core/shape.h>

#include <vector>

namespace info {
class NextShape : public matrix::Matrix {
 public:
  explicit NextShape(int height = 7, int width = 5);  // constructor

  // drawing
  void draw_shape(Shape *shape, const int &rotation);

 private:
  virtual void initialize_matrix();
};

class Score : public matrix::Matrix {
 public:
  explicit Score(int height = 6, int width = 5);  // constructor
  void update_score(int score);

 private:
  virtual void initialize_matrix();
};

class Lines : public matrix::Matrix {
 public:
  explicit Lines(int height = 3, int width = 5);  // constructor
  void update_lines(int lines);

 private:
  virtual void initialize_matrix();
};

}  // namespace info
