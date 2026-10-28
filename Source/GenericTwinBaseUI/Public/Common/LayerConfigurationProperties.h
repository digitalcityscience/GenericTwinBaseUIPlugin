/**

The MIT License (MIT)

Copyright (c) 2023 - present, Maoiok Ernst


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

#pragma once

#include "UObject/Object.h"

#include "LayerConfigurationProperties.generated.h"

UENUM(BlueprintType)
enum class EGenericTwinConfigPropertyType : uint8
{	
	UNDEFINED		UMETA(DisplayName = "Undefined"),
	BOOL			UMETA(DisplayName = "Bool"),
	STRING			UMETA(DisplayName = "String"),
	STRING_ARRAY	UMETA(DisplayName = "StringArray"),
	INT				UMETA(DisplayName = "Integer"),
	INT_ARRAY		UMETA(DisplayName = "IntegerArray"),
	NUMBER			UMETA(DisplayName = "Number"),
	NUMBER_ARRAY	UMETA(DisplayName = "NumberArray"),
	VECTOR2			UMETA(DisplayName = "Vector2"),
	VECTOR3			UMETA(DisplayName = "Vector3"),
	VECTOR4			UMETA(DisplayName = "Vector4"),
	COLOR			UMETA(DisplayName = "Color"),

};

UCLASS(BlueprintType, Blueprintable, Abstract)	// 	abstract
class GENERICTWINBASEUI_API ULayerConfigurationPropertyBase :   public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadonly, Category = Default)
	EGenericTwinConfigPropertyType	PropertyType;

	UPROPERTY(BlueprintReadonly, Category = Default)
	bool	AsSlider = false;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationBoolProperty :   public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = Default)
	bool		Value = 0;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationIntProperty :   public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationIntProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::INT;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	int32		Value = 0;

	UPROPERTY(BlueprintReadonly, Category = Default)
	int32		MinValue = TNumericLimits<int32>::Min();

	UPROPERTY(BlueprintReadonly, Category = Default)
	int32		MaxValue = TNumericLimits<int32>::Max();

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationNumberProperty :   public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationNumberProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::NUMBER;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	double		Value = 0.0;

	UPROPERTY(BlueprintReadonly, Category = Default)
	double		MinValue = TNumericLimits<int32>::Min();

	UPROPERTY(BlueprintReadonly, Category = Default)
	double		MaxValue = TNumericLimits<int32>::Max();

};

