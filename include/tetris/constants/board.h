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

namespace board {

// boarder offsets
const int LEFT_BORDER_WIDTH = 2;
const int RIGHT_BORDER_WIDTH = 2;
const int TOP_BORDER_WIDTH = 1;
const int BOTTOM_BORDER_WIDTH = 1;

// + 0, no offset aside from the border width for now
const int OFFSET_FROM_TOP = TOP_BORDER_WIDTH + 0;
const int OFFSET_FROM_LEFT = LEFT_BORDER_WIDTH + 0;
const int OFFSET_FROM_RIGHT = RIGHT_BORDER_WIDTH + 0;
const int OFFSET_LR = OFFSET_FROM_LEFT + OFFSET_FROM_RIGHT;

// boarder symbols
const char EMPTY_SYMBOL = ' ';
const char HORZ_SYMBOL = '-';
const char VERT_SYMBOL = '|';
const char LINE_SYMBOL = '=';

}  // namespace board
