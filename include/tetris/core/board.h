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
  void draw_shape(Shape *shape, int row, int col, int rotation);
  bool is_collide(Shape *shape, int row, int col, int rotation);
  void save_state();
  bool is_valid_board();
  std::vector<int> get_line(Shape *shape, int row, int col, int rotation);
  void draw_line(std::vector<int> row);
  int clear_line(std::vector<int> row);

 private:
  int width;   // nun cols
  int height;  // num rows
  std::vector<std::vector<char>> empty_board;
  std::vector<std::vector<char>> fixed_board;  // holds fixed position items
  std::vector<std::vector<char>> board;

  void initialize_board(int height, int width);
  void set_board(std::vector<std::vector<char>> b);
  void set_fixed_board(std::vector<std::vector<char>> b);
  void reset_board();
};
