#include "controller/ConsoleInputReader.h"
#include "controller/MainController.h"
#include "model/ItemModel.h"
#include "view/ConsoleView.h"

int main()
{
    ConsoleView view;
    ConsoleInputReader input_reader;
    ItemModel model;

    MainController controller(view, input_reader, model);
    controller.run();

    return 0;
}
