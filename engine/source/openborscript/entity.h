/*
 * OpenBOR - http://www.chronocrash.com
 * -----------------------------------------------------------------------
 * All rights reserved. See LICENSE in OpenBOR root for license details.
 *
 * Copyright (c) 2004 - 2018 OpenBOR Team
 */

// Entity Properties
// 2018-04-02
// Caskey, Damon V.

HRESULT openbor_get_entity_property(ScriptVariant **varlist , ScriptVariant **pretvar, int paramCount);
HRESULT openbor_set_entity_property(ScriptVariant **varlist , ScriptVariant **pretvar, int paramCount);

int mapstrings_entity_property(ScriptVariant **varlist, int paramCount);

typedef enum
{
    _ENTITY_AI_TARGET_ENTITY,
    _ENTITY_ANIMATION_ANIMATING,
    _ENTITY_ANIMATION_COLLECTION,
    _ENTITY_ANIMATION_FRAME,
	_ENTITY_ANIMATION_ID,
    _ENTITY_ARROW_ON,
    _ENTITY_ATTACKING,
    _ENTITY_ATTACK_ID_INCOMING,
    _ENTITY_ATTACK_ID_OUTGOING,
    _ENTITY_AUTOKILL,
    _ENTITY_BINDING,
    _ENTITY_BLINK,
    _ENTITY_BLOCKING,
    _ENTITY_BOSS,
    _ENTITY_CHARGING,
    _ENTITY_COLORSET_DEFAULT,
    _ENTITY_COLORSET_DYING_HEALTH_1,
    _ENTITY_COLORSET_DYING_HEALTH_2,
    _ENTITY_COLORSET_DYING_INDEX_1,
    _ENTITY_COLORSET_DYING_INDEX_2,
    _ENTITY_COLORSET_TABLE,
    _ENTITY_COLORSET_TIME,
    _ENTITY_COMBO_STEP,
    _ENTITY_COMBO_TIME,
    _ENTITY_DAMAGE_ON_LANDING,
    _ENTITY_DEDUCT_AMMO,
	_ENTITY_EXISTS,
	_ENTITY_HP,
	_ENTITY_HP_OLD,
	_ENTITY_MODEL,
	_ENTITY_MODEL_DATA,
	_ENTITY_MODEL_DEFAULT,
	_ENTITY_MP,
	_ENTITY_MP_OLD,
	_ENTITY_NAME,
    _ENTITY_OPPONENT,
    _ENTITY_OWNER,
    _ENTITY_PLAYER_INDEX,
	_ENTITY_POSITION_BASE,
    _ENTITY_POSITION_BASE_ALTERNATE,
    _ENTITY_POSITION_DIRECTION,
	_ENTITY_POSITION_X,
	_ENTITY_POSITION_Y,
	_ENTITY_POSITION_Z,
    _ENTITY_PROJECTILE_PRIME,
    _ENTITY_SPAWN_TYPE,
    _ENTITY_END,
} e_entity_properties;

HRESULT openbor_get_entity_property(ScriptVariant **varlist, ScriptVariant **pretvar, int paramCount);
HRESULT openbor_set_entity_property(ScriptVariant **varlist, ScriptVariant **pretvar, int paramCount);

int mapstrings_entity_property(ScriptVariant **varlist, int paramCount);
