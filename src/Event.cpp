//
// EPITECH PROJECT, 2018
// Event
// File description:
// Event
//

#include "../includes/Event.hpp"

Event::Event ()
{
	struct timeval tp;

	gettimeofday(&tp, nullptr);
	_time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	_type = E_NOTHING;
	_diff_time = 42;
}

Event &Event::setType (Type type)
{
	_type = type;
	return (*this);
}

Event &Event::setKey (Key key)
{
	_key = key;
	return (*this);
}

Event::Type Event::getType () const
{
	return (_type);
}

Event::Key Event::getKey () const
{
	return (_key);
}

void Event::updateTime ()
{
	struct timeval tp;
	int time_tmp;

	gettimeofday(&tp, nullptr);
	time_tmp = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	_diff_time = time_tmp - _time;
	_time = time_tmp;
}

int Event::getDiff () const
{
	return (_diff_time);
}

int Event::getTime () const
{
	return (_time);
}

void Event::operator= (const Event &event)
{
	_time = event.getTime();
	_diff_time = event.getDiff();
	_key = event.getKey();
	_type = event.getType();
}