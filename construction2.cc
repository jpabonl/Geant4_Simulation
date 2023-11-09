#include "construction.hh"

// Construye el detector
DetectorConstruction::DetectorConstruction() {}

// Destruye el detector
DetectorConstruction::~DetectorConstruction() {}

// Se construye la geometría del detector
G4VPhysicalVolume *DetectorConstruction::Construct()
{
    // G4Nistmanager tiene toda la información de los materiales que se pueden utilizar
    G4NistManager *nist = G4NistManager::Instance();

    // Se especifican los materiales que se van a utilizar: Nitrogeno, vidrio, el fotodiodo y el centelleador
    G4Material *nitrogenMat = nist->FindOrBuildMaterial("G4_NITROGEN");
    G4Material *glassMat = nist->FindOrBuildMaterial("G4_SILICON_DIOXIDE");
    G4Material *photodiodeMat = nist->FindOrBuildMaterial("G4_Si");
    G4Material *plasticMat = nist->FindOrBuildMaterial("G4_POLYVINYL_CHLORIDE");
    G4Material *protectivelayerMat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");

    // Se crean las dimensiones de la figura
    G4double baseRadius = 10.0 * cm;
    G4double topRadius = 1.0 * cm;
    G4double height = 8.0 * cm;
    G4double startAngle = 0.0 * deg;
    G4double spanningAngle = 360.0 * deg;

    G4Tubs *solidGlassBase = new G4Tubs("solidGlassBase", 0.0, baseRadius, height, startAngle, spanningAngle);
    G4Sphere *solidHemisphere = new G4Sphere("solidHemisphere", 0.0, topRadius, startAngle, spanningAngle, 0.0, 180.0 * deg);

    // Union de las figuras
    G4UnionSolid *solidWineGlass = new G4UnionSolid("solidWineGlass", solidGlassBase, solidHemisphere, 0, G4ThreeVector(0.0, 0.0, height));

    // Se llena la figura con los materiañes
    G4LogicalVolume *logicGlass = new G4LogicalVolume(solidWineGlass, glassMat, "logicGlass");
    G4LogicalVolume *logicPhotodiode = new G4LogicalVolume(solidGlassBase, photodiodeMat, "logicPhotodiode");
    G4LogicalVolume *logicPlastic = new G4LogicalVolume(solidGlassBase, plasticMat, "logicPlastic");
    G4LogicalVolume *logicProtectiveLayer = new G4LogicalVolume(solidGlassBase, protectivelayerMat, "logicProtectiveLayer");

    // G4ThreeVector posiciona los vasos en el plano (para este caso el origen).
    G4ThreeVector glassPos(0., 0., 0.);
    G4ThreeVector photodiodePos(0., 0., 0.);
    G4ThreeVector plasticPos(0., 0., 0.);
    G4ThreeVector protectiveLayerPos(0., 0., 0.);

    // Se introduce la figura en el fotodiodo
    new G4PVPlacement(0, glassPos, logicGlass, "physGlass", logicPhotodiode, false, 0, true);

    // Se introducen la figura en el fotodiodo en el plástico
    new G4PVPlacement(0, photodiodePos, logicPhotodiode, "physPhotodiode", logicPlastic, false, 0, true);

    // Se introduce la figura en el  fotodiodo y plástico en la capa protectora
    new G4PVPlacement(0, plasticPos, logicPlastic, "physPlastic", logicProtectiveLayer, false, 0, true);

    // Se almacena toda la información en phosphor_model
    G4VPhysicalVolume *phosphor_model = new G4PVPlacement(0, protectiveLayerPos, logicProtectiveLayer, "physProtectiveLayer", 0, false, 0, true);

    // Retorna el puntero al volumen físico del detector
    return phosphor_model;
}
