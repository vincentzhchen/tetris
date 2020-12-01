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

#include <tetris/util/kb_io.h>

namespace keyns {
enum Key { UP, DOWN, LEFT, RIGHT, NONE };
}

class KeyPress {
 public:
  void update_key_press();
  bool is_up();
  bool is_down();
  bool is_left();
  bool is_right();

 private:
  keyns::Key key_press = keyns::Key::NONE;
  keyns::Key get_key_press();
};
