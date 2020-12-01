#pragma once

#include <tetris/core/shape.h>

#include <vector>

class Board {
 public:
  // standard board size is 10 wide and 20 high
  explicit Board(int height = 20, int width = 10);  // constructor
  int get_board_height();
  int get_board_width();
  void draw();
  void draw_shape(Shape *shape, int row = 0, int col = -1, int rotation = 0);

 private:
  int width;   // nun cols
  int height;  // num rows
  std::vector<std::vector<char>> empty_board;
  std::vector<std::vector<char>> board;

  void initialize_board(int height, int width);
  void set_board(std::vector<std::vector<char>> b);
  void reset_board();
  bool is_collide(Shape *shape, int row, int col, int rotation);
};
