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

#include <tetris/core/game_state.h>
#include <unistd.h>

#include <random>

GameState::GameState(int curr_row, int curr_col, int curr_rot) {
  _game_over = false;
  _score = 0;

  _curr_row_init = curr_row;
  _curr_col_init = curr_col;
  _curr_rotation_init = curr_rot;

  reset_position();
}

const int &GameState::score() { return _score; }

void GameState::update_score(const int &num_lines) {
  _score += num_lines % 4 != 0 ? 25 * num_lines : 100 * num_lines;
}

const bool &GameState::game_over() { return _game_over; }

void GameState::end_game() { _game_over = true; }

void GameState::apply_game_speed_delay() {
  // this is in microseconds
  usleep(200000);
}

void GameState::apply_line_clear_delay() { usleep(50000); }

Shape *GameState::get_shape(char shape) {
  if (shape == 'I') {
    return all_shapes[0];
  } else if (shape == 'J') {
    return all_shapes[1];
  } else if (shape == 'L') {
    return all_shapes[2];
  } else if (shape == 'O') {
    return all_shapes[3];
  } else if (shape == 'S') {
    return all_shapes[4];
  } else if (shape == 'T') {
    return all_shapes[5];
  } else {
    return all_shapes[6];
  }
}

Shape *GameState::get_random_shape() {
  char choices[] = "IJLOSTZ";  // all the kinds of shapes
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<int> uniform(0, 6);
  char choice = choices[uniform(generator)];
  return get_shape(choice);
}

const int &GameState::curr_row() { return _curr_row; }
const int GameState::next_row() { return curr_row() + 1; }
const int GameState::prev_col() { return curr_col() - 2; }
const int &GameState::curr_col() { return _curr_col; }
const int GameState::next_col() { return curr_col() + 2; }
const int &GameState::curr_rot() { return _curr_rotation; }
const int GameState::next_rot() { return (curr_rot() + 90) % 360; }

void GameState::move_left() { _curr_col -= 2; }
void GameState::move_right() { _curr_col += 2; }
void GameState::move_down() { _curr_row += 1; }
void GameState::rotate() { _curr_rotation = (_curr_rotation + 90) % 360; }
void GameState::reset_position() {
  _curr_rotation = _curr_rotation_init;
  _curr_row = _curr_row_init;
  _curr_col = _curr_col_init;
}
