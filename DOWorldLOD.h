#pragma once

#define dword_91CA20 *(DWORD*)0x91CA20

int __fastcall DOWorldLOD_Act(DWORD* DOWorldLOD, void* EDX_Unused, char const* Unk, unsigned int Message)
{
	int val = *(DWORD*)(*(DWORD*)dword_91CA20 + 68);

	if (Message == 0x9120409E && --val < 2) val = 2; // PAD_LEFT
	else if (Message == 0xB5971BF1 && ++val > 3) val = 3; // PAD_RIGHT

	*(DWORD*)(*(DWORD*)dword_91CA20 + 68) = val;

	DWORD DOWorldLOD_vtable = *(DWORD*)DOWorldLOD;
	*((BYTE*)DOWorldLOD + 42) = 1;
	(*(void(__thiscall**)(DWORD*, unsigned int))(DOWorldLOD_vtable + 56))(DOWorldLOD, Message); // FEToggleWidget::BlinkArrows
	return (*(int(__thiscall**)(DWORD*))(*(DWORD*)DOWorldLOD + 12))(DOWorldLOD); // DOWorldLOD::Draw
}