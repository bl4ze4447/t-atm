//
// Created by Antonie Gabriel Belu on 16.03.2026.
//

#include "../include/address.h"

std::string address_t::get_address_line() const {
    return state + ", " + city + ", " + street_name + ", " + postal_code;
}

std::ostream &operator<<(std::ostream &os, const address_t &email) {
    os << email.get_address_line();
    return os;
}

void to_json(nlohmann::json &j, const address_t &a) {
    j = nlohmann::json{
        {"street", a.street_name},
        {"city", a.city},
        {"state", a.state},
        {"postal_code", a.postal_code}
    };
}

void from_json(const nlohmann::json &j, address_t &a) {
    j.at("street").get_to(a.street_name);
    j.at("city").get_to(a.city);
    j.at("state").get_to(a.state);
    j.at("postal_code").get_to(a.postal_code);
}
