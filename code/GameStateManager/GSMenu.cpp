#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	GameButton* button;
	//PlayButton
	button = new GameButton();
	button->Init("play");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::MAP1); });
	button->setPosition(WIDTH / 2, HEIGHT / 2+HEIGHT/10);
	button->setSize(sf::Vector2f(250,200));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	// //Exit Button
	// button = new GameButton();
	// button->Init("close");
	// button->setOrigin(button->getSize() / 2.f);
	// button->setPosition(WIDTH / 2+WIDTH/4, HEIGHT-HEIGHT/8);
	// button->setOnClick([]() {WConnect->getWindow()->close();});
	// m_ListBtn.push_back(button);

	// //Setting Button
	// button = new GameButton();
	// button->Init("settings");
	// button->setOrigin(button->getSize() / 2.f);
	// button->setPosition(WIDTH / 2 - WIDTH / 4, HEIGHT - HEIGHT / 8);
	// button->setOnClick([]() {GSM->ChangeState(StateTypes::MAP1); });
	// m_ListBtn.push_back(button);

	// //about Button
	// button = new GameButton();
	// button->Init("about");
	// button->setOrigin(button->getSize() / 2.f);
	// button->setPosition(WIDTH / 2 + WIDTH / 12, HEIGHT - HEIGHT / 8);
	
	// button->setOnClick([]() {GSM->ChangeState(StateTypes::MAP1); });
	// m_ListBtn.push_back(button);

	// //HighScore Button
	// button = new GameButton();
	// button->Init("prize");
	// button->setOrigin(button->getSize() / 2.f);
	// button->setPosition(WIDTH / 2 - WIDTH / 12, HEIGHT - HEIGHT / 8);
	// button->setOnClick([]() {GSM->ChangeState(StateTypes::MAP1); });
	// m_ListBtn.push_back(button);

	//Background
	m_Background.setTexture(*DATA->getTexture("background/menubg"));
	m_Background.setScale(3.f,4.f);

}

void GSMenu::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}

