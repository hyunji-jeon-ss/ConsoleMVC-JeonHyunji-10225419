#include "view/ConsoleView.h"

#include <iostream>

using std::cout;
using std::endl;

void ConsoleView::showMenu()
{
    cout << "==============================" << endl;
    cout << "[1] 항목 등록   [2] 항목 목록   [0] 종료" << endl;
    cout << "선택 > ";
}

void ConsoleView::showItems(const std::vector<Item>& items)
{
    if (items.empty())
    {
        cout << "등록된 항목이 없습니다." << endl;
        return;
    }

    for (const Item& item : items)
    {
        cout << item.id << " | " << item.name << endl;
    }
}

void ConsoleView::showMessage(const std::string& message)
{
    cout << message << endl;
}
