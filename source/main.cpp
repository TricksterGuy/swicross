#include <cstdio>
#include <fstream>
#include <iostream>

#include <switch.h>
#include "scenes/game_scene.hpp"
#include "SDLGame.hpp"
#include "Picross.pb.h"
#include <NFont.h>

class Swicross : public SDLGame
{
public:
    Swicross() : SDLGame("Swicross") {}

    bool Initialize() override;
    void New(time_t seeded_game = 0) override;
    void Destroy() override;
private:
    std::unique_ptr<NFont> font;
};

bool Swicross::Initialize()
{
    if (!SDLGame::Initialize())
        return false;

    font.reset(new NFont(renderer, "romfs:/fonts/FreeSans.ttf", 20));

    return true;
}

void Swicross::New(time_t seeded_game)
{
    SDLGame::New(seeded_game);

    SetScene(GameScene::Create("romfs:/puzzles/test.picross", Scene::Options{renderer, font.get()}));
}

void Swicross::Destroy()
{
    SDLGame::Destroy();
}

int main(int argc, char *argv[])
{
    romfsInit();
    Swicross game;

    if (game.Initialize())
    {
        game.New();
        game.Run();
    }

    game.Destroy();
    romfsExit();

    return 0;
}
