#include "Line.h"

// Default constructor
Line::Line() : lineID("") {}

// Constructor with ID parameter
Line::Line(const std::string& id) : lineID(id) {}

// Get line ID
std::string Line::getID() const {
    return lineID;
}
