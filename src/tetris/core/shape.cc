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

int Shape::color() { return shape_color; }

int ShapeI::color() { return shape_color; }

int ShapeJ::color() { return shape_color; }

int ShapeL::color() { return shape_color; }

int ShapeO::color() { return shape_color; }

int ShapeS::color() { return shape_color; }

int ShapeT::color() { return shape_color; }

int ShapeZ::color() { return shape_color; }

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
