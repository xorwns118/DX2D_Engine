#include "pch.h"
#include "TimeMgr.h"


TimeMgr::TimeMgr()
	: m_Frequency{}
	, m_CurCount{}
	, m_PrevCount{}
	, m_FrameCount(0)
	, m_String{}
	, m_DeltaTime(0.f)
	, m_AccTime(0.f)
{
	// 초당 카운팅 횟수
	QueryPerformanceFrequency(&m_Frequency);

	// 현재 카운팅
	QueryPerformanceCounter(&m_PrevCount);
}

TimeMgr::~TimeMgr()
{
}

void TimeMgr::Tick()
{
	++m_FrameCount;

	// WindowOS 가 프로세스가 실행된 시점부터 1초에 1000씩 카운팅
	// 현재 카운팅값 가져오기
	// GetTickCount()
	
	// 전원이 켜진 시점부터 1초에 10000000 씩 카운팅
	// 현재 카운팅 값 가져오기
	QueryPerformanceCounter(&m_CurCount);
	
	m_DeltaTime = (float)(m_CurCount.QuadPart - m_PrevCount.QuadPart) / (float)m_Frequency.QuadPart;
			
	// DT 가 1/60 초 이상이면 강제로 1/60 으로 보정해준다.
	// DT 값이 커져서 이상동작이 발생하는 현상 방지(ex 벽 통과)
	if (m_DeltaTime > 1.f / 60.f)
		m_DeltaTime = 1.f / 60.f;

	m_PrevCount = m_CurCount;

	m_AccTime += m_DeltaTime;

	// 1초에 한번씩 조건 성립
	if (m_AccTime >= 1.f)
	{	
		swprintf_s(m_String, 256, L"FrameCount : %d, DeltaTime : %f", m_FrameCount, m_DeltaTime);
		m_FrameCount = 0;
		m_AccTime = 0.f;
	}
}

void TimeMgr::Render(HDC _dc)
{
	TextOut(_dc, 10, 10, m_String, (int)wcslen(m_String));
}