#pragma once
struct Vertex
{
	Vec3	vPos;
	Vec4	vColor;
	Vec2	vUV;
};
typedef Vertex Vtx;

struct tTransform
{
	Vec4 ObjPos;
	Vec4 ObjScale;
};