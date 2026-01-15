#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowEnums.hpp>

int main()
{
    sf::RenderWindow window(
        //sf::VideoMode({1920, 1080}), // sets specific screen resolution
        sf::VideoMode::getDesktopMode(), // gets users desktop screen resolution
        "Project Name",
        sf::Style::None
    );

    while (window.isOpen())
    {
        // Event handling (SFML 3)
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Real-time input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }

        window.clear();

        // code here

        window.display();
    }
}
