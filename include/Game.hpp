#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <ctime>
#include <memory>
#include "scenes/scene.hpp"

inline int randomInt(int max)
{
    return rand() / (RAND_MAX / max + 1);
}

inline int randomInt(int start, int end)
{
    return randomInt(end - start + 1) + start;
}

class Game
{
public:
    Game() {}
    virtual ~Game() {}
    virtual bool Initialize() {return true;}
    virtual void New(time_t seeded_game = 0)
    {
        if (seeded_game == 0)
            seeded_game = time(NULL);
        srand(seed = seeded_game);
    }
    virtual void Run()
    {
        while(true)
        {
            BeginFrame();
            if (!Input())
                break;
            Update();
            Draw();
            EndFrame();
        }
    }
    virtual void BeginFrame() {current_scene->BeginFrame();}
    virtual void Update() {current_scene->Update();}
    virtual bool Input() {return true;}
    virtual void Draw() {current_scene->Draw();}
    virtual void EndFrame() {current_scene->EndFrame();}

    void SetScene(Scene* scene) {current_scene.reset(scene);}
    virtual void Destroy() {current_scene.reset();}
protected:
    time_t seed = 0;
    std::unique_ptr<Scene> current_scene;
};

#endif
