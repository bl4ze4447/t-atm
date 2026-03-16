//
// Created by Antonie Gabriel Belu on 16.03.2026.
//

#include "../include/address.h"

std::string address_t::get_address_line() const {
    return state + ", " + city + ", " + street_name + ", " + postal_code;
}
