#include "physics.hh"

PhysicList::PhysicList()
{
    RegisterPhysics (new G4EmStandardPhysics());
    RegisterPhysics (new G4OpticalPhysics());
}

PhysicList::~PhysicList()
{}