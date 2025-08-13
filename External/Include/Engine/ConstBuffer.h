#pragma once
#include "Entity.h"

class ConstBuffer : public Entity
{
private:
	ComPtr<ID3D11Buffer>	m_CB;
	D3D11_BUFFER_DESC		m_Desc;

	CB_TYPE					m_Type;

public:
	void SetData(void* _SysMem, UINT _Size = 0);

public:
	void Create(CB_TYPE _Type, UINT _BufferSize);
	void Binding();

public:
	ConstBuffer();
	virtual ~ConstBuffer();
};

