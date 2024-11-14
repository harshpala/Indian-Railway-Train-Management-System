#ifndef LINE_H
#define LINE_H

#include <string>

class Line {
private:
    std::string lineID; // Line identifier

public:
    Line(const std::string& id); // Constructor
    std::string getID() const;   // Get line ID
};

#endif
