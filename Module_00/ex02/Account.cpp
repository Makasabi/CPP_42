# include "Account.hpp"
# include <iostream>
# include <ctime>

Account::Account( void ) {

	return ;
}

Account::~Account( void ) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout  << "closed" << std::endl;
	return ;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit) {

	static int i = 0;
	Account::_displayTimestamp();
	this->_accountIndex = i;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout  << "created" << std::endl;
	this->_totalAmount += this->_amount;
	this->_nbAccounts = 8;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
	i += 1;
	return ;
}

int		Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ) {

	return Account::_totalAmount;
}

int		Account::getNbDeposits( void ) {

	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ) {

	struct tm *timeinfo;
	std::time_t result;

	std::time(&result);
	timeinfo = std::localtime(&result);
	std::cout << "[" << 1900 + timeinfo->tm_year << 1 + timeinfo->tm_mon << timeinfo->tm_mday;
	std::cout << "_" ;
	std::cout << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec << "] ";
}

void	Account::displayAccountsInfos( void ) {

	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits += 1;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	this->_totalAmount += deposit;
	this->_totalNbDeposits += 1;
	
}

bool	Account::makeWithdrawal( int withdrawal ) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount){
		std::cout << "withdrawal:" << "refused" << std::endl;
		return false;
	}
	else {
		std::cout << "withdrawal:" << withdrawal  << ";";
		this->_amount -= withdrawal;
		std::cout << "amount:" << this->_amount << ";";
		this->_nbWithdrawals += 1;
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals += 1;
	}
	return true;
}

int		Account::checkAmount( void ) const {


	return 0;
}

void	Account::displayStatus( void ) const {
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits  << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;
