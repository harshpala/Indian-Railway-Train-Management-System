#ifndef LINE_H
#define LINE_H

#include <string>

class Line {
private:
    std::string lineID; // Line identifier

public:
    Line();                             // Default constructor
    Line(const std::string& id);        // Constructor with ID parameter
    std::string getID() const;          // Get line ID
};

#endif
