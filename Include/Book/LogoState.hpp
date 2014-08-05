#ifndef BOOK_LOGOSTATE_HPP
#define BOOK_LOGOSTATE_HPP

#include <Book/State.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class LogoState : public State
{
	public:
							LogoState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mText;

		bool				mShowText;
		sf::Time			mTextEffectTime;
};

#endif // BOOK_LOGOSTATE_HPP
