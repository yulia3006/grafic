#include <SFML/Graphics.hpp>
#include <windows.h>
#include <functional> 
#include <cmath>
#include <locale.h>

void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); 

        
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Console app to display graphs");
    setlocale(LC_ALL, "Russian");
    
    sf::CircleShape userPoint(5);
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false; 

    
    sf::Font font;
    if (!font.loadFromFile("arial (1).ttf")) {
        return -1;
    }
    
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);
    sf::Text numberZone;
    numberZone.setFont(font);
    numberZone.setCharacterSize(20);
    numberZone.setFillColor(sf::Color::White);
    numberZone.setPosition(10, 100);

    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300); 
    xAxis[0].color = sf::Color::White; 
    xAxis[1].position = sf::Vector2f(750, 300); 
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); 
    yAxis[0].color = sf::Color::White; 
    yAxis[1].position = sf::Vector2f(400, 550); 
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Ïðîâåðêà êëèêà ìûøüþ
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                   
                    float mathX = (mousePos.x - 400) / 20.0f; 
                    float mathY = -(mousePos.y - 300) / 20.0f; 

                    
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; 

                    
                    if (mathY == -5*mathX+3 or mathY == 3 * mathX -  6) {
                        numberZone.setString("Boderline");
                    }
                    else {
                        if (mathY > 3 * mathX - 6) {
                            if (mathY > -5 * mathX + 3) {
                                numberZone.setString("Zone 3");
                            }
                            else {
                                numberZone.setString("Zone 1");
                            }
                        }
                        else {
                            if (mathY > -5 * mathX + 3) {
                                numberZone.setString("Zone 4");
                            }
                            else {
                                numberZone.setString("Zone 2");
                            }
                        }
                    }
                    coordinatesText.setString("Coordinations: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ")");
                }
            }
        }


       
        window.clear();

        window.draw(xAxis);
        window.draw(yAxis);



        
        drawGraph(window, [](float x) { return 3*x-6; }, -12, 12, 20, 20, sf::Color::Blue);

        
        drawGraph(window, [](float x) { return -5*x+3; }, -12, 12, 20, 20, sf::Color::Red);

        
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
            window.draw(numberZone);
        }

        
        window.display();
    }
    return 0;
}
