//
// Created by Antonie Gabriel Belu on 16.03.2026.
//

#include "../include/email_address.h"

#include "base_exception.h"

std::ostream &operator<<(std::ostream &os, const email_address_t &email) {
    os << email.value;
    return os;
}

void to_json(nlohmann::json &j, const email_address_t &e) {
    j = e.value;
}

void from_json(const nlohmann::json &j, email_address_t &e) {
    e.value = j.get<std::string>();
}
