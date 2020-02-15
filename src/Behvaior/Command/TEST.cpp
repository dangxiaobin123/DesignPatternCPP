#define CATCH_CONFIG_MAIN
#include "DrawCanvas.h"
#include "MacroCommand.h"
#include "DrawCommand.h"
#include <catch.hpp>

TEST_CASE("Command pattern")
{
    MacroCommand macro;
    DrawCanvas draw(&macro);
    macro.add_command(new DrawCommand(1, 2, &draw));
    macro.add_command(new DrawCommand(3, 4, &draw));
    draw.draw(20, 10);
    draw.paint();
    macro.undo();
    draw.paint();
}

