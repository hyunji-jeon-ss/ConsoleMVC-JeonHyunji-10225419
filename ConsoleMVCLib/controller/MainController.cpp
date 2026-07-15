#include "controller/MainController.h"

MainController::MainController(IView& view, IInputReader& input_reader, ItemModel& model)
    : view(view)
    , input_reader(input_reader)
    , model(model)
{
}

void MainController::run()
{
    bool running = true;
    while (running)
    {
        view.showMenu();
        const std::string command = input_reader.readLine();
        running = processCommand(command);
    }
}

bool MainController::processCommand(const std::string& command)
{
    if (command == "0") return false;

    if (command == "1")
    {
        view.showMessage("등록할 항목 이름 > ");
        const std::string name = input_reader.readLine();
        model.addItem(name);
        view.showMessage("등록 완료: " + name);
        return true;
    }

    if (command == "2")
    {
        view.showItems(model.getItems());
        return true;
    }

    view.showMessage("알 수 없는 명령입니다.");
    return true;
}
