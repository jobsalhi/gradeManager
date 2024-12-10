#include "../include/Professor.hpp"

Professor::Professor(const std::string& name) : name(name) {}

const std::string& Professor::getName() const {
    return name;
}
