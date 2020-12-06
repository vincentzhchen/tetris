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
/**
 * Construct a panel on instantiation.
 */
NextShape::NextShape(int h, int w) {
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

int NextShape::height(bool incl_boarder) {
  if (incl_boarder) {
    return _height + board::TOP_BORDER_WIDTH + board::BOTTOM_BORDER_WIDTH;
  } else {
    return _height;
  }
}

int NextShape::width(bool incl_boarder) {
  if (incl_boarder) {
    return _width + board::LEFT_BORDER_WIDTH + board::RIGHT_BORDER_WIDTH;
  } else {
    return _width;
  }
}

void NextShape::initialize_board() {
  std::vector<std::vector<char>> b(height(), blank_mid_row);
  // draw the top and bottom board over the first and last row
  std::vector<char> top_bot_boarder(width(), board::HORZ_SYMBOL);
  b.at(0) = b.at(height() - 1) = top_bot_boarder;

  // put the phrase "NEXT" in the middle
  int mid = width() / 2;
  b.at(1).at(mid - 2) = 'N';
  b.at(1).at(mid - 1) = 'E';
  b.at(1).at(mid) = 'X';
  b.at(1).at(mid + 1) = 'T';

  empty_board = b;

  // set the active board
  set_board(empty_board);

  // color board is parallel to active board and defaulted to white
  std::vector<std::vector<int>> cb(height(), blank_color_row);
  color_board = cb;
}

void NextShape::reset_board() { board = empty_board; }

void NextShape::draw_shape(Shape *shape, const int &rotation) {
  reset_board();
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  for (size_t r = 0; r < s.size(); r++)
    // s.size() * 2 because using double spacing tiles: []
    for (size_t c = 0; c < s.size() * 2; c++) {
      int y = r + 3;  // offset of 3 to allow for blank row below "NEXT"
      int x = c + width() / 2 - board::OFFSET_LR;
      if ((s[r][c] != board::EMPTY_SYMBOL) && (y >= board::OFFSET_FROM_TOP)) {
        board[y][x] = s[r][c];
        color_board[y][x] = shape->color();
      }
    }
}

void NextShape::set_board(std::vector<std::vector<char>> b) { board = b; }
std::vector<std::vector<char>> NextShape::get_board() { return board; }
std::vector<std::vector<int>> NextShape::get_color_board() {
  return color_board;
}

}  // namespace info
