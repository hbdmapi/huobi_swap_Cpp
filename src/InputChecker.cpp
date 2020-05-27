#include "InputChecker.h"

namespace HuobiSwap {

    InputChecker* InputChecker::instance = nullptr;

    InputChecker* InputChecker::checker() {
        if (instance == nullptr) {
            instance = new InputChecker();
        }
        return instance;
    }
}
