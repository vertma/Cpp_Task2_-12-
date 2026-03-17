#include "Strategy.h"
#include <iostream>

Strategy::Strategy(double startMoney, const std::string& n)
    : money(startMoney), name(n) {}

Strategy::~Strategy() {}

bool Strategy::canSell(const Position& pos, const Date& today) const {
    // Нельзя продавать в день покупки
    return !pos.buyDate.isSameDay(today);
}

void Strategy::onQuote(const std::string& stock, double price, const Date& today) {

    // ==================== 1. ПРОВЕРЯЕМ ПРОДАЖУ ====================
    for (auto it = portfolio.begin(); it != portfolio.end(); ) {

        // Если это та же акция и можно продавать
        if (it->name == stock && canSell(*it, today)) {

            // Если стратегия хочет продать
            if (wantSell(price, it->buyPrice)) {

                // Возвращаем деньги в бюджет
                double profit = it->count * price;
                money += profit;

                std::cout << "sale: " << it->count << " units "
                    << price << "P (purchased by " << it->buyPrice << "P)\n";

                // Удаляем позицию из портфеля
                it = portfolio.erase(it);
            }
            else {
                std::cout << "got it : purchased by " << it->buyPrice << "P\n";
                ++it;
            }
        }
        else {
            ++it;
        }
    }

    // ==================== 2. ПРОВЕРЯЕМ ПОКУПКУ ====================

    // Достаточно ли денег и есть ли история цены?
    bool hasHistory = lastPrice.count(stock) > 0;
    bool hasMoney = money >= price;
    bool wantToBuy = hasHistory && wantBuy(stock, price);

    if (hasMoney && hasHistory && wantToBuy) {

        // Сколько можем купить (целое число)
        int canBuy = static_cast<int>(money / price);

        if (canBuy > 0) {

            // Добавляем в портфель
            portfolio.emplace_back(stock, price, today, canBuy);

            // Списываем деньги
            money -= canBuy * price;

            std::cout << "purchase: " << canBuy << " units "
                << price << "P\n";
        }
    }

    // Запоминаем последнюю цену
    lastPrice[stock] = price;
}

double Strategy::getMoney() const {
    return money;
}

std::string Strategy::getName() const {
    return name;
}