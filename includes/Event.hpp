//
// EPITECH PROJECT, 2018
// Event
// File description:
// Event
//

#ifndef EVENT_HPP_
# define EVENT_HPP_

#include <iostream>
#include <chrono>
#include <sys/time.h>

class Event
{
public:
	enum Type {
		E_NOTHING,
		E_QUIT,
		E_UP,
		E_DOWN,
	};
	enum Key {
		K_NOTHING,
		K_UP,
		K_DOWN,
		K_RIGHT,
		K_LEFT,
		K_OTHER,
		K_SPACE,
		K_RETURN,
		K_o,
		K_n,
		K_s,
		K_p,
		K_a,
		K_z,
		K_m,
		K_c,
		K_e
	};
	Event();
	Event &setType(Type type);
	Event &setKey(Key key);
	Type getType() const;
	Key getKey() const;
	void updateTime();
	int getDiff() const;
	int getTime() const;
	void operator=(const Event &event);
private:
	int _time;
	int _diff_time;
	Type _type;
	Key _key;
};

#endif
