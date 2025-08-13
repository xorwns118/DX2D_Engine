#pragma once
#include "Asset.h"
class AGraphicShader : public Asset
{
private:
	ComPtr<ID3D11VertexShader>	m_VS;
	ComPtr<ID3DBlob>			m_VSBlob;

	ComPtr<ID3D11PixelShader>	m_PS;
	ComPtr<ID3DBlob>			m_PSBlob;

	ComPtr<ID3DBlob>			m_ErrBlob;

	ComPtr<ID3D11InputLayout>	m_Layout;

	D3D11_PRIMITIVE_TOPOLOGY	m_Topology;

public:
	GET_SET(D3D11_PRIMITIVE_TOPOLOGY, Topology)

public:
	int CreateVertexShader(const wstring& _RelativePath, const string& _FuncName);
	int CreatePixelShader(const wstring& _RelativePath, const string& _FuncName);

	void Binding();

public:
	AGraphicShader();
	virtual ~AGraphicShader();
};

