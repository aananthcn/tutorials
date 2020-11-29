#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double r) { interestRate = r; }
private:
    std::string owner;
    double amount;
    static double interestRate;

    //in-class initialization of static data members
    static constexpr int period = 30; // period is a constant expression
    // A constexpr integral value can be used wherever a const integer is 
    // required, such as in template arguments and array declarations. And 
    // when a value is computed at compile time instead of run time, it 
    // helps your program run faster and use less memory.
    
    double daily_tbl[period];
};

#endif