//
// EPITECH PROJECT, 2018
// Element
// File description:
// Element
//

#ifndef ELEMENT_HPP_
# define ELEMENT_HPP_

#include <vector>
#include "Event.hpp"
#include "Color.hpp"

#define WALL 'w'
#define PERSONAGE 'P'
#define SHIP 's'
#define MISSILE 'i'
#define MILLIPEDE 'c'
#define TAIL 't'
#define MUSHROOM 'm'
#define ENEMY 'e'
#define FOOD 'f'
#define BOMBER 'b'
#define SPIDER 'd'
#define ENERGY 'E'
#define EMPTY 'V'
#define SNAKE 's'

typedef struct s_InfoElement
{
	float x;
	float y;
	char type;
	t_Color Color;
	float size;
} t_InfoElement;

class Element
{
	public:
	virtual float getX () const = 0;
	virtual float getY () const = 0;
	virtual void setPos (float x, float y) = 0;
	virtual void setLife (int life) = 0;
	virtual void handleEvent (const Event &ptr) = 0;
	virtual t_Color getColor () const = 0;
	virtual char getType () const = 0;
	virtual int getLife () const = 0;
	virtual int getMaxLife () const = 0;
	virtual int getLength () const = 0;
	virtual bool isDestructible () const = 0;
	virtual bool hasCollision (int el) = 0;
	virtual float getSize () const = 0;
	virtual std::vector<Element *> getSubElements () = 0;

	protected:
	float _x;
	float _y;
	int _nbr_kill;
	int run_game;
	char _Type;
	t_Color _Color;
	int _length;
	bool _tangibility;
	bool _destructible;
	int _life;
	float _size;
	int _max_life;
	bool _dangerous;
	std::vector<Element *> _sub_elements;
};

#endif
