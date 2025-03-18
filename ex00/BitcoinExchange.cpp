#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->readCsv();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _exchangeRate(copy._exchangeRate) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->_exchangeRate = other._exchangeRate;
    return *this;
}

void BitcoinExchange::readCsv() {
    std::ifstream f("data.csv");
    std::string price, date;

    if (!f.is_open())
        exit(1);

    std::getline(f, date);
    while (std::getline(f, date, ',') && std::getline(f, price)) {
        try
        {
            double valueOfBtc;
            valueOfBtc = std::stod(price);
            _exchangeRate[date] = valueOfBtc;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            f.close();
            exit(1);
        }
        
    }
    f.close();
}

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

bool checkDate(std::string dateStr) {
    int year, month, day;
    char dash1, dash2;

    // Parse the string: "YYYY-MM-DD"
    std::istringstream iss(dateStr);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
        return false;  // Parsing failed (wrong format)
    }
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;  // Basic range check before using chrono
    }
    // Create a year_month_day object
    std::chrono::year_month_day ymd{
        std::chrono::year{year},
        std::chrono::month{static_cast<unsigned int>(month)},
        std::chrono::day{static_cast<unsigned int>(day)}
    };

    // Validate using .ok()
    return ymd.ok();
}

void BitcoinExchange::parseWallet(char* wallet) {
    std::ifstream f(wallet);
    std::string tmp;
    if (!f.is_open())
        exit(1);
    std::getline(f, tmp); //assuming there is the header "date | value" in the beginning, if not comment this out
    while (std::getline(f, tmp)) {
        std::istringstream string(tmp);
        std::string price, date;
        if (std::getline(string, date, '|') && std::getline(string, price)) {
            if (!checkDate(date)) {
                printBadInput(date);
                continue;
            }
            try
            {
                double amountOfBtc = static_cast<double>(std::stof(price));
                if (amountOfBtc > 1000.0 || amountOfBtc < 0) {
                    printInvalidNumber(amountOfBtc);
                }
                else {
                    date = trim(date);
                    // std::cout << date << std::endl;
                    printValidInput(_exchangeRate, date, amountOfBtc);
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        else
            printBadInput(date);
    }
}

BitcoinExchange::~BitcoinExchange()
{

}