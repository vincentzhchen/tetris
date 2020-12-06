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

#include <tetris/core/board.h>
#include <tetris/core/game_state.h>
#include <tetris/core/shape.h>
#include <tetris/util/user_input.h>

#include <iostream>
#include <vector>

int main() {
  system("clear");  // always clear terminal first

  // setup
  Board board;
  GameState state(1, board.width() / 2, 0);
  // Shape *shape = state.get_random_shape();  // spawn a shape
  Shape *shape = state.get_shape('I');  // specific shape for debugging

  // initial spawn
  board.draw_shape(shape, state.curr_row(), state.curr_col(), state.curr_rot());
  board.draw();

  KeyPress kp;
  while (!state.game_over()) {
    kp.update_key_press();

    if (kp.is_left())
      if (!board.is_collide(shape, state.curr_row(), state.prev_col(),
                            state.curr_rot()))
        state.move_left();

    if (kp.is_right())
      if (!board.is_collide(shape, state.curr_row(), state.next_col(),
                            state.curr_rot()))
        state.move_right();

    if (kp.is_down())
      if (!board.is_collide(shape, state.next_row(), state.curr_col(),
                            state.curr_rot()))
        state.move_down();

    if (kp.is_up())
      if (!board.is_collide(shape, state.curr_row(), state.curr_col(),
                            state.next_rot()))
        state.rotate();

    board.draw_shape(shape, state.curr_row(), state.curr_col(),
                     state.curr_rot());

    // controls game speed
    state.apply_game_speed_delay();

    // apply gravity if no collision
    if (!board.is_collide(shape, state.next_row(), state.curr_col(),
                          state.curr_rot())) {
      state.move_down();
    } else {  // otherwise save state of board
      board.save_state();

      // check for line clear
      std::vector<int> line_num = board.get_line(
          shape, state.curr_row(), state.curr_col(), state.curr_rot());
      board.draw_line(line_num);
      board.save_state();

      // show the line clear
      board.draw();
      state.apply_line_clear_delay();  // delay to keep visible

      int num_lines = board.clear_line(line_num);
      state.update_score(num_lines);
      board.save_state();

      // check if the saved board is good
      if (board.is_valid_board()) {  // reset state if it is
        state.reset_position();
        shape = state.get_random_shape();  // spawn another shape
      } else {
        // game over if board is not valid
        state.end_game();
      }
    }

    board.draw();
    std::cout << "SCORE: " << state.score() << std::endl;
  }  // end while loop
  return 0;
}
