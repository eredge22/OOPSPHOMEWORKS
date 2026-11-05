# Бібліотека класів предметної області «Сейф»

Тема з завдання «Перший клас» — **Сейф**. Проєкт містить бібліотеку класів та виконуваний застосунок, що її використовує.

## Структура
```
safe-library/
├── lib/
│   ├── include/   Valuable.h, Safe.h, KeySafe.h, CombinationSafe.h, ElectronicSafe.h
│   ├── src/       реалізація класів
│   └── CMakeLists.txt
├── src/main.cpp
└── CMakeLists.txt
```

## Ієрархія класів
- `Valuable` — цінна річ, яку зберігають у сейфі (назва, вартість).
- `Safe` — абстрактний базовий клас (модель, місткість, стан, вміст). Чисто віртуальні методи `unlock()` і `getType()`.
- `KeySafe` — відкривається ключем.
- `CombinationSafe` — відкривається кодовою комбінацією, блокується після 3 невдалих спроб.
- `ElectronicSafe` — відкривається PIN-кодом, має заряд батареї.

## Збірка та запуск
```
cmake -S . -B build
cmake --build build
./build/safe_app
```
На Windows (Visual Studio) виконуваний файл може бути в `build/Debug/safe_app.exe`.
