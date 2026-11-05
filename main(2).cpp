#include <iomanip>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

class BankAccount {
protected:
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& number, double balance)
        : accountNumber(number), balance(balance) {}

    virtual ~BankAccount() = default;

    void printInfo() const {
        std::cout << "Рахунок №" << accountNumber
                  << ", баланс: " << std::fixed << std::setprecision(2)
                  << balance << " грн" << std::endl;
    }

    virtual double calculateIncome() const {
        std::cout << "[BankAccount] Загальний рахунок: зміни коштів немає." << std::endl;
        return 0.0;
    }
};

class DebitAccount : public BankAccount {
private:
    double monthlyFee;

public:
    DebitAccount(const std::string& number, double balance, double monthlyFee)
        : BankAccount(number, balance), monthlyFee(monthlyFee) {}

    double calculateIncome() const override {
        std::cout << "[DebitAccount] Додаткового доходу немає, "
                  << "списується плата за обслуговування: "
                  << std::fixed << std::setprecision(2) << monthlyFee << " грн" << std::endl;
        return -monthlyFee;
    }
};

class CreditAccount : public BankAccount {
private:
    double annualCreditRate;

public:
    CreditAccount(const std::string& number, double balance, double annualCreditRate)
        : BankAccount(number, balance), annualCreditRate(annualCreditRate) {}

    double calculateIncome() const override {

        double debt = balance < 0 ? -balance : 0.0;
        double interest = debt * annualCreditRate / 100.0 / 12.0;
        std::cout << "[CreditAccount] Борг: " << std::fixed << std::setprecision(2) << debt
                  << " грн, ставка " << annualCreditRate
                  << "% річних. Відсотки за місяць (витрати): " << interest << " грн" << std::endl;
        return -interest;
    }
};

class DepositAccount : public BankAccount {
private:
    double annualInterestRate;

public:
    DepositAccount(const std::string& number, double balance, double annualInterestRate)
        : BankAccount(number, balance), annualInterestRate(annualInterestRate) {}

    double calculateIncome() const override {
        double income = balance * annualInterestRate / 100.0 / 12.0;
        std::cout << "[DepositAccount] Ставка " << std::fixed << std::setprecision(2)
                  << annualInterestRate << "% річних. Нараховано відсотків за місяць: "
                  << income << " грн" << std::endl;
        return income;
    }
};

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    DebitAccount debit("UA-DEB-001", 15000.00, 50.00);
    CreditAccount credit("UA-CRD-002", -20000.00, 36.0);
    DepositAccount deposit("UA-DEP-003", 100000.00, 12.0);

    BankAccount* account = nullptr;

    std::cout << "=== Дебетовий рахунок ===" << std::endl;
    account = &debit;
    account->printInfo();
    double result = account->calculateIncome();
    std::cout << "Зміна коштів за місяць: " << std::showpos << result << std::noshowpos << " грн\n" << std::endl;

    std::cout << "=== Кредитний рахунок ===" << std::endl;
    account = &credit;
    account->printInfo();
    result = account->calculateIncome();
    std::cout << "Зміна коштів за місяць: " << std::showpos << result << std::noshowpos << " грн\n" << std::endl;

    std::cout << "=== Депозитний рахунок ===" << std::endl;
    account = &deposit;
    account->printInfo();
    result = account->calculateIncome();
    std::cout << "Зміна коштів за місяць: " << std::showpos << result << std::noshowpos << " грн" << std::endl;

    return 0;
}
