#pragma once

#include "model/Item.h"

#include <string>
#include <vector>

class IView
{
    public:
        virtual ~IView() = default;

        virtual void showMenu() = 0;
        virtual void showItems(const std::vector<Item>& items) = 0;
        virtual void showMessage(const std::string& message) = 0;
};
