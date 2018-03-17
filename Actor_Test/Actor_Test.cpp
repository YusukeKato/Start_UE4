// Copyright 2018 Yusuke Kato All Rights Reserved. 

#include "Actor_Test.h"


// Sets default values
AActor_Test::AActor_Test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AActor_Test::BeginPlay()
{
	Super::BeginPlay();
	point = 1.0f;
}

// Called every frame
void AActor_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	if (NewLocation.Y > 100.0f) {
		point = -1.0f;
	}
	else if (NewLocation.Y < -100.0f) {
		point = 1.0f;
	}
	NewLocation.Y += point;
	SetActorLocation(NewLocation);
}

