#include <tetris/core/board.h>
#include <tetris/core/shape.h>

#include <iostream>
#include <vector>

int main() {
  system("clear");  // always clear terminal first

  // setup
  int curr_rotation = 0;  // this can be randomized in the future
  int curr_col = -1;      // -1 here for initial spawn
  int curr_row = 0;

  Board board;

  // spawn a shape
  Shape *shape = get_random_shape();

  board.draw_shape(shape, curr_row, curr_col, curr_rotation);
  board.draw();

  return 0;
}
