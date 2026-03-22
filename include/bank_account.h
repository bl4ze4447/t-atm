//
// Created by Antonie Gabriel Belu on 18.03.2026.
//

#ifndef OOP_BANK_ACCOUNT_H
#define OOP_BANK_ACCOUNT_H
#include "bank.h"
#include "client.h"

#include "transaction.h"
using balance_t = long long;

class bank_account_t {
private:
    std::string identifier;
    std::string username;
    std::string pin;
    client_t client;
    bank_t bank;

    balance_t balance;
    std::vector<transaction_t> transactions;

public:
    bank_account_t(std::string username, std::string pin,
                   client_t &client, const bank_t &bank, const balance_t balance,
                   const std::vector<transaction_t> &transactions)
        : username(std::move(username)), pin(std::move(pin)), client(std::move(client)), bank(bank),
          balance(balance), transactions(transactions) {
        this->identifier = this->bank.get_identifier() + ":" + this->username;
    }
    bank_account_t(const bank_account_t &other) = default;
    bank_account_t(bank_account_t &&other) noexcept
        : identifier(std::move(other.identifier)),
          username(std::move(other.username)), pin(std::move(other.pin)),
          client(std::move(other.client)), bank(other.bank),
          balance(other.balance), transactions(std::move(other.transactions)) {}


    bank_account_t &operator=(bank_account_t &&other) noexcept;
    bank_account_t &operator=(const bank_account_t &other);
    friend std::ostream &operator<<(std::ostream &os, const bank_account_t &bank_account);

    ~bank_account_t() = default;
};

#endif // OOP_BANK_ACCOUNT_H
