#include "Sales_item.h"


int main()
{
    //Sales_item item1, item2;
    Sales_item *items;
    int records = 0;
    double total_rs = 0.0;

    std::cout << "Enter the number of isbn records\n";
    std::cin >> records;
    items = new Sales_item[records]; 

    for(auto i = 0; i < records; i++) {
        std::cout << "Enter book details(" << i <<"): <isbn> <no_of_books> <price>\n";
        //std::cin >> item1 >> item2;
        std::cin >> items[i];
        std::cout << items[i];
        total_rs += items[i].item_revenue();
    }

#if 0
    std::cout << "\nSummary\n-------\n"; 
    if (item1.isbn() == item2.isbn()) {
        item2 += item1;
        std::cout << item2;
        return 0;
    }
    std::cout << item1 << item2;
#endif

    std::cout << "Total revenue: " << total_rs << std::endl;

    return 0;
}