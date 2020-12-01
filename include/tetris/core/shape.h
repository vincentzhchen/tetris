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
