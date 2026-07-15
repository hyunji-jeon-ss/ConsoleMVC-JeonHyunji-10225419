#pragma once

#include "view/IView.h"

class ConsoleView : public IView
{
    public:
        void showMenu() override;
        void showItems(const std::vector<Item>& items) override;
        void showMessage(const std::string& message) override;
};
