#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include "Quote.h"
#include "Strategy.h"
#include "AggressiveStrategy.h"
#include "ConservativeStrategy.h"

using namespace std;

vector<Quote> readQuotes(const string& filename) {
    vector<Quote> quotes;
    ifstream file(filename);

    if (!file.is_open()) return quotes;

    string name, dateStr;
    double price;

    while (file >> name >> dateStr >> price) {
        int y, m, d;
        char dash;
        istringstream ds(dateStr);
        ds >> y >> dash >> m >> dash >> d;
        quotes.emplace_back(name, d, m, y, price);
    }
    return quotes;
}

int main() {
    double money;
    cout << "Budget: ";
    cin >> money;
    if (money <= 0) return 1;

    cout << "1 - Conservative\n2 - Aggressive\nChoice: ";
    int choice;
    cin >> choice;

    vector<Quote> quotes = readQuotes("C:/Users/Vertman/source/repos/StockMarket/x64/Debug/test.txt");

    if (quotes.empty()) {
        cout << "Error: test.txt not found or empty\n";
        return 1;
    }

    unique_ptr<Strategy> strategy;
    if (choice == 1) {
        strategy = make_unique<ConservativeStrategy>(money);
    }
    else {
        strategy = make_unique<AggressiveStrategy>(money);
    }

    Date current(0, 0, 0);
    for (const auto& q : quotes) {
        if (!q.date.isSameDay(current)) {
            current = q.date;
            cout << "\n" << q.date.year << "-"
                << setw(2) << setfill('0') << q.date.month << "-"
                << setw(2) << setfill('0') << q.date.day << "\n";
        }
        cout << q.stockName << " " << fixed << setprecision(2) << q.price << "\n";
        strategy->onQuote(q.stockName, q.price, q.date);
    }

    cout << "\nResult: " << fixed << setprecision(2)
        << strategy->getMoney() << "\n";
    return 0;
}