#include "SDLGame.hpp"

bool SDLGame::Initialize()
{
    Game::Initialize();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
    {
        SDL_Log("SDL_Init: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window)
    {
        SDL_Log("SDL_CreateWindow: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        SDL_Log("SDL_CreateRenderer: %s\n", SDL_GetError());
        return false;
    }

    for (int i = 0; i < 2; i++)
    {
        if (SDL_JoystickOpen(i) == NULL)
        {
            SDL_Log("SDL_JoystickOpen: %s\n", SDL_GetError());
            return false;
        }
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        SDL_Log("IMG_Init: failed to init required png support %s\n", IMG_GetError());
        return false;
    }

    return true;
}

bool SDLGame::Input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_FINGERMOTION:
                break;
            case SDL_FINGERDOWN:
                break;
            case SDL_FINGERUP:
                break;
            case SDL_JOYBUTTONDOWN:
                break;
            case SDL_JOYBUTTONUP:
                break;
            default:
                break;
        }
    }
    return true;
}

void SDLGame::BeginFrame()
{
    Clear();
    Game::BeginFrame();
}

void SDLGame::EndFrame()
{
    Game::EndFrame();
    SDL_RenderPresent(renderer);
}

void SDLGame::Destroy()
{
    Game::Destroy();
    if (renderer) SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    if (window) SDL_DestroyWindow(window);
    window = nullptr;
    IMG_Quit();
    SDL_Quit();
}
