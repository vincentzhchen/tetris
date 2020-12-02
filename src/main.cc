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
  int curr_rotation = 0;  // this can be randomized in the future
  int curr_col = board.get_board_width() / 2;  // initial spawn in middle
  int curr_row = 0;
  // Shape *shape = get_random_shape();  // spawn a shape
  Shape *shape = get_shape('T');  // spawn a shape

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
      if (!board.is_collide(shape, curr_row + 1, curr_col,
                            curr_rotation + 90)) {
        curr_rotation += 90;
        curr_rotation = curr_rotation > 270 ? 0 : curr_rotation;
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

      curr_rotation = 0;  // this can be randomized in the future
      curr_col = board.get_board_width() / 2;  // initial spawn in middle
      curr_row = 0;
      shape = get_random_shape();  // spawn another shape
      // shape = get_shape('O');  // spawn a shape

      // // check for line clear
      // std::vector<int> line_num =
      //     board.get_line(shape, curr_row, curr_col, curr_rotation);
      // board.draw_line(line_num);
      // board.save_state();
      // board.draw();

      // // check if the saved board is good
      // board.save_state();
      if (!board.is_valid_board()) game_over = true;
    }
    board.draw();
  }  // end while loop
  return 0;
}
