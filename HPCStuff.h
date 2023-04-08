#include "InGameFunctions.h"
#include "CodeCaves.h"
#include "Helpers.h"
#include "UIMain.h"
#include "DOWorldLOD.h"

bool Game_IsCareerMode()
{
	return 1;
}

void Init()
{
	// Remember, no Russian
	if (DoesFileExist("..\\Languages\\Russian.bin"))
	{
		MessageBoxA(NULL, "ERROR: It seems that your game appears to be a russian release or/and contains related files to it. Please install an US English v1.3 version.", "NFSMW Hot Pursuit Challenges", MB_ICONERROR);
		*(int*)_ExitTheGameFlag = 1;
	}

	// Reshade check
	bool ReShadeDLLExists = DoesFileExist("..\\d3d9.dll") || DoesFileExist("..\\scripts\\reshade.asi");
	bool ReShadeFXHExists = DoesFileExist("reshade-shaders\\Shaders\\ReShade.fxh") || DoesFileExist("..\\reshade-shaders\\Shaders\\ReShade.fxh");
	if (ReShadeDLLExists && ReShadeFXHExists)
	{
		// Todo: ReShade related stuff
		//MessageBoxA(NULL, "we have reshade.", "NFSMW Hot Pursuit Challenges", MB_ICONERROR);
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

	// Make game read "MINI_MAP_U2.BIN" file instead of "MINI_MAP_Unlock_2.BIN"
	/*injector::WriteMemory(0x8A0DF6, '2', true);
	injector::WriteMemory(0x8A0DF7, '\0', true);
	injector::WriteMemory(0x8A0DF8, 0, true);
	injector::WriteMemory(0x8A0DFC, 0, true);*/

	//Make game read "HPC_DIABLO_YELLOW" string in executable instead of "M3GTRCAREERSTART" and "E3_DEMO_BMW"
	char* HPCDiabloYellow = "HPC_DIABLO_YELLOW";
	injector::WriteMemory(0x551D76, HPCDiabloYellow, true); // uiRepSheetRivalBio::NotificationMessage
	injector::WriteMemory(0x58FF63, HPCDiabloYellow, true); // sub_58FF60

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

	// HUD is probably not working because it does not fetch car preset name from vlt when loading HUD
	// Insted it tries to find the car in FE and presumably fails

	// TODO
	// - Fix custom speedos getting ignored in Challenge Series
	// - Force game to actually follow event's ForceHeatLevel & MaxHeatLevel parameters (currently only does ForceHeatLevel) (issue only applies to non-pursuit events like circuit, sprint, etc)
	//
	// not sure about last two, but if possible...
	// - There will be a camera shake option (through .ini config). It's done through editing vlt attributes (if ON = see script "camera_enablenoise.nfsms"; if OFF = do nothing)
	// - There will be a smoke graphic setting (through .ini config). It's done through editing vlt attributes (if HIGH = see script "tire_smoke_high.nfsms"; if MEDIUM = "tire_smoke_medium.nfsms"; if LOW = do nothing)
}