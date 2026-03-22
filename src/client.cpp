//
// Created by Antonie Gabriel Belu on 16.03.2026.
//

#include "../include/client.h"

std::ostream &operator<<(std::ostream &os, const client_t &client) {
    return os << client.personal_information;
}

void to_json(nlohmann::json &j, const client_t &c) {
    j = c.personal_information;
}

void from_json(const nlohmann::json &j, client_t &c) {
    c.personal_information = j.get<personl_information_t>();
}
