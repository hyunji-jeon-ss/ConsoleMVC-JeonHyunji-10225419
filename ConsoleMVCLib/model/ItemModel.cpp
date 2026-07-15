#include "model/ItemModel.h"

Item ItemModel::addItem(const std::string& name)
{
    Item item{ next_id, name };
    items.push_back(item);
    next_id++;
    return item;
}

const std::vector<Item>& ItemModel::getItems() const
{
    return items;
}
