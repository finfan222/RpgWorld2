#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "GameSystem.hpp"

class GameObject {
public:
	/*Выводит информацию в виде логирования где принтуется __as_string*/
	virtual void as_info() const;
	/*Представляет игровой объект в виде gt::STRING*/
	virtual gt::STRING as_string() const;
	/*Размерность игрового объекта*/
	virtual gt::UINT as_size() const;
};

#endif
