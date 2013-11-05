#pragma once

#include <vector>
#include "rtype_common.h"

class Element
{
	t_coord					_pos; // point en haut a gauche
	t_coord					_hitboxSize;
	t_coord					_spritePos;
	t_coord					_center;

	bool					_bulletProof;
	bool					_shipProof;
	char					_faction; // 0 murs ; 1 joueur ; 2 ennemis
	int						_hp;
	int						_id;
	char					_spriteId;
	std::vector<t_coord>	_currentCells;
	char					_sendPriority;

public:
	Element();
	~Element();

	void					setHP(int);
	void					setBulletProof(bool);
	void					setShipProof(bool);
	void					setFaction(char);
	void					setSendPriority(char);
	void					setPos(t_coord);

	t_coord					getPos() const;
	t_coord					getHitboxSize() const;
	std::vector<t_coord>	getCurrentCell() const;
	char					getSpriteId() const;
	int						getHP() const;
	int						getId() const;
	bool					getShipProof()const;
	bool					getBulletProof()const;
	char					getFaction() const;
	char					getSendPriority() const;

	void					move();
	int						isCollision(std::list<Element*>);
	void					addToCurrentCell(t_coord);
	void					cleanCurrentCell();
};