#include "Line.h"

Line::Line(const std::string& id) : lineID(id) {}

std::string Line::getID() const {
    return lineID;
}
