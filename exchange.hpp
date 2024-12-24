#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "useraccount.hpp"
#include "utility.hpp"

class Exchange {
 public:
  void MakeDeposit(const std::string &username, const std::string &asset, int amount);
  bool MakeWithdrawal(const std::string &username, const std::string &asset, int amount);
  bool AddOrder(const Order &order);
  
  
  std::ostream &PrintUserPortfolios(std::ostream &os) const;
  std::ostream &PrintUsersOrders(std::ostream &os) const;
  std::ostream &PrintOpenOrders(std::ostream &os) const;
  std::ostream &PrintFilledOrders(std::ostream &os) const;
  std::ostream &PrintTradeHistory(std::ostream &os) const;
  std::ostream &PrintBidAskSpread(std::ostream &os) const;

 private:
  std::map<std::string, UserAccount> user_accounts_; 
  std::vector<Order> trade_history_; 

  bool ValidateOrder(const Order &order, const UserAccount &account) const; 
  bool ReserveFundsForOrder(const Order &order, UserAccount &account);      
  void AddOrderToAccount(const Order &order, UserAccount &account);         
  bool MatchOrder(const Order &new_order);                                  
  void ExecuteTrade(const Order &buy_order, const Order &sell_order);       
};
