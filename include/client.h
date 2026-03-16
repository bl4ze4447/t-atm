//
// Created by Antonie Gabriel Belu on 16.03.2026.
//

#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H

#include <string>
#include <nlohmann/json.hpp>

#include "email_address.h"
#include "phone_number.h"
#include "personl_information.h"

class client_t {
private:
    personl_information_t personal_information;
public:
    client_t(
        const std::string& first_name,
        const std::string& last_name,
        const std::string& street_name,
        const std::string& city,
        const std::string& state,
        const std::string& postal_code,
        const std::string& email,
        const std::string& phone_number) :
    personal_information(
        first_name,last_name,
        address_t(street_name, city, state, postal_code),
        phone_number_t(phone_number),
        email_address_t(email)) {}

    friend std::ostream& operator<<(std::ostream& os, const client_t& client) {
        return os << client.personal_information;
    }
};


#endif //OOP_CLIENT_H