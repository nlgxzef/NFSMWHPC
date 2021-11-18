#pragma once

DWORD* TutorialButtonObj;

void __declspec(naked) HideTutorialButtonCodeCave()
{
	_asm pushad;

	// Hide Tutorial button
	TutorialButtonObj = FEngFindObject("ChallengeSeries.fng", 0x12FD7D4A);
	FEngSetCenter(TutorialButtonObj, 9999, 9999);
	FEngSetInvisible(TutorialButtonObj);

	_asm popad;
	_asm retn;
}

float ShadowPopInThing = 0;

void __declspec(naked) ShadowPopInFixCodeCave()
{
	_asm
	{
		fmul dword ptr ds : [ShadowPopInThing]
		mov dword ptr ds : [ShadowPopInThing], 0x43B40000 // 360 float
		push 0x6C9659
		retn
	}
}

float ShadowFOVAspectRatio, ShadowFOVMult, ShadowFOVResult;

void __declspec(naked) ShadowFOVCodeCave1()
{
	_asm
	{
		cvtsi2ss xmm0, dword ptr ds : [0x982BE4]
		cvtsi2ss xmm1, dword ptr ds : [0x982BE8]
		divss xmm1, xmm0
		movss dword ptr ds: [ShadowFOVAspectRatio], xmm1
		fild dword ptr ds: [ebx + 0xC4] // loads FOV
		fdiv dword ptr ds: [ShadowFOVAspectRatio] // divides by aspect ratio
		fmul dword ptr ds : [ShadowFOVMult] // multiplies by 0.85
		fistp dword ptr ds : [ShadowFOVResult] // stores result
		mov eax, dword ptr ds : [ShadowFOVResult] // moves result
		mov dword ptr ds: [ShadowFOVMult], 0x3F59999A
		push 0x6E4668
		retn
	}
}

void __declspec(naked) ShadowFOVCodeCave2()
{
	_asm
	{
		cvtsi2ss xmm0, dword ptr ds : [0x982BE4]
		cvtsi2ss xmm1, dword ptr ds : [0x982BE8]
		divss xmm1, xmm0
		movss dword ptr ds : [ShadowFOVAspectRatio] , xmm1
		fild dword ptr ds : [ebx + 0xC4] // loads FOV
		fdiv dword ptr ds : [ShadowFOVAspectRatio] // divides by aspect ratio
		fmul dword ptr ds : [ShadowFOVMult] // multiplies by 0.85
		fistp dword ptr ds : [ShadowFOVResult] // stores result
		mov ecx, dword ptr ds : [ShadowFOVResult] // moves result
		mov dword ptr ds : [ShadowFOVMult] , 0x3F59999A
		push 0x6E46AC
		retn
	}
}

void __declspec(naked) ShadowFOVCodeCave3()
{
	_asm
	{
		cvtsi2ss xmm0, dword ptr ds : [0x982BE4]
		cvtsi2ss xmm1, dword ptr ds : [0x982BE8]
		divss xmm1, xmm0
		movss dword ptr ds : [ShadowFOVAspectRatio] , xmm1
		fild dword ptr ds : [ebx + 0xC4] // loads FOV
		fdiv dword ptr ds : [ShadowFOVAspectRatio] // divides by aspect ratio
		fmul dword ptr ds : [ShadowFOVMult] // multiplies by 0.85
		fistp dword ptr ds : [ShadowFOVResult] // stores result
		mov ecx, dword ptr ds : [ShadowFOVResult] // moves result
		mov dword ptr ds : [ShadowFOVMult] , 0x3F59999A
		push 0x6E47E4
		retn
	}
}

void __declspec(naked) ShadowFOVCodeCave4()
{
	_asm
	{
		cvtsi2ss xmm0, dword ptr ds : [0x982BE4]
		cvtsi2ss xmm1, dword ptr ds : [0x982BE8]
		divss xmm1, xmm0
		movss dword ptr ds : [ShadowFOVAspectRatio] , xmm1
		fild dword ptr ds : [ebx + 0xC4] // loads FOV
		fdiv dword ptr ds : [ShadowFOVAspectRatio] // divides by aspect ratio
		fmul dword ptr ds : [ShadowFOVMult] // multiplies by 0.85
		fistp dword ptr ds : [ShadowFOVResult] // stores result
		mov edx, dword ptr ds : [ShadowFOVResult] // moves result
		mov dword ptr ds : [ShadowFOVMult] , 0x3F59999A
		push 0x6E482C
		retn
	}
}