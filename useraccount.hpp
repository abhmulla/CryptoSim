#pragma once
#include "utility.hpp"
#include <map>
#include <string>
#include <vector>
#include <ostream>

class UserAccount {
 public:
  UserAccount() : username_("") {};
  UserAccount(const std::string &username);
  
  void Deposit(const std::string &asset, int amount);
  
  bool Withdraw(const std::string &asset, int amount);
  
  void AddOrder(const Order &order);
  
  void PrintPortfolio(std::ostream &os) const;
  
  void PrintOrders(std::ostream &os) const;
  
  const std::map<std::string, int> &GetPortfolio() const { return portfolio_; }

  const std::vector<Order> &GetOpenOrders() const { return open_orders_; }

  std::vector<Order> &GetOpenOrders() { return open_orders_; }

  const std::vector<Order> &GetFilledOrders() const { return filled_orders_; }

  std::vector<Order> &GetFilledOrders() { return filled_orders_; }

 private:
  std::string username_; 
  std::map<std::string, int> portfolio_; 
  std::vector<Order> open_orders_; 
  std::vector<Order> filled_orders_; 
};
 