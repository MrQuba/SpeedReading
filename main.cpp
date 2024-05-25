#include <SFML/Graphics.hpp>
#include "src/WindowClass.hpp"
#include "src/EventClass.hpp"
#include "src/File.hpp"
#include "src/Data.hpp"
#include "src/Text.hpp"

std::string getInput(std::string text) {
    std::cout << text;
    std::string input;
    std::cin >> input;
    return input;
}

int main() {
    File* file = new File(getInput("Input path to the file: "), open::type::in);
    int speed = std::stoi(getInput("Input speed of displaying words (Words/minute): "));
    float timer = 0.f;
    float timeInterval = 1.f / (speed / 60.f);
    Text* text = new Text(Path("assets/arial.ttf").get());
    Window* reading = new Window(sf::Vector2i(1920, 1080), "Speed Reading", 60, sf::Style::Fullscreen);
    Event* event = new Event; 
    bool start = false;
    sf::Clock clock;
    file->displayVector();
    while (reading->window.isOpen()) {
        reading->window.clear(sf::Color::Black);
        event->Loop(reading->window);
        text->setOnMiddleOfWindow(reading->window);
        if(!start) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) start = true;
            text->setText("Press Space to start");
        }
        if (start) {
            sf::Time deltaTime = clock.restart();
            float dtSeconds = deltaTime.asSeconds();
            timer += dtSeconds;
            if (!file->hasVectorEnded() && timer >= timeInterval) {
                timer = 0.f;
                text->setText(file->getWord());
                file->advanceIterator();
            }
            else {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) reading->window.close();
                if (timer >= timeInterval) text->setText("Press Q to exit");
            }
        }
        reading->window.draw(text->getText());
        reading->window.display();
    }
    delete reading;
    delete event;
    delete file;
    delete text;
    return 0;
}