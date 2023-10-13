#include "construction.hh"  // Incluye el archivo de header "construction.hh".

DetectorConstruction::DetectorConstruction() {}  // Constructor predeterminado de la clase DetectorConstruction.

DetectorConstruction::~DetectorConstruction() {}  // Destructor de la clase DetectorConstruction.

G4VPhysicalVolume *DetectorConstruction::Construct()
{
  // Obtiene una instancia del gestor de materiales del NIST.
  G4NistManager *nist = G4NistManager::Instance();

  // Define y construye un material llamado utilizando el gestor de materiales.
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  // Crea una caja con dimensiones 0.5 metros en cada eje.
  G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);

  // Crea un volumen lógico utilizando el sólido y el material definido.
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

  // Crea un volumen físico y lo posiciona en la posición (0, 0, 0).
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logicWorld, "physWorld", 0, false, 0, true);

  // Devuelve el volumen fisico
  return physWorld;
}
