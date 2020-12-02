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
#include <tetris/core/shape.h>
#include <tetris/util/user_input.h>
#include <unistd.h>

#include <iostream>
#include <vector>

int main() {
  system("clear");  // always clear terminal first

  // setup
  Board board;
  int score = 0;

  int curr_rotation = 270;  // this can be randomized in the future
  int curr_col = board.get_board_width() / 2;  // initial spawn in middle
  int curr_row = 0;
  // Shape *shape = get_random_shape();  // spawn a shape
  Shape *shape = get_shape('O');  // spawn a shape

  board.draw_shape(shape, curr_row, curr_col, curr_rotation);
  board.draw();

  KeyPress kp;
  bool game_over = false;
  while (!game_over) {
    kp.update_key_press();

    if (kp.is_left()) {
      if (!board.is_collide(shape, curr_row, curr_col - 2, curr_rotation)) {
        curr_col -= 2;
      }
    }

    if (kp.is_right()) {
      if (!board.is_collide(shape, curr_row, curr_col + 2, curr_rotation)) {
        curr_col += 2;
      }
    }

    if (kp.is_down()) {
      if (!board.is_collide(shape, curr_row + 1, curr_col, curr_rotation)) {
        curr_row += 1;
      }
    }

    if (kp.is_up()) {
      if (!board.is_collide(shape, curr_row, curr_col, curr_rotation + 90)) {
        curr_rotation += 90;
        curr_rotation %= 360;
      }
    }

    // board.draw();
    board.draw_shape(shape, curr_row, curr_col, curr_rotation);

    usleep(150000);  // this is in microseconds

    // apply gravity if no collision
    if (!board.is_collide(shape, curr_row + 1, curr_col, curr_rotation)) {
      curr_row++;
    } else {  // otherwise save state of board
      board.save_state();

      // check for line clear
      std::vector<int> line_num =
          board.get_line(shape, curr_row, curr_col, curr_rotation);
      board.draw_line(line_num);
      board.save_state();
      board.draw();

      usleep(50000);
      int num_lines = board.clear_line(line_num);
      score += num_lines % 4 != 0 ? 25 * num_lines : 100 * num_lines;
      board.save_state();

      // check if the saved board is good
      if (board.is_valid_board()) {  // reset state if it is
        curr_rotation = 0;           // this can be randomized in the future
        curr_col = board.get_board_width() / 2;  // initial spawn in middle
        curr_row = 0;
        shape = get_random_shape();  // spawn another shape
      } else {                       // game over
        game_over = true;
      }
    }

    board.draw();
    std::cout << "SCORE: " << score << std::endl;
  }  // end while loop
  return 0;
}
