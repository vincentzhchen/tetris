#include <tetris/core/board.h>

#include <iostream>

/**
 * Construct a board on instantiation.
 */
Board::Board(int h, int w) {
  height = h + 4 + 1;  // 4 hidden rows + 1 bottom border
  width = w * 2 + 4;   // * 2 for double width block, +4 for left/right boarder
  initialize_board(height, width);
}

/**
 * Creates the game map in a matrix (vector of vector).
 */
void Board::initialize_board(int height, int width) {
  for (int i = 0; i < height; i++) {
    std::vector<char> row;
    if (i < 4) {
      // hidden rows for shape spawn
      for (int j = 0; j < width; j++) row.push_back(' ');
    } else if (i == height - 1) {
      // bottom border
      for (int j = 0; j < width; j++) row.push_back('-');
    } else {
      // the actual board
      for (int j = 0; j < width; j++) {
        if ((j == 1) | (j == width - 2)) {
          row.push_back('|');
        } else {
          row.push_back(' ');
        }
      }
    }
    empty_board.push_back(row);
  }
  set_board(empty_board);
  set_fixed_board(empty_board);
}

/**
 * Use this to help reset the board.
 */
void Board::reset_board() { board = empty_board; }

void Board::set_board(std::vector<std::vector<char>> b) { board = b; }

void Board::set_fixed_board(std::vector<std::vector<char>> b) {
  fixed_board = b;
}

/**
 * Prints board to console.
 */
void Board::draw() {
  system("clear");
  for (int i = 0; i < get_board_height(); i++) {
    for (int j = 0; j < get_board_width(); j++) {
      std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}

int Board::get_board_height() { return height; }

int Board::get_board_width() { return width; }

/**
 * Let the board check for collision since it has access to all the data.
 */
bool Board::is_collide(Shape *shape, int row, int col, int rotation) {
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  col -= 4;  // remove offset
  for (size_t r = 0; r < s.size(); r++)
    // s.size() * 2 because using double spacing tiles: []
    for (size_t c = 0; c < s.size() * 2; c++) {
      if ((s[r][c] == '[' || s[r][c] == ']') &&
          (fixed_board[r + row][c + col] != ' '))
        return true;
    }

  return false;
}

/**
 * This draws a shape onto the board.  Nothing to console.
 */
void Board::draw_shape(Shape *shape, int row, int col, int rotation) {
  set_board(fixed_board);
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  for (size_t r = 0; r < s.size(); r++)
    // s.size() * 2 because using double spacing tiles: []
    for (size_t c = 0; c < s.size() * 2; c++) {
      if (s[r][c] != ' ')
        // -4 for wall offset (2 spaces for each side)
        board[r + row][c + col - 4] = s[r][c];
    }
}
