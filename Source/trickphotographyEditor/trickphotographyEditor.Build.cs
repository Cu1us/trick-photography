using UnrealBuildTool;

public class trickphotographyEditor : ModuleRules
{
    public trickphotographyEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "trickphotography", "Slate", "SlateCore" });
    }
}