#pragma once

void __fastcall UIQRCarSelect_ScrollLists(DWORD* UIQRCarSelect, void* EDX_Unused, int direction)
{
	DWORD* FEDatabase = *(DWORD**)_FEDatabase;

    DWORD v3; // edi
    unsigned int CurrentCarCategory; // esi 1 = Stock, 2 = Career, 4 = My Cars, 8 = Bonus, 16 = Preset, 32 = Debug

    if ((*((BYTE*)FEDatabase + 300) & 1) == 0 && (*((DWORD*)FEDatabase + 75) & 0x20) == 0)
    {
        v3 = UIQRCarSelect[107] & 0xFFFF0000;
        CurrentCarCategory = (unsigned __int16)UIQRCarSelect[107];

        if (direction == -1) // Down
        {
            switch (CurrentCarCategory)
            {
            case 1:
            default:
                CurrentCarCategory = 8;
                break;
            case 4:
                CurrentCarCategory = 1;
                break;
            case 8:
                CurrentCarCategory = 4;
                break;
            }
        }
        else // Up
        {
            switch (CurrentCarCategory)
            {
            case 1:
            default:
                CurrentCarCategory = 4;
                break;
            case 4:
                CurrentCarCategory = 8;
                break;
            case 8:
                CurrentCarCategory = 1;
                break;
            }
        }
    }

    UIQRCarSelect[107] = v3 | CurrentCarCategory;
    UIQRCarSelect_RefreshCarList(UIQRCarSelect);
    UIQRCarSelect_RefreshHeader(UIQRCarSelect);
}