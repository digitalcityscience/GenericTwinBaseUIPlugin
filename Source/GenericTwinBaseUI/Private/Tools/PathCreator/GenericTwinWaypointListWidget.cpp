/**

The MIT License (MIT)

Copyright (c) 2023 - present, Hamburg Port Authority


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

**/

#include "Tools/PathCreator/GenericTwinWaypointListWidget.h"

#include "GeoReferencingSystem.h"
#include "JsonObjectConverter.h"

void UPathCreatorWaypointItem::MarkDirty()
{
	OnDataChanged.Broadcast();
}

void UPathCreatorWaypointItem::CalculateEngineLocations()
{
	AGeoReferencingSystem* GeoReferencingSystem = AGeoReferencingSystem::GetGeoReferencingSystem(GetWorld());
	FGeographicCoordinates LocationCoordinates(Waypoint.Longitude, Waypoint.Latitude, Waypoint.Altitude);
	FGeographicCoordinates LookAtLocationCoordinates(Waypoint.LookAtLongitude, Waypoint.LookAtLatitude, Waypoint.LookAtAltitude);

	GeoReferencingSystem->GeographicToEngine(LocationCoordinates, Location);
	GeoReferencingSystem->GeographicToEngine(LookAtLocationCoordinates, LookAtLocation);
}

void UPathCreatorWaypointItem::CalculateGPSLocations()
{
	AGeoReferencingSystem* GeoReferencingSystem = AGeoReferencingSystem::GetGeoReferencingSystem(GetWorld());

	FGeographicCoordinates LocationCoordinates;
	FGeographicCoordinates LookAtLocationCoordinates;
	GeoReferencingSystem->EngineToGeographic(Location, LocationCoordinates );
	GeoReferencingSystem->EngineToGeographic(LookAtLocation, LookAtLocationCoordinates);
	Waypoint.Longitude = LocationCoordinates.Longitude;
	Waypoint.Latitude = LocationCoordinates.Latitude;
	Waypoint.Altitude = LocationCoordinates.Altitude;
	
	Waypoint.LookAtLongitude = LookAtLocationCoordinates.Longitude;
	Waypoint.LookAtLatitude = LookAtLocationCoordinates.Latitude;
	Waypoint.LookAtAltitude = LookAtLocationCoordinates.Altitude;
}

void UGenericTwinWaypointListWidget::SaveToFile(const FString &Filename)
{
	FString JsonString;

	PathCreatorData.Waypoints.Reset();

	for (UPathCreatorWaypointItem* WaypointItem: WaypointItems)
	{		
		WaypointItem->CalculateGPSLocations();
		PathCreatorData.Waypoints.Add(WaypointItem->Waypoint);
	}
	
	FJsonObjectConverter::UStructToJsonObjectString(PathCreatorData,JsonString);

	FFileHelper::SaveStringToFile(JsonString, *Filename);
}

void UGenericTwinWaypointListWidget::LoadFromFile(const FString &Filename)
{
	FString JsonString;
	
	if (!FFileHelper::LoadFileToString(JsonString, *Filename))
	{
		OnPathLoaded.Broadcast(false);
		return;
	}

	FPathCreatorData PathData;

	FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &PathData, 0, 0);

	auto Waypoints = PathData.Waypoints;

	if(Waypoints.Num() > 1)
	{
		WaypointItems.Reset();

		for(const FPathCreatorWaypoint &waypoint : Waypoints)
		{
			UPathCreatorWaypointItem* WaypointItem = NewObject<UPathCreatorWaypointItem>(this);
			WaypointItem->Waypoint = waypoint;
			WaypointItem->CalculateEngineLocations();

			WaypointItems.Add(WaypointItem);
		}
				
		OnPathLoaded.Broadcast(true);
	}
	else
	{
		OnPathLoaded.Broadcast(false);
	}
}


