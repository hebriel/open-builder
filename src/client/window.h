#pragma once

#include "client_engine.h"
#include "input/keyboard.h"
#include "input/gamepad_manager.h"
#include <SFML/Window/Window.hpp>
#include <common/types.h>

struct ClientConfig;

/**
 * @brief Provides an interface for creating and common window interactions
 */
class Window {
  public:
    Window(const ClientConfig &config);

    template <typename F>
    EngineStatus pollEvents(Keyboard &keyboard, GamepadManager &gamepadManager, F onKeyRelease);

    sf::Window window;
    unsigned width;
    unsigned height;
    float aspect;

  private:
    void create(const sf::VideoMode &mode, u32 style);
};

template <typename F>
EngineStatus Window::pollEvents(Keyboard &keyboard, GamepadManager &gamepadManager, F onKeyRelease)
{
    auto status = EngineStatus::Ok;
    sf::Event e;
    while (window.pollEvent(e)) {
        if (window.hasFocus()) {
            keyboard.update(e);
            gamepadManager.update(e);
        }
        if (e.type == sf::Event::KeyPressed) {
            if (e.key.code == sf::Keyboard::Escape) {
                status = EngineStatus::Exit;
            }
        }
        else if (e.type == sf::Event::KeyReleased) {
            onKeyRelease(e.key.code);
        }
        else if (e.type == sf::Event::Closed) {
            status = EngineStatus::Exit;
        }
    }
    return status;
}