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

#include <tetris/util/user_input.h>

bool KeyPress::is_up() { return get_key_press() == keyns::Key::UP; }
bool KeyPress::is_down() { return get_key_press() == keyns::Key::DOWN; }
bool KeyPress::is_left() { return get_key_press() == keyns::Key::LEFT; }
bool KeyPress::is_right() { return get_key_press() == keyns::Key::RIGHT; }

void KeyPress::update_key_press() {
  enable_raw_mode();
  keyns::Key kp;
  if (kbhit()) {
    switch (getch()) {
      case 'w':
        kp = keyns::Key::UP;
        break;
      case 's':
        kp = keyns::Key::DOWN;
        break;
      case 'a':
        kp = keyns::Key::LEFT;
        break;
      case 'd':
        kp = keyns::Key::RIGHT;
        break;
    }
  } else {
    kp = keyns::Key::NONE;
  }
  disable_raw_mode();
  key_press = kp;
}

keyns::Key KeyPress::get_key_press() { return key_press; }
