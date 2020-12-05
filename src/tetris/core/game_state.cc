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

#include <random>

GameState::GameState() {
  _game_over = false;
  _score = 0;
}

const int &GameState::score() { return _score; }

void GameState::update_score(const int &num_lines) {
  _score += num_lines % 4 != 0 ? 25 * num_lines : 100 * num_lines;
}

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

const bool &GameState::game_over() { return _game_over; }

void GameState::end_game() { _game_over = true; }
