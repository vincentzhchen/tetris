#include <tetris/core/board.h>

#include <iostream>

/**
 * Construct a board on instantiation.
 */
Board::Board(int h, int w) {
  height = h + 4;     // 4 hidden rows
  width = w * 2 + 4;  // * 2 for double width block, +4 for left/right boarder
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
}

/**
 * Use this to help reset the board.
 */
void Board::set_board(std::vector<std::vector<char>> b) { board = b; }
void Board::reset_board() { board = empty_board; }

/**
 * Prints board to console.
 */
void Board::draw() {
  system("clear");
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
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
  unsigned int h = get_board_height();
  unsigned int w = get_board_width();
  for (size_t r = 0; r < s.size(); r++)
    // s.size() * 2 because using double spacing tiles: []
    for (size_t c = 0; c < s.size() * 2; c++) {
      if (c + col > 1 && c + col < w - 2) {
        if (r + row > 0 && r + row < h) {
          if ((s[r][c] == '[' || s[r][c] == ']') && (board[r][c] != ' '))
            return true;
        }
      }
    }
  return false;
}

void Board::draw_shape(Shape *shape, int row, int col, int rotation) {
  if (col == -1) col = get_board_width() / 2;  // initial spawn is in middle
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  for (size_t r = 0; r < s.size(); r++)
    // s.size() * 2 because using double spacing tiles: []
    for (size_t c = 0; c < s.size() * 2; c++) {
      // -4 for wall offset (2 spaces for each side)
      board[r + row][c + col - 4] = s[r][c];
    }
}
