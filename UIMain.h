#pragma once

#define _Challenge_vtbl 0x89C1F4
#define _MainProfileManager_vtbl 0x89C21C
#define _MainOptions_vtbl 0x89C224

void __fastcall UIMain_Setup(DWORD* UIMain, void* EDX_Unused)
{
	DWORD* AMenuOption;
	char const* UIMainPackage = (const char*)UIMain[4];

	*((DWORD*)(*(DWORD*)_FEDatabase) + 75) = 0;

	// Challenge Series
	AMenuOption = (DWORD*)j_malloc(0x4C);
	if (AMenuOption)
	{
		IconOption_Create(AMenuOption, 0x9A962438, 0xCC8CB746, 0);
		*AMenuOption = _Challenge_vtbl;
		*((BYTE*)AMenuOption + 69) = 1;
	}
	else
	{
		AMenuOption = 0;
	}
	IconScrollerMenu_AddOption(UIMain, AMenuOption);

	// Alias Manager
	AMenuOption = (DWORD*)j_malloc(0x4C);
	if (AMenuOption)
	{
		IconOption_Create(AMenuOption, 0x6B303856, 0xBCB18F38, 0);
		*AMenuOption = _MainProfileManager_vtbl;
	}
	else
	{
		AMenuOption = 0;
	}
	IconScrollerMenu_AddOption(UIMain, AMenuOption);

	// Options
	AMenuOption = (DWORD*)j_malloc(0x4C);
	if (AMenuOption)
	{
		IconOption_Create(AMenuOption, 0x3058FE37, 0x19A8C0AF, 0);
		*AMenuOption = _MainOptions_vtbl;
	}
	else
	{
		AMenuOption = 0;
	}
	IconScrollerMenu_AddOption(UIMain, AMenuOption);

	FEngSetLanguageHash(UIMainPackage, 0xB71B576D, 0xB24AAE58);
	DWORD* LastButton = FEngGetLastButton(UIMainPackage);
	if (*((BYTE*)UIMain + 297))
	{
		*((BYTE*)UIMain + 284) = 0;
		*((BYTE*)UIMain + 281) = 1;
		*((BYTE*)UIMain + 282) = 0;
		UIMain[68] = 0;
	}
	(*(void(__thiscall**)(DWORD*, DWORD*))(UIMain[11] + 64))(UIMain + 11, LastButton); // IconScroller::SetInitialPos(int)
	(*(void(__thiscall**)(DWORD*))(*UIMain + 12))(UIMain); // IconScrollerMenu::RefreshHeader
	UIMain_UpdateProfileData(UIMain);

	// Hide Game Stats button
	// Console
	DWORD* GameStatsButtonObj = FEngFindObject(UIMainPackage, 0x8913E195);
	FEngSetCenter(GameStatsButtonObj, 9999, 9999);
	FEngSetInvisible(GameStatsButtonObj);
	// PC
	GameStatsButtonObj = FEngFindObject(UIMainPackage, 0xD6463100);
	FEngSetCenter(GameStatsButtonObj, 9999, 9999);
	FEngSetInvisible(GameStatsButtonObj);
}