#include "trickphotographyEditorModule.h"

IMPLEMENT_GAME_MODULE(FtrickphotographyEditorModule, trickphotographyEditor);

void FtrickphotographyEditorModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Module started!!!"));
}

void FtrickphotographyEditorModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Module shut down!!!"));
}