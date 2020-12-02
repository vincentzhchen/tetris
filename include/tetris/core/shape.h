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

#include <string>
#include <vector>

/**
 * Main shape class to interface with.
 */
class Shape {
 public:
  // make virtual to access the derived class impl
  virtual std::string name();  // helpful for debugging
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  std::string shape_name = "BaseShape";
  std::vector<std::vector<char>> base;
  std::vector<std::vector<char>> rotate_90;
  std::vector<std::vector<char>> rotate_180;
  std::vector<std::vector<char>> rotate_270;
};

class ShapeI : public Shape {
 public:
  virtual std::string name();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  std::string shape_name = "Shape I";

  // ........
  // [][][][]
  // ........
  // ........
  std::vector<std::vector<char>> base{{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                      {'[', ']', '[', ']', '[', ']', '[', ']'},
                                      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
  // ....[]..
  // ....[]..
  // ....[]..
  // ....[]..
  std::vector<std::vector<char>> rotate_90{
      {' ', ' ', ' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', ' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', ' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', ' ', ' ', '[', ']', ' ', ' '}};

  // ........
  // ........
  // [][][][]
  // ........
  std::vector<std::vector<char>> rotate_180{
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'[', ']', '[', ']', '[', ']', '[', ']'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

  // ..[]....
  // ..[]....
  // ..[]....
  // ..[]....
  std::vector<std::vector<char>> rotate_270{
      {' ', ' ', '[', ']', ' ', ' ', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' ', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' ', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' ', ' ', ' '}};
};

class ShapeJ : public Shape {
 public:
  virtual std::string name();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  std::string shape_name = "Shape J";

  // []....
  // [][][]
  // ......
  std::vector<std::vector<char>> base{{'[', ']', ' ', ' ', ' ', ' '},
                                      {'[', ']', '[', ']', '[', ']'},
                                      {' ', ' ', ' ', ' ', ' ', ' '}};
  // ..[][]
  // ..[]..
  // ..[]..
  std::vector<std::vector<char>> rotate_90{{' ', ' ', '[', ']', '[', ']'},
                                           {' ', ' ', '[', ']', ' ', ' '},
                                           {' ', ' ', '[', ']', ' ', ' '}};

  // ......
  // [][][]
  // ....[]
  std::vector<std::vector<char>> rotate_180{{' ', ' ', ' ', ' ', ' ', ' '},
                                            {'[', ']', '[', ']', '[', ']'},
                                            {' ', ' ', ' ', ' ', '[', ']'}};

  // ..[]..
  // ..[]..
  // [][]..
  std::vector<std::vector<char>> rotate_270{{' ', ' ', '[', ']', ' ', ' '},
                                            {' ', ' ', '[', ']', ' ', ' '},
                                            {'[', ']', '[', ']', ' ', ' '}};
};

class ShapeL : public Shape {
 public:
  virtual std::string name();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  std::string shape_name = "Shape L";

  // ....[]
  // [][][]
  // ......
  std::vector<std::vector<char>> base{{' ', ' ', ' ', ' ', '[', ']'},
                                      {'[', ']', '[', ']', '[', ']'},
                                      {' ', ' ', ' ', ' ', ' ', ' '}};
  // ..[]..
  // ..[]..
  // ..[][]
  std::vector<std::vector<char>> rotate_90{{' ', ' ', '[', ']', ' ', ' '},
                                           {' ', ' ', '[', ']', ' ', ' '},
                                           {' ', ' ', '[', ']', '[', ']'}};

  // ......
  // [][][]
  // []....
  std::vector<std::vector<char>> rotate_180{{' ', ' ', ' ', ' ', ' ', ' '},
                                            {'[', ']', '[', ']', '[', ']'},
                                            {'[', ']', ' ', ' ', ' ', ' '}};

  // [][]..
  // ..[]..
  // ..[]..
  std::vector<std::vector<char>> rotate_270{{'[', ']', '[', ']', ' ', ' '},
                                            {' ', ' ', '[', ']', ' ', ' '},
                                            {' ', ' ', '[', ']', ' ', ' '}};
};

class ShapeO : public Shape {
 public:
  virtual std::string name();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  std::string shape_name = "Shape O";

  // ..[][]..
  // ..[][]..
  // ........
  // ........
  std::vector<std::vector<char>> base{{' ', ' ', '[', ']', '[', ']', ' ', ' '},
                                      {' ', ' ', '[', ']', '[', ']', ' ', ' '},
                                      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
  std::vector<std::vector<char>> rotate_90 = base;
  std::vector<std::vector<char>> rotate_180 = base;
  std::vector<std::vector<char>> rotate_270 = base;
};

class ShapeS : public Shape {
 public:
  virtual std::string name();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  std::string shape_name = "Shape S";

  // ..[][]
  // [][]..
  // ......
  std::vector<std::vector<char>> base{{' ', ' ', '[', ']', '[', ']'},
                                      {'[', ']', '[', ']', ' ', ' '},
                                      {' ', ' ', ' ', ' ', ' ', ' '}};
  // ..[]..
  // ..[][]
  // ....[]
  std::vector<std::vector<char>> rotate_90{{' ', ' ', '[', ']', ' ', ' '},
                                           {' ', ' ', '[', ']', '[', ']'},
                                           {' ', ' ', ' ', ' ', '[', ']'}};

  // ......
  // ..[][]
  // [][]..
  std::vector<std::vector<char>> rotate_180{{' ', ' ', ' ', ' ', ' ', ' '},
                                            {' ', ' ', '[', ']', '[', ']'},
                                            {'[', ']', '[', ']', ' ', ' '}};

  // []...
  // [][]..
  // ..[]..
  std::vector<std::vector<char>> rotate_270{{'[', ']', ' ', ' ', ' ', ' '},
                                            {'[', ']', '[', ']', ' ', ' '},
                                            {' ', ' ', '[', ']', ' ', ' '}};
};

class ShapeT : public Shape {
 public:
  virtual std::string name();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  std::string shape_name = "Shape T";

  // ..[]..
  // [][][]
  // ......
  std::vector<std::vector<char>> base{{' ', ' ', '[', ']', ' ', ' '},
                                      {'[', ']', '[', ']', '[', ']'},
                                      {' ', ' ', ' ', ' ', ' ', ' '}};
  // ..[]..
  // ..[][]
  // ..[]..
  std::vector<std::vector<char>> rotate_90{{' ', ' ', '[', ']', ' ', ' '},
                                           {' ', ' ', '[', ']', '[', ']'},
                                           {' ', ' ', '[', ']', ' ', ' '}};

  // ......
  // [][][]
  // ..[]..
  std::vector<std::vector<char>> rotate_180{{' ', ' ', ' ', ' ', ' ', ' '},
                                            {'[', ']', '[', ']', '[', ']'},
                                            {' ', ' ', '[', ']', ' ', ' '}};

  // ..[]..
  // [][]..
  // ..[]..
  std::vector<std::vector<char>> rotate_270{{' ', ' ', '[', ']', ' ', ' '},
                                            {'[', ']', '[', ']', ' ', ' '},
                                            {' ', ' ', '[', ']', ' ', ' '}};
};

class ShapeZ : public Shape {
 public:
  virtual std::string name();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  std::string shape_name = "Shape Z";

  // [][]..
  // ..[][]
  // ......
  std::vector<std::vector<char>> base{{'[', ']', '[', ']', ' ', ' '},
                                      {' ', ' ', '[', ']', '[', ']'},
                                      {' ', ' ', ' ', ' ', ' ', ' '}};
  // ....[]
  // ..[][]
  // ..[]..
  std::vector<std::vector<char>> rotate_90{{' ', ' ', ' ', ' ', '[', ']'},
                                           {' ', ' ', '[', ']', '[', ']'},
                                           {' ', ' ', '[', ']', ' ', ' '}};

  // ......
  // [][]..
  // ..[][]
  std::vector<std::vector<char>> rotate_180{{' ', ' ', ' ', ' ', ' ', ' '},
                                            {'[', ']', '[', ']', ' ', ' '},
                                            {' ', ' ', '[', ']', '[', ']'}};

  // ..[]..
  // [][]..
  // []....
  std::vector<std::vector<char>> rotate_270{{' ', ' ', '[', ']', ' ', ' '},
                                            {'[', ']', '[', ']', ' ', ' '},
                                            {'[', ']', ' ', ' ', ' ', ' '}};
};

Shape *get_shape(char shape);

Shape *get_random_shape();
