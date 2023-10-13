#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"  // Incluye la clase base para la construcci�n del detector en Geant4.
#include "G4VPhysicalVolume.hh"  // Incluye la clase base para el volumen f�sico en Geant4.
#include "G4LogicalVolume.hh"  // Incluye la clase para el volumen l�gico en Geant4.
#include "G4Box.hh"  // Incluye la clase para un s�lido de tipo caja en Geant4.
#include "G4PVPlacement.hh"  // Incluye la clase para la colocaci�n de un volumen f�sico en Geant4.
#include "G4NistManager.hh"  // Incluye el gestor de materiales del NIST en Geant4.
#include "G4SystemOfUnits.hh"  // Incluye las unidades del sistema internacional en Geant4.

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();  // Constructor del DetectorConstruction.
  ~DetectorConstruction();  // Destructor del DetectorConstruction.
  
  virtual G4VPhysicalVolume *Construct();  // Funci�n para construir la geometr�a y definir el detector.
};

#endif
