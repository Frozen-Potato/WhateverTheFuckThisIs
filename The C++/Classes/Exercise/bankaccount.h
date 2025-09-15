#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <fstream>
#include <iomanip>
#include <iostream>

class Logging {
    std::ofstream out_;
    public:
        explicit Logging(const std::string& path) : out_(path, std::ios::app) {}

        ~Logging() = default;

        void log(const std::string& line) {
            if (out_) out_ << line << '\n';
        }
};

class Account {
    protected:
        double balance_{0.0};
    public:
        Account() = default;
        explicit Account(double init) : balance_(init) {}
        virtual ~Account() = default;

        double balance() const { return balance_;};
        virtual void applyMonthly() {}
        bool hasFunds(double atm) const { return balance_ >= atm; };
};

class Auditor;

class BankAccount final : public Account {
    private:
        mutable std::size_t reads_ = 0;
        Logging logger_;
    public:
        inline static std::string bank_name = "OP Bank";
        inline static std::size_t count = 0;
        inline static double default_interest = 0.0025;

        BankAccount();
        explicit BankAccount(double init);
        BankAccount(std::string_view promo);
        BankAccount(const BankAccount& other);
        BankAccount(BankAccount&& other);

        BankAccount& operator=(const BankAccount& other);
        BankAccount& operator=(BankAccount&& other);

        ~BankAccount() override;

        void deposit(double amount);
        bool withdraw(double amount);
        BankAccount& operator+=(double amount);

        bool operator==(const BankAccount& rhs) const;
        void applyMonthly() override;
        template <typename Rate>
        void applyInterest(Rate r) requires std::is_arithmetic_v<Rate> {
            if (r < 0) throw std::invalid_argument("negative rate");
            balance_ += balance_ * static_cast<double>(r);
        }

        double getBalance() const;
        std::size_t readCount() const noexcept { return reads_; }

        static std::string name() { return bank_name; }

        void swap(BankAccount& other);

        friend std::ostream& operator<<(std::ostream& os, const BankAccount& acc);
        friend BankAccount operator+(BankAccount lhs, double amount);
        friend BankAccount operator+(double amount, BankAccount rhs);
        friend class Auditor;
    
    private:
        void log(const std::string& line);
        static std::string toMoney(double v);
        static std::string toPercent(double r);
};

inline void swap(BankAccount& a, BankAccount& b) noexcept { a.swap(b); };

class Auditor {
public:
    static void peek(const BankAccount& acc);
};

#endif