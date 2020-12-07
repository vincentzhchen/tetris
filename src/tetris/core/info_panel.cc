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
#include <tetris/core/info_panel.h>

namespace info {

NextShape::NextShape(int h, int w) : matrix::Matrix(h, w) {
  initialize_matrix();
}

void NextShape::initialize_matrix() {
  std::vector<std::vector<char>> m(height(), blank_mid_row);
  // draw the top and bottom board over the first and last row
  std::vector<char> top_bot_boarder(width(), board::HORZ_SYMBOL);
  m.at(0) = m.at(height() - 1) = top_bot_boarder;

  // put the phrase "NEXT" in the middle
  int mid = width() / 2;
  m.at(1).at(mid - 2) = 'N';
  m.at(1).at(mid - 1) = 'E';
  m.at(1).at(mid) = 'X';
  m.at(1).at(mid + 1) = 'T';

  empty_matrix = m;

  // set the active matrix
  _matrix = empty_matrix;

  // color board is parallel to active board and defaulted to white
  std::vector<std::vector<int>> cm(height(), blank_color_row);
  _color_matrix = cm;
}

void NextShape::draw_shape(Shape *shape, const int &rotation) {
  reset_matrix();
  // use the base method here
  Matrix::draw(shape, 3, width() / 2, rotation);
}

Score::Score(int h, int w) : matrix::Matrix(h, w) { initialize_matrix(); }

void Score::initialize_matrix() {
  std::vector<std::vector<char>> m(height(), blank_mid_row);
  // draw the top and bottom board over the first and last row
  std::vector<char> top_bot_boarder(width(), board::HORZ_SYMBOL);
  m.at(0) = m.at(height() - 1) = top_bot_boarder;

  m.at(1).at(3) = 'T';
  m.at(1).at(4) = 'O';
  m.at(1).at(5) = 'P';

  m.at(4).at(3) = 'S';
  m.at(4).at(4) = 'C';
  m.at(4).at(5) = 'O';
  m.at(4).at(6) = 'R';
  m.at(4).at(7) = 'E';

  empty_matrix = m;

  // set the active matrix
  _matrix = empty_matrix;
}

void Score::update_score(int score) {
  std::string str_score = std::to_string(score);
  int slen = str_score.size();
  for (int i = width() - slen - 2; i < width() - 2; i++)
    _matrix[5][i] = str_score[i + slen + 2 - width()];
}

Lines::Lines(int h, int w) : matrix::Matrix(h, w) { initialize_matrix(); }

void Lines::initialize_matrix() {
  std::vector<std::vector<char>> m(height(), blank_mid_row);
  // draw the top and bottom board over the first and last row
  std::vector<char> top_bot_boarder(width(), board::HORZ_SYMBOL);
  m.at(0) = m.at(height() - 1) = top_bot_boarder;

  m.at(1).at(3) = 'L';
  m.at(1).at(4) = 'I';
  m.at(1).at(5) = 'N';
  m.at(1).at(6) = 'E';
  m.at(1).at(7) = 'S';

  empty_matrix = m;

  // set the active matrix
  _matrix = empty_matrix;
}

void Lines::update_lines(int lines) {
  std::string str_lines = std::to_string(lines);
  int slen = str_lines.size();
  for (int i = width() - slen - 2; i < width() - 2; i++)
    _matrix[2][i] = str_lines[i + slen + 2 - width()];
}

}  // namespace info
