#ifndef _STD2D
#define _STD2D

// 상수 레지스터
cbuffer TRANSFORM : register(b0)
{
    // 열 기준이기 때문에 행 기준으로 바꾸는 row_major 키워드 사용
    row_major Matrix g_matWorld;    // 물체의 위치, 크기, 회전 정보를 담은 행렬
    row_major Matrix g_matView;     // 카메라가 기준이 되는 좌표계로 이동시키는 행렬
    row_major Matrix g_matProj;     // View 공간에 있는 좌표를 2차원으로 투영
}

// HLSL 5.0 기준 문법
struct VS_IN
{
    float2 vUV : TEXCOORD; // Sementic
    float4 vColor : COLOR; // Sementic
    float3 vPos : POSITION; // Sementic
};

struct VS_OUT
{
    // System Value sement, 특수 시멘틱
    float4 vPosition : SV_Position;
    float2 vUV : TEXCOORD;
    float4 vColor : COLOR;
};


// 입력으로 들어온 모델정보를 처리하는 
// 위치를 원하는 위치로 배치시킨다(좌표계 변환)
// Object Space  --> World Space
// Model Space
// Local Space

VS_OUT VS_Std2D(VS_IN _in)
{
    VS_OUT output = (VS_OUT) 0.f;
    
    // Local -> World
    float4 vWorldPos = mul(float4(_in.vPos, 1.f), g_matWorld);
    // World -> View
    float4 vViewPos = mul(vWorldPos, g_matView);
    // View -> Projection (NDC 좌표계 변환)
    float4 vProjPos = mul(vViewPos, g_matProj);
    
    output.vPosition = vProjPos;
    output.vColor = _in.vColor;
    
    return output;
}

float4 PS_Std2D(VS_OUT _in) : SV_Target
{
    return _in.vColor;
}

// UTF-8 로 인코딩 되어야 인식 가능
// with BOM 이 붙은 인코딩으로 인식되어서 안되었던것
// UTF-8 Without signiture (서명없는 UTF-8)

#endif

