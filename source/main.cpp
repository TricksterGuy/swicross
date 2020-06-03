#include <cstdio>
#include <fstream>
#include <iostream>

#include <switch.h>
#include "SDLGame.hpp"
#include "Picross.pb.h"
#include <NFont.h>

class Swicross : public SDLGame
{
public:
    Swicross() : SDLGame("Swicross") {}

    bool Initialize() override;
    void New(time_t seeded_game = 0) override;
    void Update() override;
    void Draw() override;
    void Destroy() override;
private:
    std::unique_ptr<NFont> font;
};

bool Swicross::Initialize()
{
    if (!SDLGame::Initialize())
        return false;

    romfsInit();
    return true;
}

void Swicross::New(time_t seeded_game)
{
    SDLGame::New(seeded_game);
}

void Swicross::Update()
{

}

void Swicross::Draw()
{

}

void Swicross::Destroy()
{
    //if (cursor) SDL_DestroyTexture(cursor);
    //cursor = nullptr;
    SDLGame::Destroy();
    romfsExit();
}

int main(int argc, char *argv[])
{
    Swicross game;

    if (game.Initialize())
        game.Run();

    game.Destroy();

    return 0;
}
