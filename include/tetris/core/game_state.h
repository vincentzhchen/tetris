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
  GameState();
  const bool &game_over();
  const int &score();
  void update_score(const int &num_lines);
  void end_game();
  Shape *get_shape(char shape);
  Shape *get_random_shape();

 private:
  bool _game_over;
  int _score;
  std::array<Shape *, 7> all_shapes{new ShapeI(), new ShapeJ(), new ShapeL(),
                                    new ShapeO(), new ShapeS(), new ShapeT(),
                                    new ShapeZ()};
};
