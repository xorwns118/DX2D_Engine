#pragma once
#include "Asset.h"

class AMesh : public Asset
{
	ComPtr<ID3D11Buffer>	m_VB;
	D3D11_BUFFER_DESC		m_VBDesc;
	UINT					m_VtxCount;

	ComPtr<ID3D11Buffer>	m_IB;
	D3D11_BUFFER_DESC		m_IBDesc;
	UINT					m_IdxCount;

public:
	int Create(Vtx* _VtxSysMem, UINT _VtxCount, UINT* _IdxSysMem, UINT _IdxCount);
	void Binding();
	void Render();

public:
	AMesh();
	virtual ~AMesh();
};