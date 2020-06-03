#include <cstdio>
#include <fstream>
#include <iostream>

#include <switch.h>
#include "Picross.pb.h"

int main(int argc, char **argv)
{
    // Initialize console. Using NULL as the second argument tells the console library to use the internal console structure as current one.
    romfsInit();
    consoleInit(NULL);

    std::ifstream in("romfs:/puzzles/test.picross", std::ios::binary);
    if (!in.good()) return 0;

    PicrossPuzzle puzzle;
    if (!puzzle.ParseFromIstream(&in))
        printf("Failed.\n");
    else
        printf("%s\n", puzzle.DebugString().c_str());

    while(appletMainLoop())
    {
        // Scan all the inputs. This should be done once for each frame
        hidScanInput();

        // hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        if (kDown & KEY_PLUS) break; // break in order to return to hbmenu

        // Updates the screen.
        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    romfsExit();

    return 0;
}
