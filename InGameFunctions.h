#pragma once

#include "stdio.h"
#include <windows.h>
#include "GlobalVariables.h"

unsigned int(__thiscall* IconOption_Create)(void* MenuItemPtr, DWORD IconTextureHash, DWORD NameStringHash, DWORD unknown) = (unsigned int(__thiscall*)(void*, DWORD, DWORD, DWORD))0x586FA0;
unsigned int(__thiscall* IconScrollerMenu_AddOption)(void* TheThis, DWORD* IconOption) = (unsigned int(__thiscall*)(void*, DWORD*))0x573960;
DWORD* (*FEngGetLastButton)(char const* PackageName) = (DWORD * (*)(char const*))0x571E80;
void(__thiscall* UIMain_UpdateProfileData)(DWORD* UIMain) = (void(__thiscall*)(DWORD*))0x528BC0;

unsigned int(__thiscall* CustomizeCategoryScreen_AddCustomOption)(void* TheThis, const char* Package, unsigned int TextureHash, unsigned int LanguageHash, unsigned int BrandID) = (unsigned int(__thiscall*)(void*, const char*, unsigned int, unsigned int, unsigned int))0x7BB560;
char(*CustomizeIsInBackRoom)() = (char(*)())0x575B00;
int(*CarCustomizeManager_IsCareerMode)() = (int(*)())0x7A56C0;
bool(*CustomizeSetInParts)(bool IsInParts) = (bool(*)(bool))0x575B50;
void* (*j_malloc)(size_t) = (void* (*)(size_t))0x652AD0;
unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))0x460BF0;
unsigned int(*bStringHash2)(char* StringToHash, unsigned int HashToStart) = (unsigned int(*)(char*, unsigned int))0x460C20;
char* (*GetCarTypeName)(int CarTypeID) = (char* (*)(int))0x668370;
int(__thiscall* FECarRecord_GetType)(void* FECarRecord) = (int(__thiscall*)(void*))0x5816B0;
unsigned int(__thiscall* CarPart_GetAppliedAttributeIParam)(void* CarPart, unsigned int AttributeHash, int ValueIfNotFound) = (unsigned int(__thiscall*)(void*, unsigned int, int))0x747AC0;
unsigned int(__thiscall* CarPart_GetAppliedAttributeUParam)(void* CarPart, unsigned int AttributeHash, int ValueIfNotFound) = (unsigned int(__thiscall*)(void*, unsigned int, int))0x747AE0;
int(__thiscall* CustomizeSub_SetupPerformance)(void* CustomizeSub) = (int(__thiscall*)(void*))0x7BBFD0;
int(__thiscall* CustomizeSub_SetupDecalPositions)(void* CustomizeSub) = (int(__thiscall*)(void*))0x7BCBB0;
int(__thiscall* CustomizeSub_SetupRimBrands)(void* CustomizeSub) = (int(__thiscall*)(void*))0x7BC3C0;
int(__thiscall* CustomizeSub_SetupVinylGroups)(void* CustomizeSub) = (int(__thiscall*)(void*))0x7BC730;
int(__thiscall* CustomizeSub_SetupDecalLocations)(void* CustomizeSub) = (int(__thiscall*)(void*))0x7BCA60;
int(__thiscall* CustomizeSub_RefreshHeader)(void* CustomizeSub) = (int(__thiscall*)(void*))0x7B1070;
unsigned int(__thiscall* CarPartDatabase_NewGetCarPart)(DWORD* CarPartDB, int CarTypeID, int CarSlotID, int CarPartNameHash, int a5, int a6) = (unsigned int(__thiscall*)(DWORD*, int, int, int, int, int))0x747C40;
bool(__thiscall* RideInfo_UpdatePartsEnabled)(DWORD* RideInfo) = (bool(__thiscall*)(DWORD*))0x7517D0;
int(__thiscall* Attrib_Instance_dtInstance)(DWORD* Attrib) = (int(__thiscall*)(DWORD*))0x45A430;
int(__thiscall* RideInfo_SetStockParts)(void* RideInfo) = (int(__thiscall*)(void*))0x7594A0;
int(__thiscall* PursuitBoard_SetNumCopsDestroyed_Game)(DWORD* PursuitBoard, int NumberOfCopsDestroyed, unsigned int PVehicleHash, int ComboMultiplier, int BountyAward) = (int(__thiscall*)(DWORD*, int, unsigned int, int, int))0x595AF0;
unsigned int(*stringhash32)(char* StringToHash) = (unsigned int(*)(char*))0x5CC240;
char* (*GetLocalizedString)(unsigned int StringHash) = (char* (*)(unsigned int))0x56BC10;
DWORD* (__thiscall* LocalPlayer_GetHud)(DWORD* LocalPlayer) = (DWORD * (__thiscall*)(DWORD*))0x6F8F10;
int(*IGenericMessage_IHandle)() = (int(*)())0x5650B0;
DWORD* (__thiscall* UTL_COM_Object__IList_Find)(DWORD* LocalPlayer, void*) = (DWORD * (__thiscall*)(DWORD*, void*))0x5D59F0;
int(__thiscall* GenericMessage_RequestGenericMessage)(DWORD*, const char* MessageString, char Unkc, int Unk1, int IconTextureHash, int Type, int Priority) = (int(__thiscall*)(DWORD*, const char*, char, int, int, int, int))0x568030;
int(__cdecl* bSNPrintf)(char*, int, char const*, ...) = (int(__cdecl*)(char*, int, char const*, ...))0x4647E0;
int(*bRandom)(int Max) = (int(*)(int))0x45DA30;
bool(*DoesStringExist)(unsigned int StringHash) = (bool(*)(unsigned int))0x56BC00;
bool(*bFileExists)(char const *path) = (bool(*)(char const*))0x65F7A0;
int(__cdecl* bStrCmp)(char*, char*) = (int(__cdecl*)(char*, char*))0x460D20;
int(__thiscall* CarPartModelTable_GetModelNameHash)(DWORD* _this, int model_num, int a4, int LOD) = (int(__thiscall*)(DWORD*, int, int, int))0x7397D0;
int(__thiscall* CarPart_GetBrandName)(DWORD* CarPart) = (int(__thiscall*)(DWORD*))0x74D070;
int(__thiscall* CarPart_GetCarTypeNameHash)(DWORD* CarPart) = (int(__thiscall*)(DWORD*))0x739860;
DWORD* (*GetCarTypeInfoFromHash)(int CarTypeNameHash) = (DWORD * (*)(int))0x739940;
int(*UsedCarTextureAddToTable)(int* UsedCarTextureInfo, int NumTextures, int MaxTextures, int TextureHash) = (int(*)(int*, int, int, int))0x739E90;
int(__thiscall* CarPart_GetTextureNameHash)(DWORD* CarPart) = (int(__thiscall*)(DWORD*))0x74D0D0;
bool(__thiscall* EasterEggs_IsEasterEggUnlocked)(DWORD* EasterEggs, int EasterEggID) = (bool(__thiscall*)(DWORD*, int))0x6530A0;
int(__thiscall* CarCustomizeManager_GetStockCarPart)(DWORD* CarCustomizeManager, int CarSlotID) = (int(__thiscall*)(DWORD*, int))0x7A4B10;
int(__thiscall* CarCustomizeManager_IsPartInstalled)(DWORD* CarCustomizeManager, DWORD* SelectablePart) = (int(__thiscall*)(DWORD*, DWORD*))0x7A4DF0;
int(__thiscall* CarCustomizeManager_IsPartTypeInCart)(DWORD* CarCustomizeManager, DWORD* SelectablePart) = (int(__thiscall*)(DWORD*, DWORD*))0x7AEB90;
DWORD* (__thiscall* FEPlayerCarDB_GetCustomizationRecordByHandle)(DWORD* FEPlayerCarDB, BYTE FECarRecordID) = (DWORD * (__thiscall*)(DWORD*, BYTE))0x56F100;
DWORD* (__thiscall* FECustomizationRecord_GetInstalledPart)(DWORD* FECustomizationRecord, int FECarType, int CarSlotID) = (DWORD * (__thiscall*)(DWORD*, int, int))0x56F250;
int(__thiscall* IconScrollerMenu_SetInitialOption)(DWORD* IconScrollerMenu, int Option) = (int(__thiscall*)(DWORD*, int))0x50E7F0;
unsigned int(__thiscall* cFEng_QueuePackageMessage)(void* TheThis, unsigned int Message, const char* Package, unsigned int FEObject) = (unsigned int(__thiscall*)(void*, unsigned int, const char*, unsigned int))0x516C90;
bool(__thiscall* FEPackage_Startup)(DWORD* FEPackage, DWORD* FEGameInterface) = (bool(__thiscall*)(DWORD*, DWORD*))0x5BC4D0;
DWORD* (__thiscall* FEPackage_FindObjectByHash)(DWORD* FEPackage, unsigned int ObjectHash) = (DWORD * (__thiscall*)(DWORD*, unsigned int))0x5B8550;
DWORD* (__thiscall* FEObject_Clone)(DWORD* FEObject, bool) = (DWORD * (__thiscall*)(DWORD*, bool))0x5C3470;
DWORD* (__thiscall* FEGroup_Clone)(DWORD* FEGroup, bool) = (DWORD * (__thiscall*)(DWORD*, bool))0x5C49C0;
void(__thiscall* FEMinList_AddNode)(DWORD* FEMinList, DWORD* FEMinNode, DWORD* FEObject) = (void(__thiscall*)(DWORD*, DWORD*, DWORD*))0x5B2160;
int(__cdecl* FEPrintf)(const char* pkg_name, unsigned int obj_hash, const char* format, ...) = (int(__cdecl*)(const char*, unsigned int, const char*, ...))0x5252D0;
DWORD* (__cdecl* FEngFindObject)(const char* pkg_name, unsigned int obj_hash) = (DWORD * (__cdecl*)(const char*, unsigned int))0x524850;
DWORD* (__cdecl* FEngSetInvisible)(DWORD* obj) = (DWORD * (__cdecl*)(DWORD*))0x514C70;
DWORD* (__cdecl* FEngGetCenter)(DWORD* obj, float* x, float* y) = (DWORD * (__cdecl*)(DWORD*, float*, float*))0x524EE0;
DWORD* (__cdecl* FEngSetCenter)(DWORD* obj, float x, float y) = (DWORD * (__cdecl*)(DWORD*, float, float))0x525050;
void(__thiscall* CustomizationScreen_RefreshHeader)(DWORD* CustomizationScreen) = (void(__thiscall*)(DWORD*))0x7B1620;
int(__thiscall* bList_TraversebList)(DWORD* bList, DWORD* bNode) = (int(__thiscall*)(DWORD*, DWORD*))0x45D3A0;
void(__thiscall* CarCustomizeManager_PreviewPart)(DWORD* CarCustomizeManager, int unk, DWORD* CarPart) = (void(__thiscall*)(DWORD*, int, DWORD*))0x7AF110;
char* (__thiscall* CarPart_GetName)(DWORD* CarPart) = (char* (__thiscall*)(DWORD*))0x739850;
void(__cdecl* FEngSetLanguageHash)(const char* pkg_name, unsigned int obj_hash, unsigned int LanguageHash) = (void(__cdecl*)(const char*, unsigned int, unsigned int))0x525220;
void(__thiscall* FEPackage_BuildMouseObjectStateList)(DWORD*) = (void(__thiscall*)(DWORD*))0x5B88F0;
void(__thiscall* FEPackage_ConnectObjectResources)(DWORD*) = (void(__thiscall*)(DWORD*))0x5B87E0;
int(*GetMikeMannBuild)() = (int(*)())0x56E2B0;
void(__thiscall* UIQRCarSelect_RefreshCarList)(DWORD*) = (void(__thiscall*)(DWORD*))0x7BF7B0;
void(__thiscall* UIQRCarSelect_RefreshHeader)(DWORD*) = (void(__thiscall*)(DWORD*))0x7ADA50;