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

#include <array>

class GameState {
 public:
  GameState(int curr_row, int curr_col, int curr_rot);

  // game management
  const bool &game_over();
  const int &score();
  void update_score(const int &num_lines);
  void end_game();
  void apply_game_speed_delay();
  void apply_line_clear_delay();

  // shape management
  Shape *get_shape(char shape);
  Shape *get_random_shape();
  const int &curr_row();
  const int next_row();
  const int prev_col();
  const int &curr_col();
  const int next_col();
  const int &curr_rot();
  const int next_rot();
  void move_left();
  void move_right();
  void move_down();
  void rotate();
  void reset_position();

 private:
  // game management
  bool _game_over;
  int _score;

  // shape management
  std::array<Shape *, 7> all_shapes{new ShapeI(), new ShapeJ(), new ShapeL(),
                                    new ShapeO(), new ShapeS(), new ShapeT(),
                                    new ShapeZ()};

  // store this for resetting (created once and never modified)
  int _curr_rotation_init;
  int _curr_row_init;
  int _curr_col_init;

  // modify these
  int _curr_rotation;
  int _curr_row;
  int _curr_col;
};
