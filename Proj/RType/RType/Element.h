#pragma once

#include <vector>
#include "rtype_common.h"
#include "ESprites.h"

class Element
{
	t_coord					_pos; // point en haut a gauche
	t_coord					_hitboxSize;
	t_coord					_spritePos;
	t_coord					_center;
	t_coord					_cellPosTL;
	t_coord					_cellPosBR;

	short int				_speed;
	bool					_bulletProof;
	bool					_shipProof;
	char					_faction; // 0 murs ; 1 joueur ; 2 ennemis
	int						_hp;
	int						_id;
	char					_spriteId;
	std::vector<t_coord>	_currentCells;
	char					_sendPriority;
	bool					_side; // 0 LIGHT ; 1 DARK
	char					_color;
	std::list<eSprites>		_sprites;
	bool					_isToUp;

public:
	Element();
	~Element();

	void					setHP(int);
	void					setBulletProof(bool);
	void					setShipProof(bool);
	void					setFaction(char);
	void					setSendPriority(char);
	void					setPos(const t_coord *);
	void					setSpeed(short int);
	void					setHitboxSize(t_coord *);
	void					setId(int);
	void					setColor(char);
	void					setSide(bool);
	void					setSprite(std::list<eSprites>);
	void					addSprite(eSprites);

	const t_coord&				getPos() const;
	const t_coord&				getHitboxSize() const;
	std::vector<t_coord>	getCurrentCell() const;
	char					getSpriteId() const;
	int						getHP() const;
	int						getId() const;
	bool					getShipProof()const;
	bool					getBulletProof()const;
	char					getFaction() const;
	char					getSendPriority() const;
	short int				getSpeed() const;
	char					getColor() const;
	bool					getSide() const;
	std::list<eSprites>		getSprite() const;

	void					move();
	int						isCollision(std::list<Element*>);
	void					addToCurrentCell(t_coord);
	void					setCell(t_coord);
	void					checkCell();
	void					cleanCurrentCell();
};
