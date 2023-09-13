#include <iostream>
#include <string>

namespace OS {
    class OpSystem {
        OpSystem() {
            // #ifdef _WIN32
            // name_ = "Windows";
            // #elif __linux__
            // name_ = "Linux";
            // #endif
        }
    };

    OpSystem os;
}