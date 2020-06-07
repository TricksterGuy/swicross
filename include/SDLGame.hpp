#ifndef SDL_GAME_HPP
#define SDL_GAME_HPP

#include "Game.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>
#include <SDL.h>
#include <SDL_image.h>

enum SDLKeyMapping {
    SDL_KEY_A, SDL_KEY_B, SDL_KEY_X, SDL_KEY_Y,
    SDL_KEY_LSTICK, SDL_KEY_RSTICK,
    SDL_KEY_L, SDL_KEY_R,
    SDL_KEY_ZL, SDL_KEY_ZR,
    SDL_KEY_PLUS, SDL_KEY_MINUS,
    SDL_KEY_DLEFT, SDL_KEY_DUP, SDL_KEY_DRIGHT, SDL_KEY_DDOWN,
    SDL_KEY_LSTICK_LEFT, SDL_KEY_LSTICK_UP, SDL_KEY_LSTICK_RIGHT, SDL_KEY_LSTICK_DOWN,
    SDL_KEY_RSTICK_LEFT, SDL_KEY_RSTICK_UP, SDL_KEY_RSTICK_RIGHT, SDL_KEY_RSTICK_DOWN,
    SDL_KEY_SL_LEFT, SDL_KEY_SR_LEFT, SDL_KEY_SL_RIGHT, SDL_KEY_SR_RIGHT
};

constexpr uint32_t SCREEN_WIDTH = 1920;
constexpr uint32_t SCREEN_HEIGHT = 1080;

class SDLGame : public Game
{
public:
    SDLGame(std::string_view window_title) : title(window_title) {}
    virtual ~SDLGame() {}
    bool Initialize() override;
    bool Input() override;
    void Clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255)
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_RenderClear(renderer);
    }
    void Destroy() override;

    void BeginFrame() override;
    void EndFrame() override;

protected:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    const std::string title;
};

#endif
