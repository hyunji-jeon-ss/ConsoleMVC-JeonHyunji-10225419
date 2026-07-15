#include "controller/IInputReader.h"
#include "controller/MainController.h"
#include "model/ItemModel.h"
#include "view/IView.h"

#include "gmock/gmock.h"

#include <string>
#include <vector>

using namespace testing;

class MockView : public IView
{
    public:
        MOCK_METHOD(void, showMenu, (), (override));
        MOCK_METHOD(void, showItems, (const std::vector<Item>& items), (override));
        MOCK_METHOD(void, showMessage, (const std::string& message), (override));
};

class MockInputReader : public IInputReader
{
    public:
        MOCK_METHOD(std::string, readLine, (), (override));
};

TEST(MainControllerTest, ExitCommandStopsLoop)
{
    MockView view;
    MockInputReader input_reader;
    ItemModel model;
    MainController controller(view, input_reader, model);

    EXPECT_FALSE(controller.processCommand("0"));
}

TEST(MainControllerTest, AddCommandAddsItemToModel)
{
    MockView view;
    MockInputReader input_reader;
    ItemModel model;
    MainController controller(view, input_reader, model);

    EXPECT_CALL(input_reader, readLine()).WillOnce(Return("Sample-A"));
    EXPECT_CALL(view, showMessage(_)).Times(2);

    EXPECT_TRUE(controller.processCommand("1"));
    ASSERT_EQ(model.getItems().size(), 1u);
    EXPECT_EQ(model.getItems()[0].name, "Sample-A");
}

TEST(MainControllerTest, ListCommandShowsItems)
{
    MockView view;
    MockInputReader input_reader;
    ItemModel model;
    model.addItem("Sample-B");
    MainController controller(view, input_reader, model);

    EXPECT_CALL(view, showItems(_)).Times(1);

    EXPECT_TRUE(controller.processCommand("2"));
}

TEST(MainControllerTest, UnknownCommandShowsErrorMessage)
{
    MockView view;
    MockInputReader input_reader;
    ItemModel model;
    MainController controller(view, input_reader, model);

    EXPECT_CALL(view, showMessage(_)).Times(1);

    EXPECT_TRUE(controller.processCommand("9"));
}

int main(int argc, char** argv)
{
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
