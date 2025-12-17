/**

The MIT License (MIT)

Copyright (c) 2023 - present, Hamburg Port Authority


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the Ã¢â‚¬Å“SoftwareÃ¢â‚¬Â), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED Ã¢â‚¬Å“AS ISÃ¢â‚¬Â, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

**/

#pragma once

#include "CoreMinimal.h"
#include "GenericTwinPath.h"
#include "Blueprint/UserWidget.h"
#include "GenericTwinWaypointListWidget.generated.h"

USTRUCT(BlueprintType)
struct FGenericTwinWaypointData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = Default)
	float	SolarTime = -1.0;
};

USTRUCT(BlueprintType)
struct FPathCreatorWaypoint
{
	GENERATED_BODY()
		
	UPROPERTY(BlueprintReadWrite)
	EGenericTwinPathWaypointType Type = EGenericTwinPathWaypointType::Fly;

	UPROPERTY(BlueprintReadWrite)
	EGenericTwinPathWaypointMode	Mode = EGenericTwinPathWaypointMode::Default;
	
	UPROPERTY(BlueprintReadWrite)
	double							Longitude = 0.0;
	
	UPROPERTY(BlueprintReadWrite)
	double							Latitude = 0.0;
	
	UPROPERTY(BlueprintReadWrite)
	double							Altitude = 0.0;
	
	UPROPERTY(BlueprintReadWrite)
	FRotator						Rotation;
	
	UPROPERTY(BlueprintReadWrite)
	double							LookAtLongitude = 0.0;

	UPROPERTY(BlueprintReadWrite)
	double							LookAtLatitude = 0.0;
	
	UPROPERTY(BlueprintReadWrite)
	double							LookAtAltitude = 0.0;
		
	UPROPERTY(BlueprintReadWrite)
	float StopDuration = 0.0;
	
	UPROPERTY(BlueprintReadWrite)
	FGenericTwinWaypointData		Data;
};

UCLASS(BlueprintType)
class UPathCreatorWaypointItem : public UObject
{
	GENERATED_BODY()

public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDataChanged);

	UPathCreatorWaypointItem()
	{
	}
	
	UFUNCTION(BlueprintCallable, Category="GenericTwin|Tools|Waypoints")
	void MarkDirty();
	
	UFUNCTION(BlueprintCallable, Category="GenericTwin|Tools|Waypoints")
	// Calculate the locations in Engine from GPS locations
	void CalculateEngineLocations();
	
	UFUNCTION(BlueprintCallable, Category="GenericTwin|Tools|Waypoints")
	// Calculate the GPS locations from locations in Engine
	void CalculateGPSLocations();
	
	UPROPERTY(BlueprintReadWrite, Category="GenericTwin|Tools|Waypoints")
	FPathCreatorWaypoint Waypoint{};

	UPROPERTY(BlueprintAssignable, Category="GenericTwin|Tools|Waypoints")
	FDataChanged OnDataChanged;
	
	UPROPERTY(BlueprintReadWrite, Category="GenericTwin|Tools|Waypoints")
	// Location in Engine
	FVector Location;
	
	UPROPERTY(BlueprintReadWrite, Category="GenericTwin|Tools|Waypoints")
	// Location in Engine
	FVector LookAtLocation;
};

USTRUCT(BlueprintType)
struct FPathCreatorData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FPathCreatorWaypoint> Waypoints;
};

UCLASS()
class UGenericTwinWaypointListWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPathLoaded, bool, Success);

	UFUNCTION(BlueprintCallable, Category="GenericTwin|Tools|Waypoints")
	void SaveToFile(const FString &Filename);

	UFUNCTION(BlueprintCallable, Category="GenericTwin|Tools|Waypoints")
	void LoadFromFile(const FString &Filename);

	UPROPERTY(BlueprintAssignable, Category="GenericTwin|Tools|Waypoints")
	FPathLoaded		OnPathLoaded;

	UPROPERTY(BlueprintReadWrite)
	TArray <UPathCreatorWaypointItem*> WaypointItems;

private:

	FPathCreatorData PathCreatorData;
};
