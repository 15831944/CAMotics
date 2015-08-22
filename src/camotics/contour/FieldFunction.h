/******************************************************************************\

    CAMotics is an Open-Source CAM software.
    Copyright (C) 2011-2015 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#ifndef CAMOTICS_FIELD_FUNCTION_H
#define CAMOTICS_FIELD_FUNCTION_H

#include <camotics/Geom.h>

#include <vector>

namespace CAMotics {
  class FieldFunction {
  public:
    virtual ~FieldFunction() {} // Compiler needs this

    virtual bool contains(const Vector3R &p) = 0;
    virtual Vector3R getEdgeIntersect(const Vector3R &v1, bool inside1,
                                      const Vector3R &v2, bool inside2);
    virtual bool canCull(const Rectangle3R &bbox) {return false;}
  };
}

#endif // CAMOTICS_FIELD_FUNCTION_H
