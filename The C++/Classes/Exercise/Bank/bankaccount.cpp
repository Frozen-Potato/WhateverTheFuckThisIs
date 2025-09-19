#include "bankaccount.h"

BankAccount::BankAccount() : Account(0.0), logger_("transactions.log") {
    ++count;
    log("OPEN default");
}

BankAccount::BankAccount(double init) : Account(init), logger_("transactions.log") {
    ++count;
    log("OPEN init=" + toMoney(init));
}

BankAccount::BankAccount(std::string_view promo)
: BankAccount(promo == "starter" ? 100.0 : 0.0) {
    log(std::string("OPEN promo=") + std::string(promo));
}

BankAccount::BankAccount(const BankAccount& other)
: Account(other.balance_), reads_(other.reads_), logger_("transactions.log") {
    ++count;
    log("COPY from " + toMoney(other.balance_));
}

BankAccount::BankAccount(BankAccount&& other)
: Account(other.balance_), reads_(other.reads_), logger_("transactions.log") {
    other.balance_ = 0.0;
    other.reads_ = 0;
    ++count;
    log("MOVE-CONSTRUCTOR");
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        balance_ = other.balance_;
        reads_   = other.reads_;
        log("COPY-ASSIGN from " + toMoney(other.balance_));
    }
    return *this;
}

BankAccount& BankAccount::operator=(BankAccount&& other) {
    if (this != &other) {
        balance_ = other.balance_;
        reads_   = other.reads_;
        other.balance_ = 0.0;
        other.reads_ = 0;
        log("MOVE-ASSIGN");
    }
    return *this;
}

BankAccount::~BankAccount() {
    log("CLOSE balance=" + toMoney(balance_));
    --count;
}

void BankAccount::deposit(double amount) {
    if (amount < 0) throw std::invalid_argument("negative deposit");
    balance_ += amount;
    log("DEPOSIT " + toMoney(amount) + " => " + toMoney(balance_));
}

bool BankAccount::withdraw(double amount) {
    if (amount < 0) throw std::invalid_argument("negative withdraw");
    if (amount > balance_) return false;
    balance_ -= amount;
    log("WITHDRAW " + toMoney(amount) + " => " + toMoney(balance_));
    return true;
}

BankAccount& BankAccount::operator+=(double amount) {
    deposit(amount);
    return *this;
}

bool BankAccount::operator==(const BankAccount& rhs) const {
    return balance_ == rhs.balance_;
}

void BankAccount::applyMonthly() {
    applyInterest(default_interest);
    log("APPLY_MONTHLY rate=" + toPercent(default_interest)
        + " => " + toMoney(balance_));
}

double BankAccount::getBalance() const {
    ++reads_;
    return balance_;
}

void BankAccount::swap(BankAccount& other) {
    using std::swap;
    swap(balance_, other.balance_);
    swap(reads_, other.reads_);
}

void BankAccount::log(const std::string& line) {
    logger_.log(line);
}

std::string BankAccount::toMoney(double v) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << v;
    return "$" + oss.str();
}

std::string BankAccount::toPercent(double r) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << (r * 100.0) << "%";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const BankAccount& acc) {
    os << "[" << BankAccount::bank_name << "] balance="
       << std::fixed << std::setprecision(2)
       << acc.balance_
       << " (reads=" << acc.reads_ << ")";
    return os;
}

BankAccount operator+(BankAccount lhs, double amount) {
    lhs += amount;
    return lhs;
}

BankAccount operator+(double amount, BankAccount rhs) {
    rhs += amount;
    return rhs;
}

void Auditor::peek(const BankAccount& acc) {
    std::cout << "[AUDIT] raw balance=" << acc.balance_
              << ", reads=" << acc.reads_ << "\n";
}
