#include <vector>
using namespace std;

class Bank {
public:
    // Member function declarations
    void dataInput();
    void displayInput();
    void reportWithoutMonthlyPay();
    void reportWithMonthlyPay();

private:
    // Variables declared
    double investment;
    double deposit;
    int years;
    double interest;
    double monthly_interest;
    double year_end_balance;
    double year_end_interest;
    vector<int> month_numbers;
    vector<int> year_numbers;
};