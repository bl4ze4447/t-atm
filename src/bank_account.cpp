//
// Created by Antonie Gabriel Belu on 18.03.2026.
//

#include "../include/bank_account.h"

std::ostream &operator<<(std::ostream& os, const bank_account_t& bank_account) {
    os << "Account ID: " << bank_account.identifier << "\n"
       << "Username: " << bank_account.username << "\n"
       << "Client: " << bank_account.client << "\n"
       << "Bank: " << bank_account.bank << "\n"
       << "Balance: " << bank_account.balance << "\n"
       << "Transactions:\n";

    if (bank_account.transactions.empty()) {
        os << "  No transactions found.\n";
        return os;
    }

    // for (const auto& transaction : bank_account.transactions) {
    //     os << "> " << transaction << "\n";
    // } todo

    return os;
}

bank_account_t &bank_account_t::operator=(const bank_account_t &other) {
    if (this != &other) {
        identifier = other.identifier;
        username = other.username;
        pin = other.pin;
        client = other.client;
        bank = other.bank;
        balance = other.balance;
        transactions = other.transactions;
    }
    return *this;
}

bank_account_t &bank_account_t::operator=(bank_account_t &&other) noexcept {
    if (this != &other) {
        identifier = std::move(other.identifier);
        username = std::move(other.username);
        pin = std::move(other.pin);
        client = std::move(other.client);
        bank = other.bank;
        balance = other.balance;
        transactions = std::move(other.transactions);
    }
    return *this;
}
