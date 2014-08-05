#include <Book/LogoState.hpp>
#include <Book/Utility.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


LogoState::LogoState(StateStack& stack, Context context)
: State(stack, context)
, mText()
, mShowText(true)
, mCount(16)
, mCurrent(0) // first image
{
	mpStrings = new sf::String[16]{
		"Meffmeff1",
		"Meffmeff2",
		"Meffmeff3",
		"Meffmeff4",
		"Meffmeff5",
		"Meffmeff6",
		"Meffmeff7",
		"Meffmeff8",
		"Meffmeff9",
		"Meffmeff10",
		"Meffmeff11",
		"Meffmeff12",
		"Meffmeff13",
		"Meffmeff14",
		"Meffmeff15",
		"Meffmeff16",
		};
	mpTimeSteps = new sf::Time[16]{
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
		sf::seconds(1),
	};
	mBackgroundSprite.setTexture(context.textures->get(Textures::Screens));
	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setString("LogoState");
	centerOrigin(mText);
	mText.setPosition(sf::Vector2f(context.window->getSize() / 2u));
}

void LogoState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);

	if (mShowText)
		window.draw(mText); 
}
/**
 * 		sf::Sprite			mBackgroundSprite;
		sf::Text			mText;

		bool				mShowText;
		sf::Time			mAge;
		int					mCount; // how many images/texts are there
		int					mCurrent; // current image/text id
		sf::Time[]			mTimeSteps; // time after text/image changes
		sf::String[]		mStrings; // texts to be shown */
bool LogoState::update(sf::Time dt)
{
	mAge += dt;

	if (mAge >= mpTimeSteps[mCurrent])
	{
		mAge = sf::Time::Zero;
		mCurrent++;
		if(mCurrent<mCount){ // valid frame -> change image and text
			mText.setString(mpStrings[mCurrent]);
			mBackgroundSprite.setTextureRect(sf::IntRect(mCurrent%6*1024,mCurrent/6*768,1024,768));
		} else {
			requestExit();
		}	
			
	}

	return true;
}

bool LogoState::handleEvent(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyReleased)
	{
		requestExit();
	}

	return false; // dont forward events
}


void LogoState::requestExit(){
	requestStackPop();
	// requestStackPush(States::Menu); // TODO ITE use this line
}
