#pragma once
#include <string>
#include <thread>
#include <math.h>

namespace mt
{

	const float pi = acos(-1);

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;

		sf::RenderWindow m_window;
		sf::Image fiksikiI;
		sf::Texture fiksikiT;
		sf::Sprite fiksikiS;

	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			fiksikiI.loadFromFile("22.png");
			fiksikiT.loadFromImage(fiksikiI);
			fiksikiS.setTexture(fiksikiT);
			fiksikiS.setPosition(150, 250);

		}

		void LifeCycle()
		{
			sf::Clock clock;

			while (m_window.isOpen())
			{
				sf::Texture backgroundTexture;
				if (!backgroundTexture.loadFromFile("fire.png")) {
					return; // ошибка загрузки картинки
				}

				sf::Sprite backgroundSprite;
				backgroundSprite.setTexture(backgroundTexture);

				sf::Vector2f targetSize(m_width, m_height); //целевой размер

				backgroundSprite.setScale(
					targetSize.x / backgroundSprite.getLocalBounds().width,
					targetSize.y / backgroundSprite.getLocalBounds().height);

				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();

					if (event.type == sf::Event::KeyPressed)
					{
						if (event.key.code == sf::Keyboard::S)
						{
							fiksikiS.setPosition(fiksikiS.getPosition().x, fiksikiS.getPosition().y + 5);
						}
						if (event.key.code == sf::Keyboard::A)
						{
							fiksikiS.setPosition(fiksikiS.getPosition().x - 5, fiksikiS.getPosition().y);
						}
						if (event.key.code == sf::Keyboard::W)
						{
							fiksikiS.setPosition(fiksikiS.getPosition().x, fiksikiS.getPosition().y - 5);
						}
						if (event.key.code == sf::Keyboard::D)
						{
							fiksikiS.setPosition(fiksikiS.getPosition().x + 5, fiksikiS.getPosition().y);
						}
					}
				}


				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				m_window.clear();
				m_window.draw(backgroundSprite);
				m_window.draw(fiksikiS);
				m_window.display();
			}
		}
	};

}