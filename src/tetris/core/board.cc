#include <tetris/core/board.h>

#include <algorithm>
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

void Board::save_state() { fixed_board = board; }

bool Board::is_valid_board() {
  for (size_t c = 0; c < fixed_board[3].size(); c++)
    if (fixed_board[3][c] != ' ') return false;
  return true;
}

std::vector<int> Board::get_line(Shape *shape, int row, int col, int rotation) {
  std::vector<std::vector<char>> s = shape->get_orientation(rotation);
  std::vector<int> line_num;
  // for the placed shape...
  for (size_t r = 0; r < s.size(); r++) {
    int check_row = r + row;
    if (check_row < get_board_height()) {
      // if there is only 2 white space from boarder, this is a line
      if (std::count(fixed_board[r + row].begin(), fixed_board[r + row].end(),
                     ' ') == 2) {
        line_num.push_back(check_row);
      }
    }  // bottom border guard
  }    // for loop
  return line_num;
}

void Board::draw_line(std::vector<int> row) {
  for (size_t r = 0; r < row.size(); r++)
    for (int c = 2; c < get_board_width() - 2; c++) board[row[r]][c] = '=';
}

int Board ::clear_line(std::vector<int> row) {
  int num_rows_to_modify = row.size();
  if (num_rows_to_modify == 0) return 0;

  board.erase(board.begin() + row[0],
              board.begin() + row[0] + num_rows_to_modify);

  // insert back deleted rows at the top
  std::vector<char> blank_row;
  for (int i = 0; i < get_board_width(); i++) {
    if (i == 1 || i == get_board_width() - 2)
      blank_row.push_back('|');
    else
      blank_row.push_back(' ');
  }

  for (int i = 0; i < num_rows_to_modify; i++)
    board.insert(board.begin() + 4, blank_row);

  return num_rows_to_modify;
}
