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

#include <tetris/core/shape.h>

#include <random>

std::string Shape::name() { return shape_name; }

std::string ShapeI::name() { return shape_name; }

std::string ShapeJ::name() { return shape_name; }

std::string ShapeL::name() { return shape_name; }

std::string ShapeO::name() { return shape_name; }

std::string ShapeS::name() { return shape_name; }

std::string ShapeT::name() { return shape_name; }

std::string ShapeZ::name() { return shape_name; }

std::vector<std::vector<char>> Shape::get_orientation(int rotation) {
  std::vector<std::vector<char>> s;
  switch (rotation) {
    case 0:
      s = base;
      break;
    case 90:
      s = rotate_90;
      break;
    case 180:
      s = rotate_180;
      break;
    case 270:
      s = rotate_270;
      break;
  }
  return s;
}

std::vector<std::vector<char>> ShapeI::get_orientation(int rotation) {
  std::vector<std::vector<char>> s;
  switch (rotation) {
    case 0:
      s = base;
      break;
    case 90:
      s = rotate_90;
      break;
    case 180:
      s = rotate_180;
      break;
    case 270:
      s = rotate_270;
      break;
  }
  return s;
}

std::vector<std::vector<char>> ShapeJ::get_orientation(int rotation) {
  std::vector<std::vector<char>> s;
  switch (rotation) {
    case 0:
      s = base;
      break;
    case 90:
      s = rotate_90;
      break;
    case 180:
      s = rotate_180;
      break;
    case 270:
      s = rotate_270;
      break;
  }
  return s;
}

std::vector<std::vector<char>> ShapeL::get_orientation(int rotation) {
  std::vector<std::vector<char>> s;
  switch (rotation) {
    case 0:
      s = base;
      break;
    case 90:
      s = rotate_90;
      break;
    case 180:
      s = rotate_180;
      break;
    case 270:
      s = rotate_270;
      break;
  }
  return s;
}

std::vector<std::vector<char>> ShapeO::get_orientation(int rotation) {
  std::vector<std::vector<char>> s;
  switch (rotation) {
    case 0:
      s = base;
      break;
    case 90:
      s = rotate_90;
      break;
    case 180:
      s = rotate_180;
      break;
    case 270:
      s = rotate_270;
      break;
  }
  return s;
}

std::vector<std::vector<char>> ShapeS::get_orientation(int rotation) {
  std::vector<std::vector<char>> s;
  switch (rotation) {
    case 0:
      s = base;
      break;
    case 90:
      s = rotate_90;
      break;
    case 180:
      s = rotate_180;
      break;
    case 270:
      s = rotate_270;
      break;
  }
  return s;
}

std::vector<std::vector<char>> ShapeT::get_orientation(int rotation) {
  std::vector<std::vector<char>> s;
  switch (rotation) {
    case 0:
      s = base;
      break;
    case 90:
      s = rotate_90;
      break;
    case 180:
      s = rotate_180;
      break;
    case 270:
      s = rotate_270;
      break;
  }
  return s;
}

std::vector<std::vector<char>> ShapeZ::get_orientation(int rotation) {
  std::vector<std::vector<char>> s;
  switch (rotation) {
    case 0:
      s = base;
      break;
    case 90:
      s = rotate_90;
      break;
    case 180:
      s = rotate_180;
      break;
    case 270:
      s = rotate_270;
      break;
  }
  return s;
}

Shape *get_shape(char shape) {
  if (shape == 'I') {
    return new ShapeI();
  } else if (shape == 'J') {
    return new ShapeJ();
  } else if (shape == 'L') {
    return new ShapeL();
  } else if (shape == 'O') {
    return new ShapeO();
  } else if (shape == 'S') {
    return new ShapeS();
  } else if (shape == 'T') {
    return new ShapeT();
  } else {
    return new ShapeZ();
  }
}

Shape *get_random_shape() {
  char choices[] = "IJLOSTZ";  // all the kinds of shapes
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<int> uniform(0, 6);
  char choice = choices[uniform(generator)];
  return get_shape(choice);
}