#pragma once

#include "model/Item.h"

#include <string>
#include <vector>

class ItemModel
{
    public:
        Item addItem(const std::string& name);
        const std::vector<Item>& getItems() const;

    private:
        std::vector<Item> items;
        int next_id = 1;
};
