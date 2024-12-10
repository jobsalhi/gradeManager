#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <string>

class Professor {
private:
    std::string name;

public:
    Professor(const std::string& name);
    const std::string& getName() const;
};

#endif // PROFESSOR_HPP
