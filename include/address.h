//
// Created by Antonie Gabriel Belu on 16.03.2026.
//

#ifndef OOP_ADDRESS_H
#define OOP_ADDRESS_H
#include <string>

class address_t {
private:
    std::string street_name;
    std::string postal_code;
    std::string city;
    std::string state;
public:
    address_t(
        std::string street_name,
        std::string postal_code,
        std::string city,
        std::string state) :
    street_name(std::move(street_name)),
    postal_code(std::move(postal_code)),
    city(std::move(city)),
    state(std::move(state))
    {}

    [[nodiscard]] std::string get_address_line() const;

    friend std::ostream& operator<<(std::ostream& os, const address& email) {
        os << email.get_address_line();
        return os;
    }
};


#endif //OOP_ADDRESS_H