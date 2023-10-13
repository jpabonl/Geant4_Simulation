#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"  // Incluye la clase base para la construcción del detector en Geant4.
#include "G4VPhysicalVolume.hh"  // Incluye la clase base para el volumen físico en Geant4.
#include "G4LogicalVolume.hh"  // Incluye la clase para el volumen lógico en Geant4.
#include "G4Box.hh"  // Incluye la clase para un sólido de tipo caja en Geant4.
#include "G4PVPlacement.hh"  // Incluye la clase para la colocación de un volumen físico en Geant4.
#include "G4NistManager.hh"  // Incluye el gestor de materiales del NIST en Geant4.
#include "G4SystemOfUnits.hh"  // Incluye las unidades del sistema internacional en Geant4.

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();  // Constructor del DetectorConstruction.
  ~DetectorConstruction();  // Destructor del DetectorConstruction.
  
  virtual G4VPhysicalVolume *Construct();  // Función para construir la geometría y definir el detector.
};

#endif
