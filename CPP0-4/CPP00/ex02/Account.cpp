#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0; 

int Account::_totalAmount = 0; 

int Account::_totalNbDeposits = 0; 

int Account::_totalNbWithdrawals = 0;

int Account :: getNbAccounts(void)
{   return _nbAccounts; }

int Account :: getTotalAmount(void)
{   return _totalAmount; }

int Account :: getNbDeposits(void)
{   return _totalNbDeposits; }

int Account :: getNbWithdrawals(void)
{   return _totalNbWithdrawals; }

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

int Account :: checkAmount(void) const
{   return _amount; }

void Account::_displayTimestamp(void)
{
    char timestamp[20];  
    std::time_t now;      

    std::time(&now);
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&now)); // 4. Format the time
    std::cout << "[" << timestamp << "] ";
}
void Account :: displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
                << ";deposits:" << getNbDeposits() << ";withdrawals:" <<
                    getNbWithdrawals() << std::endl;
 
}

void Account :: displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
                << getNbDeposits() << ";withdrawals" << getNbWithdrawals() 
                    << std::endl;
}

void Account :: makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:"
                << deposit ;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account :: makeWithdrawal( int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if(checkAmount() < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:"
                << _nbWithdrawals << std::endl;
    return true;
}
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}