#include <Book/MenuState.hpp>
#include <Book/Button.hpp>
#include <Book/Utility.hpp>
#include <Book/MusicPlayer.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
	sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	mBackgroundSprite.setTexture(texture);
	mBackgroundSprite.setTextureRect(sf::IntRect(2*1024,3*768, 1024,768));
	// game
	auto playButton = std::make_shared<GUI::Button>(context);
	playButton->setPosition(100, 300);
	playButton->setText("GameState");
	playButton->setCallback([this] ()
	{
		//requestStackPop();
		requestStackPush(States::Game);
	});
	// logo
	auto logoButton = std::make_shared<GUI::Button>(context);
	logoButton->setPosition(100, 350);
	logoButton->setText("LogoState");
	logoButton->setCallback([this] ()
	{
		//requestStackPop();
		requestStackPush(States::Logo);
	});
	// intro
	auto introButton = std::make_shared<GUI::Button>(context);
	introButton->setPosition(100, 400);
	introButton->setText("IntroState");
	introButton->setCallback([this] ()
	{
		//requestStackPop();
		requestStackPush(States::Intro);
	});
	// Pause
	auto pauseButton = std::make_shared<GUI::Button>(context);
	pauseButton->setPosition(100, 450);
	pauseButton->setText("PauseState");
	pauseButton->setCallback([this] ()
	{
		requestStackPush(States::Pause);
	});
	// outro
	auto outroButton = std::make_shared<GUI::Button>(context);
	outroButton->setPosition(100, 500);
	outroButton->setText("OutroState");
	outroButton->setCallback([this] ()
	{
		//requestStackPop();
		requestStackPush(States::Outro);
	});
	// GameOvewr
	auto gameOverButton = std::make_shared<GUI::Button>(context);
	gameOverButton->setPosition(100, 550);
	gameOverButton->setText("GameOverState");
	gameOverButton->setCallback([this] ()
	{
		requestStackPush(States::GameOver);
	});
	// exit
	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(100, 600);
	exitButton->setText("Exit");
	exitButton->setCallback([this] ()
	{
		requestStackPop(); // TODO ITE: Replace with Clear()
	});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(logoButton);
	mGUIContainer.pack(introButton);
	mGUIContainer.pack(pauseButton);
	mGUIContainer.pack(outroButton);
	mGUIContainer.pack(gameOverButton);
	mGUIContainer.pack(exitButton);

	// Play menu theme
	context.music->play(Music::MainTheme);
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool MenuState::update(sf::Time)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
	{
		requestStackPop();
	}
	mGUIContainer.handleEvent(event);
	return false;
}
