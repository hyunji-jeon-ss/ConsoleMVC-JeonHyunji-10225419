#include "controller/ConsoleInputReader.h"
#include "controller/MainController.h"
#include "model/ItemModel.h"
#include "view/ConsoleView.h"

#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ConsoleView view;
    ConsoleInputReader input_reader;
    ItemModel model;

    MainController controller(view, input_reader, model);
    controller.run();

    return 0;
}
