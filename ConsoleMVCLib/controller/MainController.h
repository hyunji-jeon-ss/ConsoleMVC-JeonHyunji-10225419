#pragma once

#include "controller/IInputReader.h"
#include "model/ItemModel.h"
#include "view/IView.h"

#include <string>

class MainController
{
    public:
        MainController(IView& view, IInputReader& input_reader, ItemModel& model);

        void run();
        bool processCommand(const std::string& command);

    private:
        IView& view;
        IInputReader& input_reader;
        ItemModel& model;
};
