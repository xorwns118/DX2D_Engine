#pragma once
#include "Entity.h"

class Asset : public Entity
{
private:
	ASSET_TYPE	m_Type;
	wstring		m_Key;
	wstring		m_RelativePath;

private:
	SET(wstring, Key)
	SET(wstring, RelativePath)

public:
	GET(ASSET_TYPE, Type)
	GET(wstring, Key)
	GET(wstring, RelativePath)

public:
	Asset(ASSET_TYPE _Type);
	virtual ~Asset();
};

