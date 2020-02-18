#define CATCH_CONFIG_MAIN
#include "DrawCanvas.h"
#include "MacroCommand.h"
#include "DrawCommand.h"
#include "Command.h"
#include <catch.hpp>

int add(int x, int y)
{
    return x+y;
}

TEST_CASE("Command pattern")
{
    MacroCommand macro;
    DrawCanvas draw(&macro);
    Command<int> cmd;
    cmd.wrap(add, 3, 4);
    int r = cmd.execute();
    Command<void> cmd1;
    cmd1.wrap(&DrawCanvas::draw, &draw, 3, 5);
    cmd1.execute();
    macro.add_command(new DrawCommand(1, 2, &draw));
    macro.add_command(new DrawCommand(3, 4, &draw));
    draw.draw(20, 10);
    draw.paint();
    macro.undo();
    draw.paint();
}

