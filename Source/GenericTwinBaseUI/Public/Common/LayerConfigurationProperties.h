/**

The MIT License (MIT)

Copyright (c) 2023 - present, Maik Ernst


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
	STRING_OPTION	UMETA(DisplayName = "String Option"),
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

UCLASS(BlueprintType, Blueprintable, Abstract)
class GENERICTWINBASEUI_API ULayerConfigurationPropertyBase : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadonly, Category = Default)
	EGenericTwinConfigPropertyType  PropertyType;

	UPROPERTY(BlueprintReadonly, Category = Default)
	bool	AsSlider = false;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationBoolProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationBoolProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::BOOL;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	bool	Value = false;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationStringProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationStringProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::STRING;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	FString	Value;

	// Optional: could include option lists / dropdown constraints if needed
	UPROPERTY(BlueprintReadonly, Category = Default)
	TArray<FString>	ValidOptions;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationStringOptionProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationStringOptionProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::STRING_OPTION;
	}

	UPROPERTY(BlueprintReadonly, Category = Default)
	TArray<FString> Value;

	UPROPERTY(BlueprintReadWrite, Category = Default)
	int32 Index;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationStringArrayProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationStringArrayProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::STRING_ARRAY;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	TArray<FString> Value;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationIntProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationIntProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::INT;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	int32	Value = 0;

	UPROPERTY(BlueprintReadonly, Category = Default)
	int32	MinValue = TNumericLimits<int32>::Min();

	UPROPERTY(BlueprintReadonly, Category = Default)
	int32	MaxValue = TNumericLimits<int32>::Max();

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationIntArrayProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationIntArrayProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::INT_ARRAY;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	TArray<int32> Value;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationNumberProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationNumberProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::NUMBER;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	double	Value = 0.0;

	// Fixed the original limit casting type here to double limits
	UPROPERTY(BlueprintReadonly, Category = Default)
	double	MinValue = TNumericLimits<double>::Lowest();

	UPROPERTY(BlueprintReadonly, Category = Default)
	double	MaxValue = TNumericLimits<double>::Max();

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationNumberArrayProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationNumberArrayProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::NUMBER_ARRAY;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	TArray<double> Value;

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationVector2Property : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationVector2Property()
	{
		PropertyType = EGenericTwinConfigPropertyType::VECTOR2;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	FVector2D	Value = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadonly, Category = Default)
	FVector2D	MinValue = FVector2D(TNumericLimits<double>::Lowest());

	UPROPERTY(BlueprintReadonly, Category = Default)
	FVector2D	MaxValue = FVector2D(TNumericLimits<double>::Max());

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationVector3Property : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationVector3Property()
	{
		PropertyType = EGenericTwinConfigPropertyType::VECTOR3;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	FVector	Value = FVector::ZeroVector;

	UPROPERTY(BlueprintReadonly, Category = Default)
	FVector	MinValue = FVector(TNumericLimits<double>::Lowest());

	UPROPERTY(BlueprintReadonly, Category = Default)
	FVector	MaxValue = FVector(TNumericLimits<double>::Max());

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationVector4Property : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationVector4Property()
	{
		PropertyType = EGenericTwinConfigPropertyType::VECTOR4;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	FVector4	Value = FVector4(0, 0, 0, 0);

	UPROPERTY(BlueprintReadonly, Category = Default)
	FVector4	MinValue = FVector4(TNumericLimits<double>::Lowest(), TNumericLimits<double>::Lowest(), TNumericLimits<double>::Lowest(), TNumericLimits<double>::Lowest());

	UPROPERTY(BlueprintReadonly, Category = Default)
	FVector4	MaxValue = FVector4(TNumericLimits<double>::Max(), TNumericLimits<double>::Max(), TNumericLimits<double>::Max(), TNumericLimits<double>::Max());

};

UCLASS(BlueprintType, Blueprintable)
class GENERICTWINBASEUI_API ULayerConfigurationColorProperty : public ULayerConfigurationPropertyBase
{
	GENERATED_BODY()

public:

	ULayerConfigurationColorProperty()
	{
		PropertyType = EGenericTwinConfigPropertyType::COLOR;
	}

	UPROPERTY(BlueprintReadWrite, Category = Default)
	FLinearColor	Value = FLinearColor::White;

};