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

#include <tetris/constants/color.h>

#include <string>
#include <vector>

/**
 * Main shape class to interface with.
 */
class Shape {
 public:
  // make virtual to access the derived class impl
  virtual std::string name();  // helpful for debugging
  virtual int color();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  const std::string shape_name = "BaseShape";
  const int shape_color = color::BLACK;
  const std::vector<std::vector<char>> base;
  const std::vector<std::vector<char>> rotate_90;
  const std::vector<std::vector<char>> rotate_180;
  const std::vector<std::vector<char>> rotate_270;
};

class ShapeI : public Shape {
 public:
  virtual std::string name();
  virtual int color();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  const std::string shape_name = "Shape I";
  const int shape_color = color::CYAN;

  // ........
  // [][][][]
  // ........
  // ........
  const std::vector<std::vector<char>> base{
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'[', ']', '[', ']', '[', ']', '[', ']'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

  // ....[]..
  // ....[]..
  // ....[]..
  // ....[]..
  const std::vector<std::vector<char>> rotate_90{
      {' ', ' ', ' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', ' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', ' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', ' ', ' ', '[', ']', ' ', ' '}};

  // ........
  // ........
  // [][][][]
  // ........
  const std::vector<std::vector<char>> rotate_180{
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'[', ']', '[', ']', '[', ']', '[', ']'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

  // ..[]....
  // ..[]....
  // ..[]....
  // ..[]....
  const std::vector<std::vector<char>> rotate_270{
      {' ', ' ', '[', ']', ' ', ' ', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' ', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' ', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' ', ' ', ' '}};
};

class ShapeJ : public Shape {
 public:
  virtual std::string name();
  virtual int color();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  const std::string shape_name = "Shape J";
  const int shape_color = color::BLACK;

  // []....
  // [][][]
  // ......
  const std::vector<std::vector<char>> base{{'[', ']', ' ', ' ', ' ', ' '},
                                            {'[', ']', '[', ']', '[', ']'},
                                            {' ', ' ', ' ', ' ', ' ', ' '}};

  // ..[][]
  // ..[]..
  // ..[]..
  const std::vector<std::vector<char>> rotate_90{
      {' ', ' ', '[', ']', '[', ']'},
      {' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' '}};

  // ......
  // [][][]
  // ....[]
  const std::vector<std::vector<char>> rotate_180{
      {' ', ' ', ' ', ' ', ' ', ' '},
      {'[', ']', '[', ']', '[', ']'},
      {' ', ' ', ' ', ' ', '[', ']'}};

  // ..[]..
  // ..[]..
  // [][]..
  const std::vector<std::vector<char>> rotate_270{
      {' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' '},
      {'[', ']', '[', ']', ' ', ' '}};
};

class ShapeL : public Shape {
 public:
  virtual std::string name();
  virtual int color();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  const std::string shape_name = "Shape L";
  const int shape_color = color::BLUE;

  // ....[]
  // [][][]
  // ......
  const std::vector<std::vector<char>> base{{' ', ' ', ' ', ' ', '[', ']'},
                                            {'[', ']', '[', ']', '[', ']'},
                                            {' ', ' ', ' ', ' ', ' ', ' '}};

  // ..[]..
  // ..[]..
  // ..[][]
  const std::vector<std::vector<char>> rotate_90{
      {' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', '[', ']'}};

  // ......
  // [][][]
  // []....
  const std::vector<std::vector<char>> rotate_180{
      {' ', ' ', ' ', ' ', ' ', ' '},
      {'[', ']', '[', ']', '[', ']'},
      {'[', ']', ' ', ' ', ' ', ' '}};

  // [][]..
  // ..[]..
  // ..[]..
  const std::vector<std::vector<char>> rotate_270{
      {'[', ']', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' '}};
};

class ShapeO : public Shape {
 public:
  virtual std::string name();
  virtual int color();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  const std::string shape_name = "Shape O";
  const int shape_color = color::YELLOW;

  // ..[][]..
  // ..[][]..
  // ........
  // ........
  const std::vector<std::vector<char>> base{
      {' ', ' ', '[', ']', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', '[', ']', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
  const std::vector<std::vector<char>> &rotate_90 = base;
  const std::vector<std::vector<char>> &rotate_180 = base;
  const std::vector<std::vector<char>> &rotate_270 = base;
};

class ShapeS : public Shape {
 public:
  virtual std::string name();
  virtual int color();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  const std::string shape_name = "Shape S";
  const int shape_color = color::GREEN;

  // ..[][]
  // [][]..
  // ......
  const std::vector<std::vector<char>> base{{' ', ' ', '[', ']', '[', ']'},
                                            {'[', ']', '[', ']', ' ', ' '},
                                            {' ', ' ', ' ', ' ', ' ', ' '}};

  // ..[]..
  // ..[][]
  // ....[]
  const std::vector<std::vector<char>> rotate_90{
      {' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', '[', ']'},
      {' ', ' ', ' ', ' ', '[', ']'}};

  // ......
  // ..[][]
  // [][]..
  const std::vector<std::vector<char>> rotate_180{
      {' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', '[', ']', '[', ']'},
      {'[', ']', '[', ']', ' ', ' '}};

  // []...
  // [][]..
  // ..[]..
  const std::vector<std::vector<char>> rotate_270{
      {'[', ']', ' ', ' ', ' ', ' '},
      {'[', ']', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' '}};
};

class ShapeT : public Shape {
 public:
  virtual std::string name();
  virtual int color();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  const std::string shape_name = "Shape T";
  const int shape_color = color::MAGENTA;

  // ..[]..
  // [][][]
  // ......
  const std::vector<std::vector<char>> base{{' ', ' ', '[', ']', ' ', ' '},
                                            {'[', ']', '[', ']', '[', ']'},
                                            {' ', ' ', ' ', ' ', ' ', ' '}};

  // ..[]..
  // ..[][]
  // ..[]..
  const std::vector<std::vector<char>> rotate_90{
      {' ', ' ', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', '[', ']'},
      {' ', ' ', '[', ']', ' ', ' '}};

  // ......
  // [][][]
  // ..[]..
  const std::vector<std::vector<char>> rotate_180{
      {' ', ' ', ' ', ' ', ' ', ' '},
      {'[', ']', '[', ']', '[', ']'},
      {' ', ' ', '[', ']', ' ', ' '}};

  // ..[]..
  // [][]..
  // ..[]..
  const std::vector<std::vector<char>> rotate_270{
      {' ', ' ', '[', ']', ' ', ' '},
      {'[', ']', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', ' ', ' '}};
};

class ShapeZ : public Shape {
 public:
  virtual std::string name();
  virtual int color();
  virtual std::vector<std::vector<char>> get_orientation(int rotation = 0);

 private:
  const std::string shape_name = "Shape Z";
  const int shape_color = color::RED;

  // [][]..
  // ..[][]
  // ......
  const std::vector<std::vector<char>> base{{'[', ']', '[', ']', ' ', ' '},
                                            {' ', ' ', '[', ']', '[', ']'},
                                            {' ', ' ', ' ', ' ', ' ', ' '}};

  // ....[]
  // ..[][]
  // ..[]..
  const std::vector<std::vector<char>> rotate_90{
      {' ', ' ', ' ', ' ', '[', ']'},
      {' ', ' ', '[', ']', '[', ']'},
      {' ', ' ', '[', ']', ' ', ' '}};

  // ......
  // [][]..
  // ..[][]
  const std::vector<std::vector<char>> rotate_180{
      {' ', ' ', ' ', ' ', ' ', ' '},
      {'[', ']', '[', ']', ' ', ' '},
      {' ', ' ', '[', ']', '[', ']'}};

  // ..[]..
  // [][]..
  // []....
  const std::vector<std::vector<char>> rotate_270{
      {' ', ' ', '[', ']', ' ', ' '},
      {'[', ']', '[', ']', ' ', ' '},
      {'[', ']', ' ', ' ', ' ', ' '}};
};
