// Not_afraid
// 2024/11/29

#ifndef SIPSERVER_IDGEN_H
#define SIPSERVER_IDGEN_H

#include <iostream>
#include <sstream>

class IDGen {
public:
    IDGen() = delete;

    static std::string GenerateID(int len) {
        std::ostringstream id;
        for (int i = 0; i < len; ++i) {
            id << alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        return id.str();
    }

private:
    static constexpr char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
};

#endif //SIPSERVER_IDGEN_H
