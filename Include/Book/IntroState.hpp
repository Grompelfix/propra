#ifndef BOOK_INTROSTATE_HPP
#define BOOK_INTROSTATE_HPP

#include <Book/State.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class IntroState : public State
{
	public:
							IntroState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mText;

		bool				mShowText;
		sf::Time			mTextEffectTime;
};

#endif // BOOK_INTROSTATE_HPP
