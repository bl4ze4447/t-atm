//
// Created by Antonie Gabriel Belu on 16.03.2026.
//

#ifndef OOP_PERSONL_INFORMATION_H
#define OOP_PERSONL_INFORMATION_H

#include <string>
#include <ostream>

#include "address.h"
#include "email_address.h"
#include "phone_number.h"

class personl_information_t {
private:
    std::string first_name;
    std::string last_name;
    phone_number_t phone;
    email_address_t email;
    address_t address;
public:
    personl_information_t(
        std::string first_name,
        std::string last_name,
        address_t address,
        phone_number_t phone,
        email_address_t email)
        :
    first_name(std::move(first_name)),
    last_name(std::move(last_name)),
    phone(std::move(phone)),
    email(std::move(email)),
    address(std::move(address))
    {}

    friend std::ostream& operator<<(std::ostream& os, const personl_information_t& pi) {
        os << "first_name: " << pi.first_name << '\n'
        << "last_name: " << pi.last_name << '\n'
        << "phone_number: " << pi.phone << '\n'
        << "email: " << pi.email << '\n'
        << "address: " << pi.address << '\n';
        return os;
    }
};


#endif //OOP_PERSONL_INFORMATION_H