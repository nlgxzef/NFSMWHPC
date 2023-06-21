#include "InGameFunctions.h"
#include "CodeCaves.h"
#include "Helpers.h"
#include "UIMain.h"
#include "UIQRCarSelect.h"
#include "DOWorldLOD.h"
#include "Game.h"

void Init()
{
	// Remember, no Russian
	if (DoesFileExist("Languages\\Russian.bin") || DoesFileExist("..\\Languages\\Russian.bin"))
	{
		MessageBoxA(NULL, "ERROR: It seems that your game appears to be a russian release or/and contains related files to it. Please install an US English v1.3 version.", "NFSMW Hot Pursuit Challenges", MB_ICONERROR);
		*(int*)_ExitTheGameFlag = 1;
	}

	// Replace main menu to show HPC specific options
	injector::MakeCALL(0x54FD11, UIMain_Setup, true); // UIMain::UIMain
	injector::WriteMemory(0x89EAE4, &UIMain_Setup, true); // UIMain::vtable

	// Disable "Game Stats" in Main Menu
	injector::MakeJMP(0x55A01B, 0x55A25B, true); // UIMain::NotificationMessage
	//injector::MakeJMP(0x528D9C, 0x528E1A, true); // UIMain::UpdateProfileData

	// Disable tutorial in Challenge Series
	injector::MakeJMP(0x7AE869, 0x7AE893, true); // UIQRChallengeSeries::NotificationMessage
	injector::WriteMemory<DWORD>(0x7A42CF, 0xF7B54C7, true); // UIQRChallengeSeries::RefreshHeader
	injector::MakeJMP(0x7A4582, HideTutorialButtonCodeCave, true); // UIQRChallengeSeries::RefreshHeader

	// Remove Over Bright and Visual Treatment options - UIOptionsScreen::SetupVideo
	injector::MakeJMP(0x529B29, 0x529BC7, true);

	// Restrict World LOD Option to 2-3
	injector::WriteMemory(0x89BC3C, &DOWorldLOD_Act, true); // DOWorldLOD::vtable

	// Disable Interactive Music by default
	injector::WriteMemory<int>(0x56D61F, 0, true); // AudioSettings::Default

	// Can Spawn Roadblocks in Quick Race - AIPursuit::RequestRoadBlock
	injector::MakeNOP(0x419519, 6, true);

	// Cops Can Call Support in Quick Race - AIPursuit::RequestGroundSupport
	injector::WriteMemory<unsigned char>(0x4196FF, 0xEB, true);
	injector::MakeNOP(0x41974B, 2, true);

	// Helicopter - AIPursuit::CopRequest
	injector::MakeNOP(0x42BAD6, 6, true);

	// Fix Sunset Shadows (Aero_)
	injector::WriteMemory<int>(0x6e5174, 0, true); // sub_6E44C0, Full Shadow LOD
	injector::MakeNOP(0x6c8420, 2, true); // sub_6C83D0, Darker Shadows
	injector::MakeJMP(0x6C9653, ShadowPopInFixCodeCave, true); // sub_6C9570
	injector::MakeJMP(0x6E4661, ShadowFOVCodeCave1, true); // sub_6E44C0
	injector::MakeJMP(0x6E46A5, ShadowFOVCodeCave2, true); // sub_6E44C0
	injector::MakeJMP(0x6E47DD, ShadowFOVCodeCave3, true); // sub_6E44C0
	injector::MakeJMP(0x6E4825, ShadowFOVCodeCave4, true); // sub_6E44C0

	// fix TOD & possibly ChanceOfRain not working
	injector::MakeNOP(0x600AEA, 0x5, true);
	injector::MakeJMP(0x605610, Game_IsCareerMode, true);
	
	// Skip "Career" mode while switching between car categories
	injector::MakeJMP(0x7BF970, UIQRCarSelect_ScrollLists, true); // 4 references, may need hooking by calls in another script

	// Disable "Defaults" option
	//injector::MakeJMP(0x545BF0, 0x545C2E, true); // UIOptionsScreen::NotificationMessage (disable defaulting function)
	//injector::MakeRangedNOP(0x545C27, 0x545C2E, true);
	injector::MakeNOP(0x545A32, 6, true);  // UIOptionsScreen::NotificationMessage (disable dialog)
	//injector::MakeJMP(0x545A32, 0x545C2E, true);
	// jz 0x545C2E
	injector::WriteMemory<WORD>(0x545A32, 0x840F, true);
	injector::WriteMemory<DWORD>(0x545A34, 0x01F6, true);
	injector::WriteMemory<WORD>(0x54611C, 0x3774, true); // UIOptionsPCController::NotificationMessage (jz 0x546155)

	// Hide "Defaults" option
	injector::MakeJMP(0x5295E8, HideDefaultsCodeCave_AGP, true); // UIOptionsScreen::SetupAudio
	injector::MakeJMP(0x529C03, HideDefaultsCodeCave_Video, true); // UIOptionsScreen::SetupVideo
	injector::MakeJMP(0x529F04, HideDefaultsCodeCave_AGP, true); // UIOptionsScreen::SetupGameplay
	injector::MakeJMP(0x52A284, HideDefaultsCodeCave_AGP, true); // UIOptionsScreen::SetupPlayer
	injector::MakeJMP(0x52AB89, HideDefaultsCodeCave_Controller, true); // UIOptionsPCController::Setup

	// Hide Quick Play mode from Quick Race Menu
	injector::MakeNOP(0x7AA753, 2, true); // UIQRMainMenu::Setup
	
	// ULv4 Car Skin Fix (Requires CarSkinCount (20) x dummy skin and wheel textures in CARS\TEXTURES.BIN)
	// VehicleRenderConn::Load
	injector::MakeNOP(0x75D29E, 2, true); // Skip precomposite skins
	injector::MakeRangedNOP(0x75D2BB, 0x75D2D6, true);
	injector::WriteMemory<unsigned char>(0x75D2B6, 20, true); // 4 -> 20
	// RideInfo::SetCompositeNameHash
	injector::MakeRangedNOP(0x747F2B, 0x747F3B, true); // Skip precomposite skins
	injector::MakeJMP(0x747F2B, 0x747F3B, true);
	injector::WriteMemory<unsigned char>(0x747F22, 20, true); // 4 -> 20
	
	// Always add both ride height values, not just when it's close enough (from chassis and ecar) (ty rx)
	injector::MakeRangedNOP(0x7470AC, 0x7470B2, true); // CarRenderConn::UpdateRenderMatrix
	
}