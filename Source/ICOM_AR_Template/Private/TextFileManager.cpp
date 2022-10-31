// Fill out your copyright notice in the Description page of Project Settings. 

#include "TextFileManager.h" 
#include "Misc/FileHelper.h" 
#include "HAL/PlatformFilemanager.h" 


bool UTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> ArrayData, bool AllowOverWriting = false)
{
	// Set complete file path. 
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!AllowOverWriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			return false;
		}
	}

	FString FinalString = "";
	for (FString& Each : ArrayData)
	{
		FinalString += Each;
		FinalString += LINE_TERMINATOR;
	}

	return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);

}



FString UTextFileManager::FileLoadString(FString SaveDirectory, FString FileName)
{
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	FString LoadText;

	FFileHelper::LoadFileToString(LoadText, *SaveDirectory);
	return LoadText;
}