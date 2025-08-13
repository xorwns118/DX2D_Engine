#pragma once

#define SINGLE(Type) private:\
						Type();\
						Type(const Type& _origin) = delete;\
						virtual ~Type();\
						Type& operator = (const Type& _other) = delete;\
						friend class singleton<Type>;

typedef Vector2 Vec2;
typedef Vector3 Vec3;
typedef Vector4 Vec4;

#define DT TimeMgr::GetInst()->GetDeltaTime()

#define KEY_CHECK(Key, State) (KeyMgr::GetInst()->GetKeyState(Key) == State)
#define KEY_TAP(Key) KEY_CHECK(Key, KEY_STATE::TAP)
#define KEY_PRESSED(Key) KEY_CHECK(Key, KEY_STATE::PRESSED)
#define KEY_RELEASED(Key) KEY_CHECK(Key, KEY_STATE::RELEASED)

#define DEVICE Device::GetInst()->GetDevice().Get()
#define CONTEXT Device::GetInst()->GetContext().Get()

#define GET(Type, MemName) const Type Get##MemName() {return m_##MemName;}
#define SET(Type, MemName) void Set##MemName(Type _Data) {m_##MemName = _Data;}
#define GET_SET(Type, MemName) GET(Type, MemName); SET(Type, MemName)