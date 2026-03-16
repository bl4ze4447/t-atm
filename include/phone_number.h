//
// Created by Antonie Gabriel Belu on 16.03.2026.
//

#ifndef OOP_PHONE_NUMBER_H
#define OOP_PHONE_NUMBER_H
#include <string>

#include "base_exception.h"

class invalid_phone_length : public base_exception {
public:
    explicit invalid_phone_length(const std::string& phone)
        : base_exception("invalid_phone_length", phone + "' has an invalid length!") {}
};

class invalid_phone_prefix : public base_exception {
public:
    explicit invalid_phone_prefix(const std::string& phone)
        : base_exception("invalid_phone_prefix", phone + " has an invalid prefix!") {}
};

class invalid_phone_chars : public base_exception {
public:
    explicit invalid_phone_chars(const std::string& phone)
        : base_exception("invalid_phone_chars", phone + " has characters different from digits!") {}
};

class phone_number_t {
private:
    const size_t PHONE_NUMBER_LENGTH = 10;
    const std::string PHONE_NUMBER_PREFIX = "07";
    std::string value;
public:
    explicit phone_number_t(std::string value) {
        this->value = std::move(value);
        if (this->value.length() != PHONE_NUMBER_LENGTH) {
            throw invalid_phone_length(this->value);
        }

        if (this->value.substr(0, 2) != PHONE_NUMBER_PREFIX) {
            throw invalid_phone_prefix(this->value);
        }

        for (const char &c : this->value) {
            if (!std::isdigit(c)) {
                throw invalid_phone_chars(this->value);
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const phone_number_t& pn) {
        os << pn.value;
        return os;
    }
};

#endif //OOP_PHONE_NUMBER_H