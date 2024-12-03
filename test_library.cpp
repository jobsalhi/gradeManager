#include <iostream>
#include "Lib/nlohmann/json.hpp" // JSON handling library

int main() {
    // Create a JSON object
    nlohmann::json jsonObject;
    jsonObject["message"] = "JSON inclusion is successful";

    // Print the JSON object
    std::cout << jsonObject.dump(4) << std::endl;

    return 0;
}