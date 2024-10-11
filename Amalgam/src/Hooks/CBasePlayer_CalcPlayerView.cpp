#include "../SDK/SDK.h"

MAKE_SIGNATURE(CBasePlayer_CalcPlayerView, "client.dll", "48 89 5C 24 ? 56 57 41 54 48 83 EC ? 48 8B D9", 0x0);

MAKE_HOOK(CBasePlayer_CalcPlayerView, S::CBasePlayer_CalcPlayerView(), void, __fastcall,
	void* rcx, Vector& eyeOrigin, QAngle& eyeAngles, float& fov)
{
	if (Vars::Visuals::Removals::ViewPunch.Value && rcx)
	{
		const auto pPlayer = static_cast<CBasePlayer*>(rcx);

		Vec3 vOldPunch = pPlayer->m_vecPunchAngle();
		pPlayer->m_vecPunchAngle() = {};
		CALL_ORIGINAL(rcx, eyeOrigin, eyeAngles, fov);
		pPlayer->m_vecPunchAngle() = vOldPunch;
		return;
	}

	CALL_ORIGINAL(rcx, eyeOrigin, eyeAngles, fov);
}