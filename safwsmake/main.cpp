#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

#include "CombinationSafe.h"
#include "ElectronicSafe.h"
#include "KeySafe.h"
#include "Safe.h"

void demonstrate(Safe& safe, const std::string& wrongCredential, const std::string& rightCredential) {
    std::cout << "=== " << safe.getType() << " ===" << std::endl;
    safe.printInfo();

    std::cout << "Спроба відкрити з неправильними даними: "
              << (safe.unlock(wrongCredential) ? "успішно" : "відмовлено") << std::endl;
    std::cout << "Спроба відкрити з правильними даними: "
              << (safe.unlock(rightCredential) ? "успішно" : "відмовлено") << std::endl;

    safe.addItem(Valuable("Золотий злиток", 250000.0));
    safe.addItem(Valuable("Документи на квартиру", 1500000.0));
    safe.addItem(Valuable("Годинник", 80000.0));

    safe.printContents();
    safe.lock();
    safe.printInfo();
    std::cout << std::endl;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    KeySafe keySafe("Guardian K-2", 2, "KEY-4821");
    CombinationSafe combinationSafe("Vault C-5", 3, "17-42-08");
    ElectronicSafe electronicSafe("Secure E-9", 5, "1984", 100);

    demonstrate(keySafe, "KEY-0000", "KEY-4821");
    demonstrate(combinationSafe, "00-00-00", "17-42-08");
    demonstrate(electronicSafe, "0000", "1984");

    std::cout << "Заряд батареї електронного сейфа: "
              << electronicSafe.getBatteryPercent() << "%" << std::endl;

    return 0;
}
