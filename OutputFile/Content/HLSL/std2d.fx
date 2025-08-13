#ifndef _STD2D
#define _STD2D

// 상수 레지스터
cbuffer TRANSFORM : register(b0)
{
    float4 g_ObjPos;
    float4 g_ObjScale;
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
        
    // 모델을 오브젝트 위치로 변경하는 순서
    // 크기 -> 이동    
    output.vPosition = float4((_in.vPos * g_ObjScale.xyz) + g_ObjPos.xyz, 1.f);
    
    return output;
}

float4 PS_Std2D(VS_OUT _in) : SV_Target
{
    return float4(0.f, 1.f, 0.f, 1.f);
}

// UTF-8 로 인코딩 되어야 인식 가능
// with BOM 이 붙은 인코딩으로 인식되어서 안되었던것
// UTF-8 Without signiture (서명없는 UTF-8)

#endif

